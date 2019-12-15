#pragma once
#include "GameState.h"
#include "SFML/Audio/Music.hpp"

class main_menu :public tiny_state // class main_menu ke thua tu tiny_state
{
private:
	sf::Font* _font; // khai bao thuoc tinh _font dang con tro sf::Font
	sf::Text* _title; // khai bao thuoc tinh _title dang con tro sf::Text
	sf::Text* _play; // khai bao thuoc tinh _play dang con tro sf::Text
	sf::Text* _quit; // khai bao thuoc tinh _quit dang con tro sf::Text
	sf::Music* _music;

	int _selected; // khai bao thuoc tinh _selected dang int

	bool _isUp, _isDown; // khai bao thuoc tinh bool _isUp, _isDown
public:
	void Initialize(sf::RenderWindow* window); // khai bao ham Initialize
	void Update(sf::RenderWindow* window); // khai bao ham Update
	void Render(sf::RenderWindow* window); // khai bao ham Render
	void Destroy(sf::RenderWindow* window); // khai bao ham Destroy
};

