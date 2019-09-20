/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncPtr.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:37:44 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/26 16:38:49 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCPTR_HPP
# define INCPTR_HPP

class IncPtr
{
public:
	IncPtr();
	IncPtr(const IncPtr& src);
	~IncPtr();

	IncPtr& operator=(const IncPtr& rhs);

private:

};

#endif // INCPTR_HPP
