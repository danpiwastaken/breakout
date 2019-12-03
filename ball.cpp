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
	sf::Vector2f origin;

	// neu ball va cham voi _player1
	if (this->checkCollision(this->_player1)) // neu banh va cham voi paddle
	{
		int height_distance = this->getPosition().y + this->getGlobalBounds().height - this->_player1->getPosition().y; // tinh vi tri tuong doi cua mep duong trai banh va mep tren thanh truot
		if (height_distance == 0) // neu mep duoi banh cham mep duoi thanh truot
		{
			n -= 0.02f; // giam n di 0.02
			this->_velocity.y *= n; // nhan _velocity.y voi n
		}
		else if (height_distance > 0) // neu mep duoi banh thap hon mep tren thanh truot
		{
			sf::Vector2f paddle_velocity = this->_player1->getVelocity(); // lay gia toc cua thanh truot 
			if (paddle_velocity.x > 0) // neu gia toc > 0
			{ 
				paddle_velocity.x *= -1; // tra ve gia tri am
			}
			n += paddle_velocity.x; // giam n di mot luong bang voi gia toc cua thanh truot 
			this->_velocity.x *= n; // nhan _velocity.x voi n
		}
	}

	// neu ball va cham voi tuong tren
	if (this->getPosition().y < 0)
	{
		this->_velocity.y *= -1;
	}

	// neu ball va cham voi thanh` trai hoac phai
	if (this->getPosition().x < 0 || this->getPosition().x + this->getGlobalBounds().width > window->getSize().x)
	{
		this->_velocity.x *= -1; // nhan _velocity.y voi n
	}

	Entity::Update(); // goi ham Update cua Entity de di chuyen ball

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
	
	this->_score1 = score1; // gan _score1 la score1

	this->_velocity.x = 1.0f; // gan _velocity.x la 1
	this->_velocity.y = 0.75f; // gan _velocity.y la 0.75
}

ball::~ball()
{
}
