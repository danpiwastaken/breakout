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

	sf::Texture BackgroundTexture;
	sf::Sprite background;
	sf::Vector2u TextureSize;  //Added to store texture size.
	sf::Vector2u WindowSize;   //Added to store window size.

	if (!BackgroundTexture.loadFromFile("Graphics/background.jpg"))
	{
		return -1;
	}
	else
	{
		TextureSize = BackgroundTexture.getSize(); //Get size of texture.
		WindowSize = window.getSize();             //Get size of window.

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

		background.setTexture(BackgroundTexture);
		background.setScale(ScaleX, ScaleY);      //Set scale.  
	}

	coreState.setWindow(&window); // goi ham setWindow cua coreState voi tham so la window vua tao
	coreState.setState(new main_menu()); // goi ham setState cua coreState voi tham so la new main_menu
	
	window.setMouseCursorVisible(false); // giau con tro chuot khoi man hinh
	window.setFramerateLimit(120); // dat framerate gioi han la 120

	// chay chuong trinh khi window van dang mo
	while (window.isOpen())
	{
		window.clear(); // clear window

		window.draw(background);

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