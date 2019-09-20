/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractClasses.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 14:20:44 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 14:34:19 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class ACharacter
{
public:
	virtual void	attack(const std::string& target) = 0;
	void			sayHello(const std::string& target);
};

class Warrior : public ACharacter
{
public:
	virtual void	attack(const std::string& target);
};

void	ACharacter::sayHello(const std::string& target)
{
	std::cout << "Hello " << target << " !" << std::endl;
}

void	Warrior::attack(const std::string& target)
{
	std::cout << "*attacks " << target << " with a sword" << std::endl;
}

class ICoffeeMaker
{
public:
	virtual void			fillWaterTank(char* src) = 0;
	virtual ICoffeeMaker*	makeCoffee(const std::string& type) =0;
};

int main()
{
	ACharacter* a = new Warrior();
	a->sayHello("students");
	a->attack("roger");
	return 0;
}
