/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 23:14:51 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/23 23:14:52 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

class CentralBureaucracy
{
public:
	CentralBureaucracy();
	CentralBureaucracy(const CentralBureaucracy& src);
	~CentralBureaucracy();

	CentralBureaucracy& operator=(const CentralBureaucracy& rhs);

private:

};

#endif // CENTRALBUREAUCRACY_HPP
