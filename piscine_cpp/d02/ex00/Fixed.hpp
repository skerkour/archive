/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 13:42:49 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/17 15:31:38 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& src);
	Fixed(int n);
	~Fixed();

	Fixed&	operator=(const Fixed& rhs);

	int		getRawBits() const;
	void	setRawBits(const int raw);

private:
	int					_raw_bits;

	static const int	_n_frac_bits;
};

#endif // FIXED_HPP
