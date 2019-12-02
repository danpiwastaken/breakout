#include "player_paddle.h"

// Input: tham sao dang con tro sf::RenderWindow tu SFML
// Output:
// Chuc nang: cap nhat player_paddle
void player_paddle::Update(sf::RenderWindow* window)
{
	switch (this->_playerNum)
	{
	case 0:
		// thay doi _velocity.y dua vao nut mui ten trai va phai 
		this->_velocity.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
		break;
	}

	// neu player_paddle di chuyen khoi thanh` trai, di chuyen x cua player_paddle len 1
	if (this->getPosition().x < 0) 
	{
		this->move(1.4f, 0);
	}
	// neu player_paddle di chuyen khoi thanh` phai, di chuyen y cua player_paddle xuong 1
	if (this->getPosition().x + this->getGlobalBounds().width > window->getSize().x)
	{
		this->move(-1.4f, 0);
	}
	Entity::Update(); // goi ham Update cua Entity de di chuyen player_paddle
}

// Input: tham so dang int
// Output: doi tuong player_paddle
// Chuc nang: khoi tao player_paddle
player_paddle::player_paddle(int playerNumber)
{
	this->_playerNum = playerNumber; // gan _playerNum bang tham so
	switch (this->_playerNum)
	{
	case 0: // playerNum la 0 nghia la player1
		this->Load("paddle1.png"); // load texture "paddle1.png" cho player_paddle
		break;
	default: // playerNum khac nghia la player2
		this->Load("paddle2.png"); // load texture "paddle2.png" cho player_paddle
		break;
	}
}

