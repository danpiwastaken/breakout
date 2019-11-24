#include "ball.h"



ball::ball()
{
}

// Input: tham so dang con tro sf::RenderWindor tu SFML
// Output:
// Chuc nang: cap nhat ball
void ball::Update(sf::RenderWindow* window)
{
	float n = -1; // khai bao n = -1

	// neu ball va cham voi _player1, _player2
	if (this->checkCollision(this->_player1) || this->getPosition().y < 0 /*|| this->checkCollision(this->_player2)*/) 
	{
		n -= 0.02f; // giam n di 0.02
		this->_velocity.y *= n; // nhan _velocity.y voi n
	}

	// neu ball va cham voi thanh` trai hoac phai
	if (this->getPosition().x < 0 || this->getPosition().x + this->getGlobalBounds().width > window->getSize().x)
	{
		this->_velocity.x *= -1; // nhan _velocity.y voi n
	}

	Entity::Update(); // goi ham Update cua Entity de di chuyen ball

	//if (this->getPosition().x < 0) // neu ball cham thanh` trai
	//{
	//	this->_score2->increaseScore(); // tang _score2
	//	this->Reset(window); // goi ham Reset
	//}

	//// neu ball cham thanh` phai
	//if (this->getPosition().x + this->getGlobalBounds().width > window->getSize().x + this->_player2->getGlobalBounds().width - 30 )
	//{
	//	this->_score1->increaseScore(); //tang _score1
	//	this->Reset(window); // goi ham Reset
	//}

	if (this->getPosition().y + this->getGlobalBounds().height > window->getSize().y)
	{
		this->_score1->decreaseScore();
		this->Reset(window);
	}
}

// Input: tham so dang con tro sf::RenderWindow tu SFML
// Output:
// Chuc nang: bat dau lai game
void ball::Reset(sf::RenderWindow* window)
{
	this->_player1->setPosition((window->getSize().x / 2), (window->getSize().y) - 32); // dat vi tri player1 ve giua thanh` duoi

	// dat vi tri player2 ve giua thanh` phai
	//this->_player2->setPosition(window->getSize().x - this->_player2->getGlobalBounds().width, (window->getSize().y / 2) - 50);

	this->setPosition(window->getSize().x / 2, window->getSize().y / 2); // dat vi tri ball ve giua window
	this->_velocity.x = 1.0f; // gan _velocity.x ve lai 1
	this->_velocity.y = 0.75f; // gan _velocity.y ve lai 0.75
}

// Input: score1, score2 dang con tro Score; player1, player2 dang con tro player_paddle
// Output: doi tuong ball
ball::ball(Score* score1, /*Score* score2,*/ player_paddle* player1/*, player_paddle* player2*/)
{
	this->Load("ball.png"); // load texture cua ball bang "ball.png"
	this->_player1 = player1; // gan _player1 la player1
	//this->_player2 = player2; // gan _player2 la player2
	
	this->_score1 = score1; // gan _score1 la score1
	//this->_score2 = score2; // gan _score2 la score2

	this->_velocity.x = 1.0f; // gan _velocity.x la 1
	this->_velocity.y = 0.75f; // gan _velocity.y la 0.75
}

ball::~ball()
{
}
