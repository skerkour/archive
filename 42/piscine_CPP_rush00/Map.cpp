/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:53:18 by skerkour          #+#    #+#             */
/*   Updated: 2016/10/12 11:29:39 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "Map.hpp"
#include "Player.hpp"

const int	Map::HEIGHT = 15;
const int	Map::WIDTH = 45;

Map::Map() : _player(), _score(0)
{
}

Map::Map(WINDOW* win) : _bossMode(false), _score(0), _window(win)
{
	srand(time(NULL));

	for (int i = 0; i < NB_ENEMIES; ++i) {
		_resetPosition(_entities_list[i]);
	}

	for (int i = 0; i < NB_WALLS; ++i) {
		_resetPosition(_walls[i]);
	}

	for (int i = 0; i < NB_BLAST; ++i) {
		_blast_list[i] = NULL;
	}
}

Map::Map(const Map& src)
{
	*this = src;
}

Map::~Map()
{
}

Map& Map::operator=(const Map& rhs)
{
	if (this != &rhs) {
		//_entities_list = rhs._entities_list;
		_player = rhs._player;
		_height = rhs._height;
		_width = rhs._width;
		_score = rhs._score;
		_window = rhs._window;
	}
	return *this;
}

void	Map::lap(int key)
{
	(void)key;
	if (key == KEY_UP && _player.y() > 1) {
		_player.moveY(-1);
	} else if (key == KEY_DOWN && _player.y()  + _player.height() < 31) {
		_player.moveY(1);
	} else if (key == KEY_LEFT && _player.x() > 1) {
		_player.moveX(-1);
	} else if (key == KEY_RIGHT && _player.x()  + _player.width() < 134) {
		_player.moveX(1);
	} else if (key == KEY_B) {
		_bossMode = !_bossMode;
		for (int i = 0; i < NB_BLAST; ++i) {
			if (_blast_list[i]) {
				delete _blast_list[i];
				_blast_list[i] = NULL;
			}
		}
	} else if (key == KEY_SPACE) {
		for (int i = 0; i < NB_BLAST; i++) {
			if (!_blast_list[i]) {
				Blast*	shot = _player.attack();
				_blast_list[i] = shot;
				break ;
			}
		}
/*
		if (!_blast_lst) {
			_blast_lst = new t_ent_lst;
			_blast_lst->ent = shot;
			_blast_lst->next = NULL;
		} else {
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new t_ent_lst;
			tmp->next->ent = shot;
			tmp->next->next = NULL;
		}
*/
	}

	wclear(_window);
	_renderEntity(_player);

	_computeEntities();
	if (_bossMode) {
		_renderEntity(_boss);
	} else {
		for (int i = 0; i < NB_WALLS; ++i) {
			_renderEntity(_walls[i]);
		}
		for (int i = 0; i < NB_ENEMIES; ++i) {
			_renderEntity(_entities_list[i]);
		}
	}
	//_render all other entities
	wborder(_window, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(_window);
}

unsigned int	Map::score() const
{
	return _score;
}

int	Map::player_hp() const
{
	return _player.hp();
}

