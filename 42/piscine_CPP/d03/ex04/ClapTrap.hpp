/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 10:25:04 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 10:25:22 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& src);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& rhs);

	unsigned int	armor_damage_reduction() const;
	unsigned int	energy_points() const;
	unsigned int	hit_points() const;
	unsigned int	level() const;
	unsigned int	max_energy_points() const;
	unsigned int	max_hit_points() const;
	unsigned int	melee_attack_damage() const;
	std::string		name() const;
	unsigned int	ranged_damage_attack() const;
	void			set_name(std::string& name);

	void	beRepaired(unsigned int amount);
	bool	meleeAttack(const std::string& target);
	bool	rangedAttack(const std::string& target);
	void	takeDamage(unsigned int amount);

protected:
	unsigned int	_armor_damage_reduction,
					_energy_points,
					_hit_points,
					_level,
					_max_energy_points,
					_max_hit_points,
					_melee_attack_damage,
					_ranged_damage_attack;
	std::string		_name;
};

#endif // CLAPTRAP_HPP
