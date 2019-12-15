#include "brick.h"

void brick::setState(std::state new_state)
{
	this->_state = new_state;
}

std::state brick::getState()
{
	return this->_state;
}

void brick::Update(Score* score)
{
	if (this->_state == std::state::destroyed)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> random(0, 100000);
		switch (random(gen))
		{
		case 1010: case 58333: case 33445: case 7000:
			this->_level = std::level::easy;
			this->setState(std::state::normal);
			this->_health = 1;
			this->Load("brick.png");
			break;
		case 37:
			this->_level = std::level::normal;
			this->setState(std::state::normal);
			this->_health = 2;
			this->Load("brick2.png");
			break;
		case 36500:
			this->_level = std::level::hard;
			this->setState(std::state::normal);
			this->_health = 3;
			this->Load("brick3.png");
			break;
		case 85000:
			this->_level = std::level::hardest;
			this->setState(std::state::normal);
			this->_health = 4;
			this->Load("brick4.png");
			break;
		default:
			break;
		}
		return void();
	}
	if (this->checkCollision(this->_ball))
	{
		this->_health -= 1;
		this->_ball->Update(this);

		if (this->_health == 0)
		{
			if (this->_level == std::level::hardest)
			{
				this->setState(std::state::destroyed);
				score->increaseScore(2);
			}
			else 
			{
				this->setState(std::state::destroyed);
				score->increaseScore();
			}
		}
	}
}

brick::brick()
{
	this->_state = std::state::normal;
	this->Load("brick.png");
	this->_level = std::level::easy;
	this->_health = 1;
}

void brick::setBall(ball* ball)
{
	this->_ball = ball;
}