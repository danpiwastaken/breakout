#include "main_menu.h"
#include "main_game.h"
#include <iostream>

// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: khoi tao nhung thu can co trong main_menu
void main_menu::Initialize(sf::RenderWindow* window)
{
	this->_selected = 0; // gan _selected = 0;

	this->_font = new sf::Font(); // khoi tao _font la new sf::Font
	this->_font->loadFromFile("Graphics/font.ttf"); // load font tu file

	 // khoi tao _title la new sf::Text voi tham so string, _font va co~ chu~
	this->_title = new sf::Text("Break Out", *this->_font, 128U);
	// dat vi tri goc cua _title
	this->_title->setOrigin(this->_title->getGlobalBounds().width / 2, this->_title->getGlobalBounds().height / 2);
	// dat vi tri cua _title
	this->_title->setPosition(window->getSize().x / 2, window->getSize().y / 5);

	// khoi tao _play la new sf::Text voi tham so string, _font va co~ chu~
	this->_play = new sf::Text("Play", *this->_font, 64U);
	// dat vi tri goc cua _play
	this->_play->setOrigin(this->_play->getGlobalBounds().width / 2, this->_play->getGlobalBounds().height / 2);
	// dat vi tri cua _play
	this->_play->setPosition(window->getSize().x / 2, window->getSize().y / 1.8);

	// khoi tao _quit la new sf::Text voi tham so string, _font va co~ chu~
	this->_quit = new sf::Text("Quit", *this->_font, 64U);
	// dat vi tri goc cua _quit
	this->_quit->setOrigin(this->_quit->getGlobalBounds().width / 2, this->_quit->getGlobalBounds().height / 2);
	// dat vi tri cua _quit
	this->_quit->setPosition(window->getSize().x / 2, window->getSize().y / 1.4);
}

// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: cap nhat main_menu
void main_menu::Update(sf::RenderWindow* window)
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
// Chuc nang: ve nhung thu can co cua main_menu
void main_menu::Render(sf::RenderWindow* window)
{
	this->_play->setFillColor(sf::Color::White); // set _play mau` trang
	this->_quit->setFillColor(sf::Color::White); // set _quit mau` trang
	switch (this->_selected)
	{
	case 0: // truong hop _selected = 0
		this->_play->setFillColor(sf::Color::Green); // set _play mau` xanh la
		break;
	case 1: // truong hop _selected = 1
		this->_quit->setFillColor(sf::Color::Green); // set _quit mau` xanh la
		break;
	}
	window->draw(*this->_title); // ve _title ra window
	window->draw(*this->_play); // ve _play ra window 
	window->draw(*this->_quit); // ve _quit ra window
}

// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: giai phong bo nho
void main_menu::Destroy(sf::RenderWindow* window)
{
	delete this->_font; // xoa _font
	delete this->_title; // xoa _title
	delete this->_play; // xoa _play
	delete this->_quit; // xoa _quit
}
