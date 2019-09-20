#define KEY_ESC 27
#include <unistd.h>
#include <iostream>
#include <ncurses.h>
#include <ncurses.h>


#include <ncurses.h>
#include <unistd.h>
 
int main(int argc, char *argv[]) {
  int parent_x, parent_y, new_x, new_y;
  int score_size = 3;
 
  initscr();
  noecho();
  curs_set(FALSE);
 
  // set up initial windows
  getmaxyx(stdscr, parent_y, parent_x);
 
  WINDOW *field = newwin(30, 135, 0, 0);
  WINDOW *score = newwin(score_size, parent_x, parent_y - score_size, 0);
 
	wborder(field, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(score, '|', '|', '-', '-', '+', '+', '+', '+');
	mvwprintw(field, 1, 1, "yooo");
	int k; 
  while(1) {
	  if ((k = getch())  == ERR) {
		  ;
	  }
	  /*
    getmaxyx(stdscr, new_y, new_x);
 
    if (new_y != parent_y || new_x != parent_x) {
      parent_x = new_x;
      parent_y = new_y;
 
      wresize(field, new_y - score_size, new_x);
      wresize(score, score_size, new_x);
      mvwin(score, new_y - score_size, 0);
 
      wclear(stdscr);
      wclear(field);
      wclear(score);
 
	wborder(field, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(score, '|', '|', '-', '-', '+', '+', '+', '+');
    }
 
    // draw to our windows
    mvwprintw(field, 1, 1, "Field");
    mvwprintw(score, 1, 1, "Score");
 
    // refresh each window
    wrefresh(field);
    wrefresh(score);*/
	mvwprintw(field, 1, 1, "yooo");
    wrefresh(field);
  }
 
  endwin();
 
  return 0;
}
 
/*
int    main(void)
{
    int i = 0;
    int x = 0;
    int y = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    cbreak();
    curs_set(false);
    while (1)
    {
        if ((i = getch())  == ERR)
            ; 
        else
        {
            // std::cout << i << std::endl;
            if (i == KEY_ESC)
                break ;
            else if (i == KEY_DOWN)
            {
                // std::cout << "y++"<< std::endl;
                x++;
            }
            else if (i == KEY_UP)
            {
                // std::cout << "y--"<< std::endl;
                x--;
            }
            else if (i == KEY_RIGHT)
                y++;
            else if (i== KEY_LEFT)
                y--;
        //        usleep(30000);
            else if (i == 32) 
            {
                int ty = 0;
                while (ty < 50) 
                {
                    clear();
                    mvprintw(x, y, "8======D");                    
                    mvprintw(x, y + 8 + ty, "o");
                    ty++;
                    usleep(5000);
                    wrefresh(stdscr);
                }
            }
            //std::cout << i << std::endl;
            wrefresh(stdscr);
            clear();
            mvprintw(x, y, "8======D");
        }
    }
    endwin();
*/
