/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecPtr.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:36:52 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/26 16:36:55 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECPTR_HPP
# define DECPTR_HPP

class DecPtr
{
public:
	DecPtr();
	DecPtr(const DecPtr& src);
	~DecPtr();

	DecPtr& operator=(const DecPtr& rhs);

private:

};

#endif // DECPTR_HPP
