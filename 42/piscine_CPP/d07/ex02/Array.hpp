/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 21:20:00 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/25 11:44:34 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array
{
/*
public:
	class IndexOutOfBoundsException : public std::exception
	{
	public:
		IndexOutOfBoundsException();
		IndexOutOfBoundsException(const IndexOutOfBoundsException& src);
		virtual ~IndexOutOfBoundsException() throw();

		IndexOutOfBoundsException& operator=(const IndexOutOfBoundsException& rhs);

		virtual const char*	what() const throw();
	};
*/
public:
	Array() : _array(NULL), _size(0)
	{
	}
	Array(unsigned int n) : _array(new T[n]), _size(n)
	{
		for (unsigned int i = 0; i < n; ++i) {
			_array[i] = T();
		}
	}
	Array(const Array& src)
	{
		*this = src;
	}
	~Array()
	{
		if (_array)
			delete[] _array;
	}

	Array&	operator=(const Array& rhs)
	{
		unsigned int	i = 0,
						len = rhs.size();

		if (this != &rhs) {
			_size = len;
			if (len) {
				_array = new T[len];
				while (i < len) {
					_array[i] = rhs[i];
					++i;
				}
			} else {
				_array = NULL;
			}
		}
		return *this;
	}
	T		operator[](int i) const
	{
		if (i < 0 || static_cast<unsigned int>(i) >= _size || !_array)
			throw std::exception();
		return _array[i];
	}
	T&		operator [](int i)
	{
		if (i < 0 || static_cast<unsigned int>(i) >= _size || !_array)
			throw std::exception();
		return _array[i];
	}

	unsigned int	size() const
	{
		return _size;
	}

private:
	T*				_array;
	unsigned int	_size;
};

#endif // ARRAY_HPP
