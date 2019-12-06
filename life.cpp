#include "life.h"



void life::decreaseLife()
{
	this->_value -= 1; 
}


void life::Update()
{
	this->setString(std::to_string(this->_value)); 
}


life::life(sf::Font& font, unsigned int size) : sf::Text("0", font, size)
{
	this->_value = 3; 
}

life::life()
{
}


life::~life()
{
}
