#include "main_game.h"

// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: khoi tao nhung thu can co trong main_game
void main_game::Initialize(sf::RenderWindow* window)
{
	this->_font = new sf::Font(); // khoi tao _font la new sf::Font
	this->_font->loadFromFile("Graphics/font.ttf"); // load font tu file

	this->_score1 = new Score(*_font,32U); // khoi tao _score1 la new Score voi tham so _font va co~ chu~
	// dat vi tri _score1 lech sang trai so voi giua tren window
	this->_score1->setPosition((window->getSize().x / 2) - (this->_score1->getGlobalBounds().width) / 0.5, 0);

	this->_divider = new sf::Text(":", *this->_font, 32U); // khoi tao _divider la new sf::Text voi tham so string, _font va co~ chu~
	// dat vi tri _divider o giua tren window
	this->_divider->setPosition(window->getSize().x / 2 + this->_divider->getGlobalBounds().width / 1.4, 0);

	this->_score2 = new Score(*_font,32U); // khoi tao _score2 la new Score voi tham so _font va co~ chu~
	// dat vi tri _score2 lech sang phai so voi giua tren window
	this->_score2->setPosition((window->getSize().x / 2) + (this->_score2->getGlobalBounds().width) / 0.5 , 0);

	this->_player1 = new player_paddle(0); // khoi tao _player1 la new player_paddle voi tham so 0
	// dat vi tri _player1 sat thanh` trai window
	this->_player1->setPosition(0, (window->getSize().y / 2) - 50);

	this->_player2 = new player_paddle(1); // khoi tao _player2 la new player_paddle voi tham so 1
	// dat vi tri _player1 sat thanh` phai window
	this->_player2->setPosition(window->getSize().x - this->_player2->getGlobalBounds().width, (window->getSize().y / 2) - 50);

	// khoi tao _ball la new ball voi tham so _score1, _score2, _player1 va _player2
	this->_ball = new ball(this->_score1, this->_score2, this->_player1, this->_player2);
	// dat vi tri _ball o giua window
	this->_ball->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}


// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: cap nhat main_game
void main_game::Update(sf::RenderWindow* window)
{
	this->_player1->Update(window); // goi ham Update cua _player1 voi tham so window
	this->_player2->Update(window); // goi ham Update cua _player2 voi tham so window
	this->_ball->Update(window); // goi ham Update cua _ball voi tham so window
	this->_score1->Update(); // goi ham Update cua _score1 voi tham so window
	this->_score2->Update(); // goi ham Update cua _score2 voi tham so window

	// neu nut Escape duoc bam'
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		coreState.setState(new main_menu()); // goi ham setState cua coreState voi tham so new main_menu
	}

	// neu _score1 = 5
	if (this->_score1->getScore() == 5)
	{
		coreState.setState(new end_game(1)); // goi ham setState cua coreState voi tham so new end_game co doi so la 1
	}

	// neu _score2 = 5
	if (this->_score2->getScore() == 5)
	{
		coreState.setState(new end_game(2)); // goi ham setState cua coreState voi tham so new end_game co doi so la 2
	}
}


// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: ve nhung thu can co cua main_game
void main_game::Render(sf::RenderWindow* window)
{
	window->draw(*this->_player1); // ve _player1 len window
	window->draw(*this->_player2); // ve _player2 len window
	window->draw(*this->_ball); // ve _ball len window
	window->draw(*this->_score1); // ve _score1 len window
	window->draw(*this->_score2); // ve _score2 len window
	window->draw(*this->_divider); // ve _divider len window
}


// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: giai phong bo nho
void main_game::Destroy(sf::RenderWindow* window)
{
	delete this->_font; // xoa _font
	delete this->_player1; // xoa _player1
	delete this->_player2; // xoa _player2
	delete this->_ball; // xoa _ball
	delete this->_score1; // xoa _score1
	delete this->_score2; // xoa _score2
	delete this->_divider; // xoa _divider
}
