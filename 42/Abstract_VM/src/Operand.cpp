/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 04:53:35 by skerkour          #+#    #+#             */
/*   Updated: 2016/04/28 11:50:37 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Operand.hpp"

template <eOperandType T>
Operand<T>::Operand() {

}

template <eOperandType T>
Operand<T>::Operand(const Operand& src) {
	(void)src;
}

template <eOperandType T>
Operand<T>::~Operand() {
}

template <eOperandType T>
int Operand<T>::getPrecision(void) {
    return _precision;
}

template <eOperandType T>
eOperandType Operand<T>::getType(void) {
    return _type;
}

template <eOperandType T>
const std::string Operand<T>::toString(void) {
    /*static const std::string strs[] = {
        "Int8",
        "Int16",
        "Int32",
        "Float",
        "Double"
    };
    */
    if (_type == Int8 || _type == Int16 || _type == Int32) {
        return std::to_string(int(_value));
    } else {
        return std::to_string(_value);
    }
}