void	Map::_computeEntities()
{
	if (_bossMode)
	{
		_boss.moveY(_boss.vy());
		// _boss.moveX(_boss.vx());
		if (_boss.y() <= 1 || _boss.y() + _boss.height() >= 30) {
			_boss.set_vy(_boss.vy() * -1);
		}

		// _boss.set_vx(_boss.vx() * -1);

		for (int j = 0; j < NB_BLAST; j++) {
			if (!_blast_list[j]) {
				Blast*	shot = _boss.attack();
				_blast_list[j] = shot;
				break ;
			}
		}

		for (int j = 0; j < NB_BLAST; j++) {
			if (!_blast_list[j]) {
				Blast*	shot = _boss.attack2();
				_blast_list[j] = shot;
				break ;
			}
		}



		for (int i = 0; i < NB_BLAST; ++i) { // BLAST
			if (_blast_list[i]) {
				int oldx =  _blast_list[i]->x();
				_blast_list[i]->moveX(_blast_list[i]->vx());
				int x =  _blast_list[i]->x();

				(void)x, (void)oldx;

				if (x >= _boss.x() && x <= _boss.x() + _boss.width()
					&& _blast_list[i]->y() >= _boss.y()
					&&  _blast_list[i]->y() <= _boss.y() + _boss.height()) {
					_boss.takeDamage(1);
					delete _blast_list[i];
					_blast_list[i] = NULL;
				}


				// FEATURE AMMOS
				if (_blast_list[i]) {
					if (_blast_list[i]->x() >= 137 || _blast_list[i]->x() <= 0) {
							delete _blast_list[i];
							_blast_list[i] = NULL;
					}
				}






				if (_blast_list[i] // est-ce que le missile ennemie va nous toucher ?
					&& x <= _player.x() + _player.width()
					&& oldx >= _player.x()
					&& _blast_list[i]->y() >= _player.y()
					&& _blast_list[i]->y() < _player.y() + _player.height()) {
					delete _blast_list[i];
					_blast_list[i] = NULL;
					_player.takeDamage(1);
				}



				if (_blast_list[i]) { // si toujours en vie
					_renderEntity(*_blast_list[i]);
				}

			}

		}

		if (_boss.hp() <= 0 || _player.x() + _player.width() >= _boss.x()) {
			_score += 42000;
			_player.takeDamage(42);
		}

	}
	else
	{
	for (int i = 0; i < NB_ENEMIES; ++i) { // ENEMIES

		{
			int oldx =  _entities_list[i].x();
			_entities_list[i].moveX(_entities_list[i].vx());
			int x =  _entities_list[i].x();
			//if (x <= _player.x() && oldx >= _player.x()
			//		&& _entities_list[i].y() == _player.y()) { // collision
			if (x <= _player.x() + _player.width()
					&& oldx >= _player.x()
					&& _entities_list[i].y() >= _player.y()
					&& _entities_list[i].y() < _player.y() + _player.height()) { // collision
				_player.takeDamage(1);
				_resetPosition(_entities_list[i]);
			} else if (_entities_list[i].x() <= 1) {
				_resetPosition(_entities_list[i]);
			}

			if (_entities_list[i].x() <= 136  // si toujours sur la map, possibilitee de tirer
				&& _entities_list[i].y() == _player.y() && rand() % 9 == 3) {
				for (int j = 0; j < NB_BLAST; j++) {
					if (!_blast_list[j]) {
						Blast*	shot = _entities_list[i].attack();
						_blast_list[j] = shot;
						break ;
					}
				}
			}

		}
	}
	// ASTEROIDS
	for (int i = 0; i < NB_WALLS; i++) {
		{
			int oldx =  _walls[i].x();
			_walls[i].moveX(_walls[i].vx());
			int x =  _walls[i].x();
			if (x <= _player.x() + _player.width()
					&& oldx >= _player.x()
					&& _walls[i].y() >= _player.y()
					&& _walls[i].y() < _player.y() + _player.height()) { // collision
				_player.takeDamage(1);
				_resetPosition(_walls[i]);
			} else if (_walls[i].x() <= 1) {
				_resetPosition(_walls[i]);
			}
		}
	}

	for (int i = 0; i < NB_BLAST; ++i) { // BLAST
		if (_blast_list[i]) {
			int oldx =  _blast_list[i]->x();
			_blast_list[i]->moveX(_blast_list[i]->vx());
			int x =  _blast_list[i]->x();
			for (int j = 0; j < NB_ENEMIES; j++) {
				if (x >=  _entities_list[j].x() && oldx <= _entities_list[j].x()
						&& _blast_list[i]->y()  == _entities_list[j].y()) {
					_resetPosition(_entities_list[j]);
					delete _blast_list[i];
					_blast_list[i] = NULL;
					_score += 42;
					break ;
				}
			}

			if (_blast_list[i]) {
				for (int j = 0; j < NB_WALLS; j++) {
					if (x >= _walls[j].x() && oldx <= _walls[j].x()
						&& _blast_list[i]->y() == _walls[j].y()) {
						delete _blast_list[i];
						_blast_list[i] = NULL;
						break ;
					}
				}
			}

			if (_blast_list[i] // est-ce que le missile ennemie va nous toucher ?
				&& x <= _player.x() + _player.width()
				&& oldx >= _player.x()
				&& _blast_list[i]->y() >= _player.y()
				&& _blast_list[i]->y() < _player.y() + _player.height()) {
				delete _blast_list[i];
				_blast_list[i] = NULL;
				_player.takeDamage(1);
			}

			// FEATURE AMMOS
			if (_blast_list[i]) {
				if (_blast_list[i]->x() >= 137 || _blast_list[i]->x() <= 0) {
						delete _blast_list[i];
						_blast_list[i] = NULL;
				}
			}

			if (_blast_list[i]) { // si toujours en vie
				_renderEntity(*_blast_list[i]);
			}

		}

	}
}

/*

	t_ent_lst*	tmp = _blast_lst;
	t_ent_lst*	prev = tmp;
	int x, oldx;
	bool collision = false;
	while (tmp) {
		oldx = tmp->ent->x();
		tmp->ent->moveX(tmp->ent->vx());
		x = tmp->ent->x();
		for (int i = 0; i < 142; i++) {
			if (x >=  _entities_list[i].x() && oldx <= _entities_list[i].x()
					&& tmp->ent->y()  == _entities_list[i].y() && !collision) {
				_entities_list[i].set_x(rand() % 135 + 135);
				_entities_list[i].set_y(rand() % 31);
				collision = true;
			}
		}
		if (!collision) {
			_renderEntity(*tmp->ent);
			prev = tmp;
			tmp = tmp->next;
		} else {
			if (prev != _blast_lst) {
				prev->next = tmp->next;
				//delete tmp->ent;
				//delete tmp;
				tmp = prev->next;
			} else {
				tmp = tmp->next;
				delete _blast_lst->ent;
				delete _blast_lst;
				_blast_lst = tmp;
				prev = tmp;
			}
		}
	}
*/
}

void	Map::_renderEntity(const AEntity& e)
{
	int x = e.x(),
		y = e.y();

	if (x > 0 && x < 134 && y > 0 && y < 31)
	{
		for (int i = 0; i < e.height(); i++)
		{
			std::string str = &(e.pattern().c_str()[e.width() * i]);
			str.resize(e.width());
			mvwprintw(_window, y + i, x, str.c_str());
		}
	}
}

void	Map::_resetPosition(AEntity& e)
{
	e.set_x(rand() % 135 + 135);
	e.set_y(rand() % 31);
}
