/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 04:53:40 by skerkour          #+#    #+#             */
/*   Updated: 2016/04/28 14:22:49 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>

#include "Operand.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include "VM.hpp"

void run(const std::string& input) {
    Lexer lxr{input};
    auto tokens = lxr.run();

    Parser parser{tokens};

    //srd::vector<Instruction> instructions;

    try {
        parser.validateInput();
        //instructions = parser.run();
    } catch (std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
        exit(-42);
    }
    /*
    VM vm{instructions};
    try {
        vm.run();
    } catch (std::exception& e) {

    }
    */
}

int main(int ac, char **av) {

    std::string input{};

    if (ac == 2) {
        input = std::string(av[1]);
        // read from the file
    } else {
        std::string total;

        while (input != ";;") {
            std::getline(std::cin, input);
            total += input + '\n';
        }

        input = total;
    }

    run(input);

    return 0;
}
