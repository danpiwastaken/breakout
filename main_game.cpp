#include "main_game.h"

// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: khoi tao nhung thu can co trong main_game
void main_game::Initialize(sf::RenderWindow* window)
{
	this->_font = new sf::Font(); // khoi tao _font la new sf::Font
	this->_font->loadFromFile("Graphics/font.ttf"); // load font tu file

	this->_score1 = new Score(*_font,32U); // khoi tao _score1 la new Score voi tham so _font va co~ chu~
	this->_score1->setPosition((window->getSize().x / 2) - (this->_score1->getGlobalBounds().width) / 0.5, 0);

	this->_player1 = new player_paddle(0); // khoi tao _player1 la new player_paddle voi tham so 0
	// dat vi tri _player1 sat thanh` trai window
	this->_player1->setPosition((window->getSize().x / 2), (window->getSize().y) - 32);

	// khoi tao _ball la new ball voi tham so _score1, _score2, _player1 va _player2
	this->_ball = new ball(this->_score1, /*this->_score2,*/ this->_player1/*, this->_player2*/);
	// dat vi tri _ball o giua window
	this->_ball->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}


// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: cap nhat main_game
void main_game::Update(sf::RenderWindow* window)
{
	this->_player1->Update(window); // goi ham Update cua _player1 voi tham so window
	this->_ball->Update(window); // goi ham Update cua _ball voi tham so window
	this->_score1->Update(); // goi ham Update cua _score1 voi tham so window

	// neu nut Escape duoc bam'
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		coreState.setState(new main_menu()); // goi ham setState cua coreState voi tham so new main_menu
	}

	// neu _score1 < 0
	if (this->_score1->getScore() == -1)
	{
		coreState.setState(new end_game(1)); // goi ham setState cua coreState voi tham so new end_game co doi so la 1
	}
}


// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: ve nhung thu can co cua main_game
void main_game::Render(sf::RenderWindow* window)
{
	window->draw(*this->_player1); // ve _player1 len window
	window->draw(*this->_ball); // ve _ball len window
	window->draw(*this->_score1); // ve _score1 len window
}


// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: giai phong bo nho
void main_game::Destroy(sf::RenderWindow* window)
{
	delete this->_font; // xoa _font
	delete this->_player1; // xoa _player1
	delete this->_ball; // xoa _ball
	delete this->_score1; // xoa _score1
}
