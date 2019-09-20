/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:38:10 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/26 17:04:02 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_HPP
# define INTERPRETER_HPP

class Interpreter
{
public:
	Interpreter();
	Interpreter(const Interpreter& src);
	~Interpreter();

	Interpreter& operator=(const Interpreter& rhs);

	void	execute();
	void	readFile(std::string& filename);

private:

};

#endif // INTERPRETER_HPP
