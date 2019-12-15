#pragma once
#include "player_paddle.h"
#include "score.h"
#include "life.h"
#include <fstream>

class ball : public Entity // class ball ke thua tu Entity
{
private:
	player_paddle* _player1; // khai bao thuoc tinh _player1 dang con tro player_paddle
	life* _life; // khai bao thuoc tinh _score1 dang con tro Score
public:
	void Update(sf::RenderWindow* window); // khai bao ham Update
	void Update(Entity* entity);
	void Reset(sf::RenderWindow* window); // khai bao ham Reset
	ball(life* life, /*Score* score2,*/ player_paddle* player1/*, player_paddle* player2*/); // ham tao co doi so
	void increaseSpeed(float amount);
	ball(); // ham tao
	~ball(); // ham huy

	sf::Vector2f getVelocity();

	friend std::ofstream& operator<<(std::ofstream& out, ball* ball)
	{
		out << std::to_string(ball->_velocity.x) << ",";
		out << std::to_string(ball->_velocity.y) << ",";
		out << std::to_string(ball->getPosition().x) << ",";
		out << std::to_string(ball->getPosition().y) << ",";
		return out;
	}

	friend std::ifstream& operator>>(std::ifstream& in, ball* ball)
	{
		float pos_x;
		float pos_y;
		std::string line;
		getline(in, line, ',');
		ball->_velocity.x = stof(line);
		getline(in, line, ',');
		ball->_velocity.y = stof(line);
		getline(in, line, ',');
		pos_x = stof(line);
		getline(in, line, ',');
		pos_y = stof(line);
		ball->setPosition(pos_x, pos_y);
		return in;
	}
};

