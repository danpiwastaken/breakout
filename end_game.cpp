#include "end_game.h"

// Input: tham so dang con tro sf::RenderWindow
// Output: 
// Chuc nang: khoi tao nhung thu can co trong end_game
void end_game::Initialize(sf::RenderWindow* window)
{
	this->_selected = 0; // gan _selected bang 0

	this->_font = new sf::Font(); // khoi tao _font la new sf::Font
	this->_font->loadFromFile("Graphics/font.ttf"); // load font tu file

	this->_player1win = new sf::Text("Player 1 win!", *this->_font, 128U); // khoi tao _player1win la new sf::Text
	// dat vi tri goc cua _player1win
	this->_player1win->setOrigin(this->_player1win->getGlobalBounds().width / 2, this->_player1win->getGlobalBounds().height / 2);
	// dat vi tri cua _player1win
	this->_player1win->setPosition(window->getSize().x / 2, window->getSize().y / 5);

	this->_player2win = new sf::Text("Player 2 win!", *this->_font, 128U); // khoi tao _player2win la new sf::Text
	// dat vi tri goc cua _player2win
	this->_player2win->setOrigin(this->_player2win->getGlobalBounds().width / 2, this->_player2win->getGlobalBounds().height / 2);
	// dat vi tri cua _player2win
	this->_player2win->setPosition(window->getSize().x / 2, window->getSize().y / 5);

	this->_playagain = new sf::Text("Play Again?", *this->_font, 64U); // khoi tao _playagain la new sf::Text
	// dat vi tri goc cua _playeragain
	this->_playagain->setOrigin(this->_playagain->getGlobalBounds().width / 2, this->_playagain->getGlobalBounds().height / 2);
	// dat vi tri cua _playeragain
	this->_playagain->setPosition(window->getSize().x / 2, window->getSize().y / 1.8);

	this->_quit = new sf::Text("Quit", *this->_font, 64U); // khoi tao _quit la new sf::Text
	// dat vi tri goc cua _quit
	this->_quit->setOrigin(this->_quit->getGlobalBounds().width / 2, this->_quit->getGlobalBounds().height / 2);
	// dat vi tri cua _quit
	this->_quit->setPosition(window->getSize().x / 2, window->getSize().y / 1.4);
}

// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: cap nhat end_game
void end_game::Update(sf::RenderWindow* window)
{
	// neu mui ten len duoc bam' va mui ten len chua dc bam' truoc do
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->_isUp) 
	{
		this->_selected -= 1; // giam _selected di 1
	}
	// neu mui ten xuong duoc bam' va mui ten xuong chua dc bam' truoc do
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->_isDown)
	{
		this->_selected += 1; // tang _selected len 1
	}
	if (this->_selected > 1) // neu _selected lon hon 1
	{
		this->_selected = 0; // gan _selected bang 0
	}
	if (this->_selected < 0) // neu _selected nho hon 0
	{
		this->_selected = 1; // gan _selected bang 1
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) // neu bam nut enter
	{
		switch (this->_selected)
		{
		case 0: // _selected = 0
			coreState.setState(new main_game()); // goi ham setState voi tham so new main_game
			break;
		case 1: // _selected = 1
			quitGame = true; // gan quitGame la true
			break;
		}
	}

	this->_isUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up); // gan _isUp bang true neu nut mui ten len duoc bam'
	this->_isDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down); // gan _isDown bang true neu nut mui ten xuong duoc bam'
}


// Input: tham so dang con tro RenderWindow
// Output:
// Chuc nang: ve nhung thu can co cua end_game
void end_game::Render(sf::RenderWindow* window)
{
	this->_playagain->setFillColor(sf::Color::White); // set _playagain mau` trang
	this->_quit->setFillColor(sf::Color::White); // set _quit mau` trang
	switch (this->_selected)
	{
	case 0: // truong hop _selected = 0
		this->_playagain->setFillColor(sf::Color::Green); // set _playagain mau` xanh la
		break;
	case 1: // truong hop _selected = 1
		this->_quit->setFillColor(sf::Color::Green); // set _quit mau` xanh la
		break;
	}
	window->draw(*this->_playagain); // ve _playagain ra window 
	window->draw(*this->_quit); // ve _quit ra window

	// neu _player bang 1
	if (this->_player == 1)
	{
		window->draw(*this->_player1win); // ve _player1win ra window
	}

	// neu _player bang 2
	if (this->_player == 2)
	{
		window->draw(*this->_player2win);  // ve _player2win ra window
	}
}
 
// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: giai phong bo nho
void end_game::Destroy(sf::RenderWindow* window)
{
	delete this->_font; // xoa _font
	delete this->_playagain; // xoa _playagain
	delete this->_quit; // xoa _quit
	delete this->_player1win; // xoa _player1win
	delete this->_player2win; // xoa _player2win
}

// Input: tham so dang int
// Output: doi tuong end_game
// Chuc nang: khoi tao end_game
end_game::end_game(int player)
{
	this->_player = player; // gan _player la tham so player
}
