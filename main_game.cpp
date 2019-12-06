#include "main_game.h"
#define ROW 5
#define COLUMN 12


// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: khoi tao nhung thu can co trong main_game
void main_game::Initialize(sf::RenderWindow* window)
{
	this->_font = new sf::Font(); // khoi tao _font la new sf::Font
	this->_font->loadFromFile("Graphics/font.ttf"); // load font tu file

	this->_life = new life(*_font,32U); // khoi tao mang
	this->_life->setPosition(this->_life->getGlobalBounds().width, 0);
	
	this->_scoretext = new sf::Text("Scores: ", *this->_font, 32U);
	this->_scoretext->setPosition(window->getSize().x - (this->_scoretext->getGlobalBounds().width + 30) , 0);

	this->_score = new Score(*_font, 32U);
	this->_score->setPosition(window->getSize().x - this->_score->getGlobalBounds().width, 0);

	this->_player = new player_paddle; // khoi tao _player1 la new player_paddle voi tham so 0
	// dat vi tri _player1 sat thanh` trai window
	this->_player->setPosition((window->getSize().x / 2), (window->getSize().y) - 32);

	// khoi tao _ball la new ball voi tham so _score1, _score2, _player1 va _player2
	this->_ball = new ball(this->_life, /*this->_score2,*/ this->_player/*, this->_player2*/);
	// dat vi tri _ball o giua window
	this->_ball->setPosition(window->getSize().x / 2, window->getSize().y / 2);


	// khai báo các cục gạch 
	this->_brick = new brick[12];
	int x = 50;
	int y = 70;
	for (int i = 0; i < 12; i++)
	{
		if (i % 6 == 0 && i != 0)
		{
			x = 50;
			y += this->_brick[i - 1].getGlobalBounds().height + 10;
		}
		else if (i != 0)
		{
			x += this->_brick[i-1].getGlobalBounds().width + 20;
		}
		this->_brick[i].setBall(this->_ball);
		this->_brick[i].setPosition(x, y);
	}
}


// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: cap nhat main_game
void main_game::Update(sf::RenderWindow* window)
{
	this->_player->Update(window); // goi ham Update cua _player1 voi tham so window
	this->_ball->Update(window); // goi ham Update cua _ball voi tham so window
	this->_life->Update(); // goi ham Update cua _life voi tham so window
	this->_score->Update();
	
	for (int i = 0; i < 12; i++)
	{
		this->_brick[i].Update(this->_score);
	}

	// neu nut Escape duoc bam'
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		coreState.setState(new main_menu()); // goi ham setState cua coreState voi tham so new main_menu
	}

	// neu _score1 < 0
	if (this->_life->getLife() == -1)
	{
		coreState.setState(new end_game(1)); // goi ham setState cua coreState voi tham so new end_game co doi so la 1
	}
}


// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: ve nhung thu can co cua main_game
void main_game::Render(sf::RenderWindow* window)
{
	window->draw(*this->_player); // ve _player1 len window
	window->draw(*this->_ball); // ve _ball len window
	window->draw(*this->_life); // ve _score1 len window
	window->draw(*this->_score);
	window->draw(*this->_scoretext);


	// vẽ các cục gạch
	for (int i = 0; i < 12; i++)
	{
		if (this->_brick[i].getState() == std::state::normal)
		{
			window->draw(this->_brick[i]);
		}
	}
}


// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: giai phong bo nho
void main_game::Destroy(sf::RenderWindow* window)
{
	delete this->_font; // xoa _font
	delete this->_player; // xoa _player1
	delete this->_ball; // xoa _ball
	delete this->_life; // xoa _life
	delete[] this->_brick;
	delete this->_score;
	delete this->_scoretext;
}
