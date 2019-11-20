#pragma once
#include "main_game.h"
class end_game : public tiny_state // class end_game ke thua tu tiny_state
{
private:
	int _player; // khai bao thuoc tinh _player dang int

	sf::Font* _font; // khai bao thuoc tinh _font dang con tro sf::Font
	sf::Text* _playagain; // khai bao thuoc tinh _playagain dang con tro sf::Text
	sf::Text* _quit; // khai bao thuoc tinh _quit dang con tro sf::Text
	sf::Text* _player1win; // khai bao thuoc tinh _player1win dang con tro sf::Text
	sf::Text* _player2win; // khai bao thuoc tinh _player2win dang con tro sf::Text

	int _selected; // khai bao thuoc tinh _selected dang int

	bool _isUp, _isDown; // khai bao thuoc tinh bool _isUp, _isDown
public:
	void Initialize(sf::RenderWindow* window); // khai bao ham Initialize
	void Update(sf::RenderWindow* window); // khai bao ham Update
	void Render(sf::RenderWindow* window); // khai bao ham Render
	void Destroy(sf::RenderWindow* window); // khai bao ham Destroy
	end_game(int); // ham tao co doi so
};

