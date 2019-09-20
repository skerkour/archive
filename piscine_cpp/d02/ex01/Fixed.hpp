/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 13:42:49 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/17 17:23:38 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& src);
	Fixed(const int n);
	Fixed(const float f);
	~Fixed();

	Fixed&	operator=(const Fixed& rhs);

	int		getRawBits() const;
	void	setRawBits(const int raw);
	float	toFloat() const;
	 int	toInt() const;

private:
	int					_raw_bits;

	static const int	_n_frac_bits;
};

std::ostream&	operator<<(std::ostream& o, const Fixed& rhs);

#endif // FIXED_HPP
