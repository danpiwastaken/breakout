#define NOMINMAX
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "main_menu.h"

GameState coreState; // khai bao bien coreState
bool quitGame = false; // khai bao bool quitGame la false

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 576), "Break Out"); // tao window co w:1024, h:576, ten Air Hockey

	coreState.setWindow(&window); // goi ham setWindow cua coreState voi tham so la window vua tao
	coreState.setState(new main_menu()); // goi ham setState cua coreState voi tham so la new main_menu
	
	window.setMouseCursorVisible(false); // giau con tro chuot khoi man hinh
	window.setFramerateLimit(120); // dat framerate gioi han la 120

	// chay chuong trinh khi window van dang mo
	while (window.isOpen())
	{
		window.clear(sf::Color::Black); // clear window voi mau den

		coreState.Update(); // goi ham Update cua coreState
		coreState.Render(); // goi ham Render cua coreState

		window.display(); // hien thi nhung gi da render ra window

		if (quitGame) 
		{
			window.close(); // dong window
		}

	}

	return 0;
}