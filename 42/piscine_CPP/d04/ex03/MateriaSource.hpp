/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:23:21 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/20 23:37:07 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource :public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& src);
	~MateriaSource();

	MateriaSource& operator=(const MateriaSource& rhs);

	virtual void		learnMateria(AMateria* m);
	virtual AMateria*	createMateria(const std::string& type);
private:
	AMateria*	_inventory[4];
	int			_n_index;
};

#endif // MATERIASOURCE_HPP
