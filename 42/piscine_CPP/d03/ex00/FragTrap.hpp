/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 09:53:34 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/18 12:33:02 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>

typedef struct	s_attack {
	std::string		name;
	unsigned int	damages;
}				t_attack;

class FragTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& src);
	~FragTrap();

	FragTrap& operator=(const FragTrap& rhs);

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
	bool	vaulthunter_dot_exe(const std::string& target);

private:
	unsigned int	_armor_damage_reduction,
					_energy_points,
					_hit_points,
					_level,
					_max_energy_points,
					_max_hit_points,
					_melee_attack_damage,
					_ranged_damage_attack;
	std::string		_name;
	
	static t_attack	_random_vh_attacks[6];

};

#endif // FRAGTRAP_HPP
