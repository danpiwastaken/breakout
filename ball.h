#pragma once
#include "player_paddle.h"
#include "score.h"
class ball : public Entity // class ball ke thua tu Entity
{
private:
	player_paddle* _player1; // khai bao thuoc tinh _player1 dang con tro player_paddle
	//player_paddle* _player2; // khai bao thuoc tinh _player2 dang con tro player_paddle
	Score* _score1; // khai bao thuoc tinh _score1 dang con tro Score
	//Score* _score2; // khai bao thuoc tinh _score2 dang con tro Score

public:
	void Update(sf::RenderWindow* window); // khai bao ham Update
	void Reset(sf::RenderWindow* window); // khai bao ham Reset
	ball(Score* score1, /*Score* score2,*/ player_paddle* player1/*, player_paddle* player2*/); // ham tao co doi so
	ball(); // ham tao
	~ball(); // ham huy
};

