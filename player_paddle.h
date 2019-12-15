#pragma once
#include "Entity.h"
#include <fstream>

class player_paddle : public Entity // class player_paddle ke thua tu Entity
{
private:
public:
	void Update(sf::RenderWindow *window); // khai bao ham Update
	sf::Vector2f getVelocity(); // ham lay velocity
	player_paddle(); // ham tao co doi so

	friend std::ofstream& operator<<(std::ofstream& out, player_paddle* player)
	{
		out << std::to_string(player->_velocity.x) << ",";
		out << std::to_string(player->_velocity.y) << ",";
		out << std::to_string(player->getPosition().x) << ",";
		out << std::to_string(player->getPosition().y) << ",";
		return out;
	}
	friend std::ifstream& operator>>(std::ifstream& in, player_paddle* player)
	{
		float pos_x;
		float pos_y;
		std::string line;
		getline(in, line, ',');
		player->_velocity.x = stof(line);
		getline(in, line, ',');
		player->_velocity.y = stof(line);
		getline(in, line, ',');
		pos_x = stof(line);
		getline(in, line, ',');
		pos_y = stof(line);
		player->setPosition(pos_x, pos_y);
		return in;
	}
};