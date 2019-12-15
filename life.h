#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>

class life : public sf::Text
{
private:
	int _value; 
public:
	
	const int getLife() { return this->_value; }
	void setLife(int amount) { this->_value = amount; }
	void decreaseLife(); 
	void Update(); 
	life(sf::Font& font, unsigned int size); 
	life(); 
	~life(); 
	friend std::ofstream& operator<<(std::ofstream& out, life* life)
	{
		out << std::to_string(life->_value) << ",";
		return out;
	}
	friend std::ifstream& operator>>(std::ifstream& in, life* life)
	{
		std::string line;
		getline(in, line, ',');
		life->_value = stoi(line);
		return in;
	}
};

