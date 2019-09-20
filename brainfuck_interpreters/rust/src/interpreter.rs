use std::io;

use parser;

pub struct Interpreter {
    instructions: Vec<parser::Token>,
    data: [i8; 30000],
    ip: usize,
    dp: usize
}

impl Interpreter {
    pub fn new(instructions: Vec<parser::Token>) -> Interpreter {
        return Interpreter{
            instructions: instructions,
            data: [0; 30000],
            ip: 0,
            dp: 0
        };
    }

    pub fn run(&mut self) {
        loop {
            match self.instructions[self.ip] {
                parser::Token::MoveFwd => self.dp += 1,
                parser::Token::MoveBack => self.dp -= 1,
                parser::Token::Incr => self.data[self.dp] += 1,
                parser::Token::Decr => self.data[self.dp] -= 1,
                parser::Token::Print => print!("{}", self.data[self.dp] as u8 as char),
                parser::Token::Read => {
                    let mut input = String::new();
                    io::stdin().read_line(&mut input).unwrap();
                    match input.trim_right().parse::<i8>() {
                        Ok(i) => self.data[self.dp] = i,
                        Err(e) => panic!("Bad value: {}", e)
                    }
                },
                parser::Token::WhileStart => {
                    if self.data[self.dp] == 0 {
                        self.jump_forward()
                    }
                },
                parser::Token::WhileEnd => {
                    if self.data[self.dp] != 0 {
                        self.jump_backward()
                    }
                },
                parser::Token::EOF => return,
                _ => {},
            }
            self.ip += 1;
        }
    }

    fn jump_forward(&mut self) {
        let mut while_level = 0;

        loop {
            if self.instructions[self.ip] == parser::Token::WhileStart {
                while_level += 1;
            } else if self.instructions[self.ip] == parser::Token::WhileEnd {
                while_level -= 1;
                if while_level == 0 {
                    return;
                }
            }
            self.ip += 1;
        }
    }

    fn jump_backward(&mut self) {
        let mut while_level = 0;

        loop {
            if self.instructions[self.ip] == parser::Token::WhileEnd {
                while_level += 1;
            } else if self.instructions[self.ip] == parser::Token::WhileStart {
                while_level -= 1;
                if while_level == 0 {
                    return;
                }
            }
            self.ip -= 1;
        }
    }
}
