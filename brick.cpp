#include "brick.h"

void brick::setState(std::state new_state)
{
	this->_state = new_state;
}

std::state brick::getState()
{
	return this->_state;
}

void brick::Update()
{
	if (this->_state == std::state::destroyed)
	{
		return void();
	}
	if (this->checkCollision(this->_ball))
	{
		this->setState(std::state::destroyed);
		this->_ball->Update(this);
	}
}

brick::brick()
{
	this->_state = std::state::normal;
	this->Load("brick.png");
}

void brick::setBall(ball* ball)
{
	this->_ball = ball;
}