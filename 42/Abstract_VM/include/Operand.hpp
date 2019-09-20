/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 04:26:12 by skerkour          #+#    #+#             */
/*   Updated: 2016/04/28 11:50:52 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

#include <string>

#include "IOperand.hpp"

template<eOperandType T>
class Operand : public IOperand {

public:
    Operand();
    Operand(const Operand& src);
    ~Operand();

    Operand& operator=(const Operand& rhs);
    virtual const IOperand* operator+(const IOperand& rhs); // Sum
    virtual const IOperand* operator-(const IOperand& rhs); // Difference
    virtual const IOperand* operator*(const IOperand& rhs); // Product
    virtual const IOperand* operator/(const IOperand& rhs); // Quotient
    virtual const IOperand* operator%(const IOperand& rhs); // Modulo

    virtual int getPrecision(void); // Precision of the type of the instance
    virtual eOperandType getType(void); // Type of the instance
    virtual const std::string toString(void); // String representation of the instance

private:
    eOperandType _type;
    int _precision;
    double _value;
};

#endif // OPERAND_HPP
