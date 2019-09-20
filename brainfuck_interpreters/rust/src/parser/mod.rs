#[derive(Clone, Copy, Eq, Debug)]
pub enum Token {
    MoveFwd,
    MoveBack,
    Incr,
    Decr,
    Print,
    Read,
    WhileStart,
    WhileEnd,
    Unknown{pos: usize},
    EOF
}

impl PartialEq for Token {
    fn eq(&self, rhs: &Token) -> bool {
        match (self, rhs) {
           (&Token::MoveFwd, &Token::MoveFwd) => return true,
           (&Token::MoveBack, &Token::MoveBack) => return true,
           (&Token::Incr, &Token::Incr) => return true,
           (&Token::Decr, &Token::Decr) => return true,
           (&Token::Print, &Token::Print) => return true,
           (&Token::Read, &Token::Read) => return true,
           (&Token::WhileStart, &Token::WhileStart) => return true,
           (&Token::WhileEnd, &Token::WhileEnd) => return true,
           (&Token::Unknown{pos: a}, &Token::Unknown{pos: b}) => return a == b,
           (&Token::EOF, &Token::EOF) => return true,
            _ => false
        }
    }
}

pub struct Parser {
    input: String,
    instructions: Vec<Token>
}

impl Parser {
    pub fn new(input: &str) -> Parser {
        return Parser{
            input: input.to_string(),
            instructions: Vec::new()
        };
    }

    #[allow(dead_code)]
    pub fn input(&self) -> &str {
        return &self.input;
    }

    // TODO: check for nWhileStart == nWhileEnd && the positions of the WhileEnd
    pub fn run(&mut self) -> Vec<Token> {
        let mut pos = 0;
        for c in self.input.chars() {
            match c {
                '>' => self.instructions.push(Token::MoveFwd),
                '<' => self.instructions.push(Token::MoveBack),
                '+' => self.instructions.push(Token::Incr),
                '-' => self.instructions.push(Token::Decr),
                '.' => self.instructions.push(Token::Print),
                ',' => self.instructions.push(Token::Read),
                '[' => self.instructions.push(Token::WhileStart),
                ']' => self.instructions.push(Token::WhileEnd),
                _ => self.instructions.push(Token::Unknown{pos: pos})
            }
            pos += 1;
        }
        self.instructions.push(Token::EOF);
        return self.instructions.clone();
    }
}

#[cfg(test)]
mod test;
