* single-player
* should use ncurses
* V or H scrolling
* random ennemies
* player can shoot at ennemies
* basic collision handling
* game entities occupy one 'square' of the map only
* frame based timing
* Displaying score, time, number of lives, etc... on screen
* Clock-based timing
* Entities that can occupy multiple squares
* Enemies can also shoot
* Scenery (Collidable objects or simple background)

* High scores
* bonuses
* Large and hard-to-beat boss enemies
* Enemies have a scripted behaviour
* Multiplayer
* Scripted game worlds, with pre-determined batches of enemies

-> all entites subclasses of a GameEntity class ? mayber an interface ?

1. Acquire input
2. Update game entities
3. Render display
4. Repeat until game ends


### entitees:

	partie:
		- initialiser l'environnement (screen, hooks)
		- jouer
		- score
		- current map (entities position)
		- affichage
	object:
		- vaisseaux:
			- players's starship
			- ennemies
		- projectiles:
		- decors ?


##Class

Map:
	listEnemies
	addEnemi
	deleteEnemi
	finishGame
	_renderEntity(Entity& e);


Entity:
	_velocity
	_pY
	_pX
	_sW
	_sH
	_hp

	takeDamage
	attack

Player:
	sendBlast
