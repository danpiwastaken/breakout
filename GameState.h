#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class tiny_state
{
public:
	virtual void Initialize(sf::RenderWindow* window) {}; //khai bao ham Initialize
	virtual void Update(sf::RenderWindow* window) {}; // khai bao ham Update
	virtual void Render(sf::RenderWindow* window) {}; // khai bao ham Render
	virtual void Destroy(sf::RenderWindow* window) {}; // khai bao ham Destroy
};

class GameState
{
private:
	sf::RenderWindow* _window; // khai bao thuoc tinh _window dang sf::RenderWindow tu SFML
	tiny_state* _state; // khai bao thuoc tinh _state dang tiny_state
public:
	// Input: tham so dang sf::RenderWindow
	// Output:
	void setWindow(sf::RenderWindow* window) {this->_window = window;} // gan thuoc tinh _window la tham so window
	void setState(tiny_state* state); // khai bao ham setState
	void Update(); // khai bao ham Update
	void Render(); // khai bao ham Render
	GameState(); // ham tao
	~GameState(); // ham huy
};

// khai bao extern de cac source file khac deu dung dc 2 bien nay
extern GameState coreState; // khai bao bien coreState dang GameState
extern bool quitGame; // khai bao bool quitGame