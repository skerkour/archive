/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 17:50:42 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/18 18:26:10 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap
{
private:
	static std::string	_sc_challenges[6];

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& src);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap& rhs);

	unsigned int	armor_damage_reduction() const;
	unsigned int	energy_points() const;
	unsigned int	hit_points() const;
	unsigned int	level() const;
	unsigned int	max_energy_points() const;
	unsigned int	max_hit_points() const;
	unsigned int	melee_attack_damage() const;
	std::string		name() const;
	unsigned int	ranged_damage_attack() const;
	void			set_name(std::string name);

	void	beRepaired(unsigned int amount);
	bool	meleeAttack(const std::string& target);
	bool	rangedAttack(const std::string& target);
	void	takeDamage(unsigned int amount);
	bool	challengeNewcomer(const std::string& target);

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
};

#endif // SCAVTRAP_HPP
