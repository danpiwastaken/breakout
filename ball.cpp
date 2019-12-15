#include "ball.h"
#define increasement 0.02
#define increasement2 0.02
#define maxSpeed 5.0

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
		// tinh vi tri tuong doi cua mep duong trai banh va mep tren thanh truot
		int height_distance = this->getPosition().y + this->getGlobalBounds().height - this->_player1->getPosition().y; 
		if (height_distance<=1 && height_distance >= 0) // neu mep duoi banh cham mep duoi thanh truot
		{
			//n -= 0.03f; // giam n di 0.03
			this->_velocity.y *= n; // nhan _velocity.y voi n
			this->increaseSpeed(increasement);
			
		}
		else if (height_distance > 0) // neu mep duoi banh thap hon mep tren thanh truot
		{
			sf::Vector2f paddle_velocity = this->_player1->getVelocity(); // lay gia toc cua thanh truot 
			if (paddle_velocity.x > 0) // neu gia toc > 0
			{ 
				paddle_velocity.x = -0.8;
			}
			else
			{
				paddle_velocity.x = 0.8;
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
		this->_life->decreaseLife();
		this->Reset(window);
	}
}

void ball::Update(Entity* entity)
{

	int height_distance = this->getPosition().y - (entity->getPosition().y + entity->getGlobalBounds().height);


	if (height_distance >= -1 && height_distance < 0 && this->_velocity.y < 0)
	{
		height_distance = 0;
	}


	int upper_measure = this->getPosition().y + this->getGlobalBounds().height + entity->getGlobalBounds().height - (entity->getPosition().y + entity->getGlobalBounds().height);

	if (upper_measure <= 1 && upper_measure > 0 && this->_velocity.y > 0)
	{
		upper_measure = 0;
	}

	if (upper_measure == 0)
	{
		this->_velocity.y *= -1;
		this->increaseSpeed(increasement2);
	}
	else if (height_distance == 0 )
	{
		this->_velocity.y *= -1;
		this->increaseSpeed(increasement2);
	}
	else if (height_distance < 0)
	{
		this->_velocity.x *= -1;
		this->increaseSpeed(increasement2);
	}
	Entity::Update();
}

// Input: tham so dang con tro sf::RenderWindow tu SFML
// Output:
// Chuc nang: bat dau lai game
void ball::Reset(sf::RenderWindow* window)
{
	this->_player1->setPosition((window->getSize().x / 2), (window->getSize().y) - 32); // dat vi tri player1 ve giua thanh` duoi

	this->setPosition(window->getSize().x / 2 + 30, window->getSize().y / 2 + 30); // dat vi tri ball ve giua window
	this->_velocity.x = 0.6f; // gan _velocity.x la 1
	this->_velocity.y = 1.2f;// gan _velocity.y ve lai 0.75
}

// Input: score1, score2 dang con tro Score; player1, player2 dang con tro player_paddle
// Output: doi tuong ball
ball::ball(life* life, /*Score* score2,*/ player_paddle* player1/*, player_paddle* player2*/)
{
	this->Load("ball.png"); // load texture cua ball bang "ball.png"
	this->_player1 = player1; // gan _player1 la player1
	
	this->_life = life; // gan _score1 la score1

	this->_velocity.x = 0.6f; // gan _velocity.x la 0.55
	this->_velocity.y = 1.2f; // gan _velocity.y la 1.2
}


ball::~ball()
{
}

void ball::increaseSpeed(float amount)
{
	float velocity;
	if (this->_velocity.y < 0)
	{
		velocity = -1 * this->_velocity.y;
	}
	else
	{
		velocity = this->_velocity.y;
	}
	if (velocity < maxSpeed)
	{
		if (this->_velocity.y < 0)
		{
			this->_velocity.y -= amount;
		}
		else
		{
			this->_velocity.y += amount;
		}
		if (this->_velocity.x < 0)
		{
			this->_velocity.x -= amount;
		}
		else
		{
			this->_velocity.x += amount;
		}
	}
}

sf::Vector2f ball::getVelocity()
{
	return this->_velocity;
}
