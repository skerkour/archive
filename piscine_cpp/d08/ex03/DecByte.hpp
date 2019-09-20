/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecByte.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:36:41 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/26 16:36:55 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECBYTE_HPP
# define DECBYTE_HPP

class DecByte
{
public:
	DecByte();
	DecByte(const DecByte& src);
	~DecByte();

	DecByte& operator=(const DecByte& rhs);

private:

};

#endif // DECBYTE_HPP
