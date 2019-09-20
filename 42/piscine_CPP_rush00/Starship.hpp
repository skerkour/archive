#ifndef STARSHIP_HPP
# define STARSHIP_HPP

#include <string>

#include "AEntity.hpp"
#include "Blast.hpp"

class Starship : public AEntity
{
public:
	Starship();
	Starship(std::string pattern, int w, int h, int x, int y, int vx, int vy, int hp, int color);
	Starship(const Starship& src);
	~Starship();

	Starship& operator=(const Starship& rhs);

	virtual Blast* attack() = 0;
	void takeDamage(int amount);

private:


};

#endif // STARSHIP_HPP
