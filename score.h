#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>

class Score : public sf::Text // class Score ke thua tu sf::Text
{
private:
	int _value; // khai bao thuoc tinh value dang int
public:
	// Input:
	// Output: _value
	const int getScore() { return this->_value; } 
	void increaseScore(); // khai bao ham IncreaseScore
	void increaseScore(int amount);
	void Update(); // khai bao ham Update
	Score(sf::Font &font, unsigned int size); // ham tao co doi so
	Score(); // ham tao k doi so
	~Score(); // ham huy
	friend std::ofstream& operator<<(std::ofstream& out, Score* score)
	{
		out << std::to_string(score->_value) << ",";
		return out;
	}
	friend std::ifstream& operator>>(std::ifstream& in, Score* score)
	{
		std::string line;
		getline(in, line, ',');
		score->_value = stoi(line);
		return in;
	}
};

