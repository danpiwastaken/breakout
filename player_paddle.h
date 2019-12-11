#pragma once
#include "Entity.h"

class player_paddle : public Entity // class player_paddle ke thua tu Entity
{
private:
public:
	void Update(sf::RenderWindow *window); // khai bao ham Update
	sf::Vector2f getVelocity(); // ham lay velocity
	player_paddle(); // ham tao co doi so
};