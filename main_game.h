#pragma once
#include "main_menu.h"
#include "end_game.h"
#include "ball.h"

class main_game :public tiny_state // class main_game ke thua tu tiny_state
{
private:
	player_paddle* _player1; // khai bao thuoc tinh _player1 dang con tro player_paddle
	//player_paddle* _player2; // khai bao thuoc tinh _player2 dang con tro player_paddle
	ball* _ball; // khai bao thuoc tinh _ball dang con tro ball
	sf::Font* _font; // khai bao thuoc tinh _font dang con tro sf::Font
	Score* _score1; // khai bao thuoc tinh _score1 dang con tro Score
	//Score* _score2; // khai bao thuoc tinh _score2 dang con tro Score
	//sf::Text* _divider; // khai bao thuoc tinh _divider dang con tro sf::Text

public:
	void Initialize(sf::RenderWindow* window); // khai bao ham Initialize
	void Update(sf::RenderWindow* window); // khai bao ham Update
	void Render(sf::RenderWindow* window); // khai bao ham Render
	void Destroy(sf::RenderWindow* window); // khi bao ham Destroy
};
