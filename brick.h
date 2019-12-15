#pragma once
#include "Entity.h"
#include <vector>
#include "ball.h"
#include "score.h"
#include <random>
#include <fstream>

namespace std
{
	enum class state { normal, destroyed };
	enum class level { easy, normal, hard, hardest };
}

class brick: public Entity
{
private:
	std::state _state;
	ball* _ball;
	std::level _level;
	int _health;
public:
	void Update(Score* score);
	void setState(std::state new_state);
	void setBall(ball* ball);
	std::state getState();
	brick();
	friend std::ofstream& operator<<(std::ofstream& out, brick* brick)
	{
		int level = 0;
		int state = 0;
	
		switch (brick->_level)
		{
		case std::level::easy:
			level = 0;
			break;
		case std::level::normal:
			level = 1;
			break;
		case std::level::hard:
			level = 2;
			break;
		case std::level::hardest:
			level = 3;
			break;
		}

		switch (brick->_state)
		{
		case std::state::normal:
			state = 0;
			break;
		case std::state::destroyed:
			state = 1;
			break;
		}

		out << std::to_string(level) << ",";
		out << std::to_string(state) << ",";
		out << std::to_string(brick->_health) << ",";
		return out;
	}
	friend std::ifstream& operator>>(std::ifstream& in, brick* brick)
	{
		int level = 0;
		int state = 0;
		int health = 0;
		std::string line;
		getline(in, line, ',');
		level = stoi(line);
		getline(in, line, ',');
		state = stoi(line);
		getline(in, line, ',');
		health = stoi(line);

		brick->_health = health;
		switch (level)
		{
		case 0:
			brick->_level = std::level::easy;
			brick->Load("brick.png");
			break;
		case 1:
			brick->_level = std::level::normal;
			brick->Load("brick2.png");
			break;
		case 2:
			brick->_level = std::level::hard;
			brick->Load("brick3.png");
			break;
		case 3:
			brick->_level = std::level::hardest;
			brick->Load("brick4.png");
			break;
		}

		switch (state)
		{
		case 0:
			brick->_state = std::state::normal;
			break;
		case 1:
			brick->_state = std::state::destroyed;
			break;
		}

		return in;
	}
};

