#pragma once
#include <SFML/Graphics.hpp>

class life : public sf::Text
{
private:
	int _value; 
public:
	
	const int getLife() { return this->_value; }
	void decreaseLife(); 
	void Update(); 
	life(sf::Font& font, unsigned int size); 
	life(); 
	~life(); 
};

