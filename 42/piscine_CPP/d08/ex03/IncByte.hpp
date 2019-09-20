/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncByte.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:37:20 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/26 16:38:49 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCBYTE_HPP
# define INCBYTE_HPP

class IncByte
{
public:
	IncByte();
	IncByte(const IncByte& src);
	~IncByte();

	IncByte& operator=(const IncByte& rhs);

private:

};

#endif // INCBYTE_HPP
