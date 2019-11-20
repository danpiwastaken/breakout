#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite // clas Entity ke thua ham tu class Sprite cua SFML
{
private:
	sf::Texture* _texture; // khai bao thuoc tinh _texture
protected:
	sf::Vector2f _velocity; // khai bao thuoc tinh _velocity
public:
	void Load(std::string);
	virtual void Update();
	bool checkCollision(Entity*);
	Entity();
	~Entity();
};

