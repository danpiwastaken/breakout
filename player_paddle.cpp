#include "player_paddle.h"

// Input: tham sao dang con tro sf::RenderWindow tu SFML
// Output:
// Chuc nang: cap nhat player_paddle
void player_paddle::Update(sf::RenderWindow* window)
{
	// thay doi _velocity.y dua vao nut mui ten trai va phai 
	this->_velocity.x = 1.5*(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left));

	// neu player_paddle di chuyen khoi thanh` trai, di chuyen x cua player_paddle len 1
	if (this->getPosition().x < 0)
	{
		this->move(1.5f, 0);
	}
	// neu player_paddle di chuyen khoi thanh` phai, di chuyen y cua player_paddle xuong 1
	if (this->getPosition().x + this->getGlobalBounds().width > window->getSize().x)
	{
		this->move(-1.5f, 0);
	}
	Entity::Update(); // goi ham Update cua Entity de di chuyen player_paddle
}

// Input: tham so dang int
// Output: doi tuong player_paddle
// Chuc nang: khoi tao player_paddle
player_paddle::player_paddle()
{
	this->Load("paddle.png"); // load texture "paddle1.png" cho player_paddle
	
}

// Output: velocity cua doi tuong player_paddle
// Chuc nang: tra ve velocity 
sf::Vector2f player_paddle::getVelocity()
{
	return this->_velocity;
}