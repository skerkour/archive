/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InByte.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:37:07 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/26 16:38:49 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INBYTE_HPP
# define INBYTE_HPP

class InByte
{
public:
	InByte();
	InByte(const InByte& src);
	~InByte();

	InByte& operator=(const InByte& rhs);

private:

};

#endif // INBYTE_HPP
