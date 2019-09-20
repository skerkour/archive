/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:37:58 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/26 16:38:49 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

class Instruction
{
public:
	Instruction();
	Instruction(const Instruction& src);
	~Instruction();

	Instruction& operator=(const Instruction& rhs);

private:

};

#endif // INSTRUCTION_HPP
