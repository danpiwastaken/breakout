#pragma once
#include "main_game.h"
#include <vector>
#include <fstream>
#include <sstream>
#include "Button.h"
#include "Textbox.h"
#include <algorithm>
#include <SFML/Audio/Music.hpp>

#define SAVE_FILE_PATH "Resources/Saves.txt"
#define SCORE_FILE_PATH "Resources/Scores.txt"
#define NUM_OF_ROWS 5
#define DEFAULT_X 100
#define DEFAULT_Y 140

class end_game : public tiny_state // class end_game ke thua tu tiny_state
{
public:
	struct Entry
	{
		std::string playerName;
		std::string playerScore;
	};
private:
	int _score; 

	sf::Font* _font; // khai bao thuoc tinh _font dang con tro sf::Font
	sf::Text* _playagain; // khai bao thuoc tinh _playagain dang con tro sf::Text
	sf::Text* _quit; // khai bao thuoc tinh _quit dang con tro sf::Text
	sf::Text* _playerlose; // khai bao thuoc tinh _player1lose dang con tro sf::Text

	int _selected; // khai bao thuoc tinh _selected dang int

	bool _isLeft, _isRight; // khai bao thuoc tinh bool _isUp, _isDown

	std::vector<Entry> _playerList;

	sf::Text* _scores;
	sf::Text* _names;

	sf::Text* _scoreText;
	sf::Text* _nameText;

	sf::Music* _music;
	Textbox* _text1;
	Button* _btn1;
public:
	void Initialize(sf::RenderWindow* window); // khai bao ham Initialize
	void Update(sf::RenderWindow* window); // khai bao ham Update
	void Render(sf::RenderWindow* window); // khai bao ham Render
	void Destroy(sf::RenderWindow* window); // khai bao ham Destroy
	end_game(int); // ham tao co doi so
};

