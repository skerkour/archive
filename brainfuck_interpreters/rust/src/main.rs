mod parser;
mod interpreter;

use parser::Parser;
use interpreter::Interpreter;

fn main() {
    let mut p = Parser::new("++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.");
    let instructions = p.run();
    let mut interpreter = Interpreter::new(instructions);
    interpreter.run()
}
