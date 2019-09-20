#include <iostream>

#include "Parser.hpp"
#include "Interpreter.hpp"

int main() {

    auto parser = Parser{"++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++."};
    auto instructions = parser.instructions();

    auto interpreter = Interpreter{instructions};
    interpreter.run();
    return 0;
}
