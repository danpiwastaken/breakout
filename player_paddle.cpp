#include "player_paddle.h"

// Input: tham sao dang con tro sf::RenderWindow tu SFML
// Output:
// Chuc nang: cap nhat player_paddle
void player_paddle::Update(sf::RenderWindow* window)
{
	switch (this->_playerNum)
	{
	case 0:
		// thay doi _velocity.y dua vao nut S va W 
		this->_velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
		break;
	default:
		// thay doi _velocity.y dua vao nut mui ten len va xuong
		this->_velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
		break;
	}

	// neu player_paddle di chuyen khoi thanh` tren, di chuyen y cua player_paddle len 1
	if (this->getPosition().y < 0) 
	{
		this->move(0, 1.0f);
	}
	// neu player_paddle di chuyen khoi thanh` duoi, di chuyen y cua player_paddle xuong 1
	if (this->getPosition().y + this->getGlobalBounds().height > window->getSize().y)
	{
		this->move(0, -1.0f);
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

