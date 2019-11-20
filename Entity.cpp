#include "Entity.h"


// Input: ten file
// Output: Entity co texture
// Chuc nang: load texture cho Entity goi ham 
void Entity::Load(std::string filename)
{
	this->_texture->loadFromFile("Graphics/sprites/" + filename); // load file cho texture
	this->setTexture(*this->_texture); // set file do thanh texture cho _texture 
}

// Input: 
// Output:
// Chuc nang: di chuyen Entity
void Entity::Update()
{
	this->move(this->_velocity); // di chuyen Entity voi tham so _velocity
}

// Input: tham so dang Entity
// Output: true or false
// Chuc nang: kiem tra va cham cua Entity
bool Entity::checkCollision(Entity* entity)
{
	// kiem tra canh cua entity goi ham co va cham 
	//voi canh cua entity truyen vao khong
	return this->getGlobalBounds().intersects(entity->getGlobalBounds());
}

// ham tao Entity
Entity::Entity()
{
	this->_texture = new sf::Texture(); // gan thuoc tinh _texture là new sf::Texture tu SFML
}

// ham huy
Entity::~Entity()
{
	delete this->_texture; // huy thuoc tinh _texture
}
