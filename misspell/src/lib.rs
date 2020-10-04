use std::collections::HashMap;
use std::fs::File;
use std::io::{BufRead, BufReader};
use std::path::Path;

pub const CORPUS: &str = include_str!("../assets/words.csv");

pub fn render(path: &Path, line_num: usize, word: &str, correction: &str) {
    println!(
        "{}:{}: {:?} -> {}",
        path.display(),
        line_num,
        word,
        correction
    );
}

pub fn tokenize<'l>(line: &'l str) -> impl Iterator<Item = String> + 'l {
    line.split_whitespace().map(|word| {
        // lowercase word then remove all non alphabetical characters
        // eg: `dictionary:` -> `dictionary`
        word.to_lowercase()
            .chars()
            .filter(|x| {
                match x {
                    'a'...'z' => true,
                    _ => false,
                }
            })
            .collect()
    })
}

pub fn process_line(line_num: usize, line: &str, min_token: u64, path: &Path, dico: &Corrections) {
    tokenize(line)
        .filter(|word: &String| word.len() >= min_token as usize)
        .for_each(|word: String| {
            // for each word in the line
            if let Some(correction) = dico.correct(&word) {
                render(path, line_num + 1, &word, correction);
            }
        });
}

/// check all lines of a file for misspelled words
pub fn process_file(path: &Path, dictionary: &Corrections, min_token: u64) {
    let file = File::open(path).expect(format!("opening file: {}", path.display()).as_str());
    BufReader::new(file)
        .lines()
        .filter_map(|line| line.ok())
        .enumerate()
        .for_each(|(line_num, line)| {
            process_line(line_num, line.as_str(), min_token, path, dictionary)
        });
}

pub struct Corrections<'s> {
    dict: HashMap<&'s str, &'s str>,
}

impl<'s> Corrections<'s> {
    /// transform a csv file in the form `misspelled_word,correction` to a HashMap for fast lookup
    pub fn new(csv_data: &'s str) -> Self {
        let mut ret = HashMap::new();
        csv_data.lines().for_each(|line| {
            let pair = line.split(',').collect::<Vec<_>>();
            let pair = (pair[0], pair[1]);
            ret.insert(pair.0, pair.1);
        });
        Corrections { dict: ret }
    }

    pub fn correct(&self, word: &str) -> Option<&str> {
        self.dict.get(word).cloned()
    }
}
