/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OutByte.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:39:12 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/26 16:39:22 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTBYTE_HPP
# define OUTBYTE_HPP

class OutByte
{
public:
	OutByte();
	OutByte(const OutByte& src);
	~OutByte();

	OutByte& operator=(const OutByte& rhs);

private:

};

#endif // OUTBYTE_HPP
