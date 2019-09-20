/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 09:24:17 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/20 11:16:15 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "ISpaceMarine.hpp"
#include "Squad.hpp"

Squad::Squad() : _n_units(0), _squad(NULL)
{
}

Squad::Squad(const Squad& src)
{
	_copyUnits(src);
	_n_units = src._n_units;
}

Squad::~Squad()
{
	_destroyUnits();
}

Squad& Squad::operator=(const Squad& rhs)
{
	if (this != &rhs) {
		_destroyUnits();
		_copyUnits(rhs);
		_n_units = rhs._n_units;
	}
	return *this;
}

int	Squad::getCount() const
{
	return _n_units;
}

ISpaceMarine*	Squad::getUnit(int n) const
{
	t_container	*tmp = _squad;

	if (n < 0 || n >= _n_units) {
		return NULL;
	} else {
		while (n--)
			tmp = tmp->next;
		return tmp->unit;
	}
}

int		Squad::push(ISpaceMarine* marine)
{
	t_container*	tmp = _squad;

	if (marine && !_unitAlreadyIn(marine, _squad)) {
		if (!_squad) {
			_squad = new t_container;
			_squad->unit = marine;
			_squad->next = NULL;
		} else {
			while (tmp->next) {
				tmp = tmp->next;
			}
			tmp->next = new t_container;
			tmp->next->unit = marine;
			tmp->next->next = NULL;
		}
		_n_units++;
	}
	return _n_units;
}

void	Squad::_copyUnits(const Squad& src)
{
	int	i = 0;
	int	n = src.getCount();

	while (i < n) {
		push(src.getUnit(i));
		++i;
	}
}

void	Squad::_destroyUnits()
{
	t_container*	tmp;

	if (!_squad) {
		return ;
	} else {
		delete _squad->unit;
		tmp = _squad;
		_squad = _squad->next;
		delete tmp;
		return _destroyUnits();
	}
}

bool	Squad::_unitAlreadyIn(ISpaceMarine* marine, t_container* squad)
{
	if (!squad) {
		return false;
	} else if (marine == squad->unit) {
		return true;
	} else {
		return _unitAlreadyIn(marine, squad->next);
	}
}
