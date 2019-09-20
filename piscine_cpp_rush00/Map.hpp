/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:43:33 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/21 18:13:01 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <ncurses.h>

#include "AEntity.hpp"
#include "Asteroid.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Boss.hpp"

#define NB_ENEMIES 27
#define NB_WALLS 21

#define NB_BLAST 300

// 15 unit de hauteur, 45 unit de largeur
// 30 / 135 -> 2/3

#define KEY_SPACE 32
#define KEY_B 98

class Map
{
public:
	static const int	HEIGHT;
	static const int	WIDTH;

private:
	typedef struct	s_ent_lst {
		AEntity*			ent;
		struct s_ent_lst	*next;
	}				t_ent_lst;

public:
	Map();
	Map(WINDOW* win);
	Map(const Map& src);
	~Map();

	Map& operator=(const Map& rhs);

	void			lap(int key);
	unsigned int	score() const;
	int				player_hp() const;

private:
	void	_computeEntities();
	void	_renderEntity(const AEntity& e);
	void	_resetPosition(AEntity& e);

	//t_ent_lst*		_blast_lst;
	bool			_bossMode;
	Boss			_boss;
	Blast*			_blast_list[NB_BLAST];
	Enemy			_entities_list[NB_ENEMIES];
	Asteroid		_walls[NB_WALLS];
	Player			_player;
	int				_height,
					_width;
	unsigned int	_score;
	WINDOW*			_window;
};

#endif // END: MAP_HPP
