package music

import (
	"errors"
	"fmt"
	"os"
	"path/filepath"
	"time"
	"unicode"

	"github.com/faiface/beep"
	"github.com/faiface/beep/effects"
	"github.com/faiface/beep/flac"
	"github.com/faiface/beep/mp3"
	"github.com/faiface/beep/speaker"
	"github.com/faiface/beep/vorbis"
	"github.com/faiface/beep/wav"
	"github.com/gdamore/tcell"
	"github.com/rivo/tview"
)

var validFileExtension = map[string]bool{
	".mp3":  true,
	".wav":  true,
	".flac": true,
	".ogg":  true,
}

var (
	MainCtrl *beep.Ctrl
	Volume   *effects.Volume

	Format       beep.Format
	Paused       bool
	PlayingIndex int
	PlayingFiles []string
	UIList       *tview.List
	UIApp        *tview.Application
)

func init() {
	Volume = &effects.Volume{Base: 2}
}

// Run the music sub-command
func Run(args []string) (err error) {

	if len(args) < 1 {
		fmt.Println("Usage:")
		fmt.Println("music file|folder...")
		os.Exit(1)
	}

	PlayingFiles, err = listFiles(args)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	playQueue := make(chan string)

	go player(playQueue)

	UIApp = tview.NewApplication()
	UIList = tview.NewList()
	for _, file := range PlayingFiles {
		UIList.AddItem(filepath.Base(file), "", '\x00', nil)
	}
	UIList.ShowSecondaryText(false)
	UIList.SetInputCapture(func(event *tcell.EventKey) *tcell.EventKey {
		key := event.Key()
		if key == tcell.KeyEscape {
			UIApp.Stop()
			return nil
		} else if key == tcell.KeyEnter {
			PlayingIndex = UIList.GetCurrentItem()
			playQueue <- PlayingFiles[PlayingIndex]
			return nil
		} else if key == tcell.KeyRune {
			switch unicode.ToLower(event.Rune()) {
			case ' ':
				Paused = !Paused
				speaker.Lock()
				MainCtrl.Paused = Paused
				speaker.Unlock()
				return nil
			case 'q':
				UIApp.Stop()
				return nil
			}
		}
		return event
	})

	if len(PlayingFiles) == 0 {
		fmt.Println("No music files found")
		return
	}

	playQueue <- PlayingFiles[0]

	err = UIApp.SetRoot(UIList, true).EnableMouse(true).Run()

	return
}

func player(queue chan string) {
	var currentFile *os.File
	var err error
	var streamer beep.StreamSeekCloser

	for {
		select {
		case song := <-queue:
			if MainCtrl != nil {
				speaker.Lock()
				MainCtrl.Paused = true
				speaker.Unlock()
			}
			if streamer != nil {
				speaker.Lock()
				streamer.Close()
				speaker.Unlock()
			}
			if currentFile != nil {
				speaker.Lock()
				currentFile.Close()
				speaker.Unlock()
			}

			currentFile, err = os.Open(song)
			if err != nil {
				panic(err)
			}
			switch filepath.Ext(song) {
			case ".mp3":
				streamer, Format, err = mp3.Decode(currentFile)
			case ".wav":
				streamer, Format, err = wav.Decode(currentFile)
			case ".ogg":
				streamer, Format, err = vorbis.Decode(currentFile)
			case ".flac":
				streamer, Format, err = flac.Decode(currentFile)
			}
			if err != nil {
				panic(err)
			}

			sampleRate := Format.SampleRate * 2
			speaker.Init(sampleRate, sampleRate.N(time.Second/10))
			Volume.Streamer = beep.Resample(4, Format.SampleRate, sampleRate, streamer)
			MainCtrl = &beep.Ctrl{Streamer: Volume}
			speaker.Play(beep.Seq(MainCtrl, beep.Callback(func() {
				if UIList != nil && MainCtrl != nil {
					if PlayingIndex == len(PlayingFiles)-1 {
						PlayingIndex = 0
					} else {
						PlayingIndex += 1
					}
					queue <- PlayingFiles[PlayingIndex]
					UIList.SetCurrentItem(PlayingIndex)
					UIApp.Draw()
				}
			})))

			// speaker.Init(Format.SampleRate, Format.SampleRate.N(time.Second/10))
			// speaker.Play(Streamer)
		}
	}
}

func listFiles(paths []string) (ret []string, err error) {
	for _, path := range paths {
		var isDir bool

		isDir, err = IsDirectory(path)
		if err != nil {
			return
		}

		if isDir {
			var files []string

			files, err = walkDirectory(path)
			if err != nil {
				return
			}
			ret = append(ret, files...)
		} else {
			err = checkFile(path)
			if err != nil {
				return
			}
			ret = append(ret, path)
		}
	}

	return
}

func IsDirectory(path string) (bool, error) {
	fileInfo, err := os.Stat(path)
	if err != nil {
		return false, err
	}
	return fileInfo.IsDir(), err
}

func walkDirectory(path string) (ret []string, err error) {
	err = filepath.Walk(path, func(path string, info os.FileInfo, err error) error {
		if err != nil {
			return err
		}

		err = checkFile(path)
		if err == nil {
			ret = append(ret, path)
		}

		return nil
	})
	return
}

func checkFile(path string) (err error) {
	var fileExt string

	fileExt = filepath.Ext(path)
	if _, ok := validFileExtension[fileExt]; !ok {
		err = errors.New("Invalid file extension")
		return
	}

	_, err = os.Stat(path)
	if err != nil {
		return
	}

	return
}
