#pragma once
#include "main_menu.h"
#include "end_game.h"
#include "brick.h"
#include <SFML/Audio/Music.hpp>

class main_game :public tiny_state // class main_game ke thua tu tiny_state
{
private:
	player_paddle* _player; // khai bao thuoc tinh _player1 dang con tro player_paddle
	ball* _ball; // khai bao thuoc tinh _ball dang con tro ball
	sf::Font* _font; // khai bao thuoc tinh _font dang con tro sf::Font
	life* _life; // khai bao thuoc tinh _score1 dang con tro Score
	brick* _brick;
	sf::Text* _scoretext;
	Score* _score;
	Entity* _heart;	
	sf::Music* _music;

	// giao dien khi nhan escape
	sf::Text* _save;
	sf::Text* _load;
	sf::Text* _main_menu;
	sf::Text* _quit;
	sf::Text* _back;
	int _selected;

	bool _isUp, _isDown, _inSelection;
public:
	void Initialize(sf::RenderWindow* window); // khai bao ham Initialize
	void Update(sf::RenderWindow* window); // khai bao ham Update
	void Render(sf::RenderWindow* window); // khai bao ham Render
	void Destroy(sf::RenderWindow* window); // khi bao ham Destroy
	void SaveGame();
	void LoadGame();
};
