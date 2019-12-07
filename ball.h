#pragma once
#include "player_paddle.h"
#include "score.h"
#include "life.h"

class ball : public Entity // class ball ke thua tu Entity
{
private:
	player_paddle* _player1; // khai bao thuoc tinh _player1 dang con tro player_paddle
	life* _life; // khai bao thuoc tinh _score1 dang con tro Score
public:
	void Update(sf::RenderWindow* window); // khai bao ham Update
	void Update(Entity* entity);
	void Reset(sf::RenderWindow* window); // khai bao ham Reset
	ball(life* life, /*Score* score2,*/ player_paddle* player1/*, player_paddle* player2*/); // ham tao co doi so

	ball(); // ham tao
	~ball(); // ham huy
};

