#include "score.h"


// Input:
// Output:
// Chuc nang: tang score
void Score::increaseScore()
{
	this->_value += 1; // tang _value len 1
}

// Input:
// Output:
// Chuc nang: cap nhat score
void Score::Update()
{
	this->setString(std::to_string(this->_value)); // dung ham setString de set string cua Score la _value
}

// Input: tham so dang sf::Font, tham so size int
// Output: doi tuong Score
// Chuc nang: khoi tao Score
Score::Score(sf::Font &font, unsigned int size) : sf::Text("0", font, size)
{
	this->_value = 0; // gan _value la 0
}

Score::Score()
{
}


Score::~Score()
{
}
