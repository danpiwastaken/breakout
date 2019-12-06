#pragma once
#include "Entity.h"

class player_paddle : public Entity // class player_paddle ke thua tu Entity
{
private:
	int _playerNum; // khai bao thuoc tinh _playerNum
public:
	void Update(sf::RenderWindow *window); // khai bao ham Update
	sf::Vector2f getVelocity(); // ham lay velocity
	player_paddle(int); // ham tao co doi so
};