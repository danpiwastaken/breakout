#include "end_game.h"

// Input: tham so dang con tro sf::RenderWindow
// Output: 
// Chuc nang: khoi tao nhung thu can co trong end_game
void end_game::Initialize(sf::RenderWindow* window)
{
	window->setMouseCursorVisible(true);
	std::string line;
	std::ifstream readFile;
	readFile.open(SCORE_FILE_PATH);
	if (readFile.is_open())
	{
		std::vector<std::string> tokens;
		std::string intermediate;
		while (getline(readFile, line))
		{
			std::stringstream ss(line);
			while (getline(ss, intermediate, ','))
			{
				tokens.push_back(intermediate);
			}
			Entry entry;
			entry.playerName = tokens.at(0);
			entry.playerScore = tokens.at(1);
			this->_playerList.push_back(entry);
			tokens.clear();
		}
	}
	readFile.close();

	Entry entry;
	entry.playerName = " ";
	entry.playerScore = std::to_string(this->_score);
	if (this->_playerList.size() > 1)
	{
		for (int i = 0; i < this->_playerList.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (std::stoi(this->_playerList[j].playerScore) < std::stoi(this->_playerList[j + 1].playerScore))
				{
					std::string temp = this->_playerList[j].playerScore;
					this->_playerList[j].playerScore = this->_playerList[j + 1].playerScore;
					this->_playerList[j + 1].playerScore = temp;
				}
			}
		}
		for (std::vector<Entry>::iterator it = this->_playerList.begin(); it != this->_playerList.end(); it++)
		{
			if (std::stoi(it->playerScore) <= this->_score)
			{
				this->_playerList.insert(it, entry);
				break;
			}
		}
	}
	else
	{
		this->_playerList.push_back(entry);
	}

	this->_selected = 0; // gan _selected bang 0

	this->_font = new sf::Font(); // khoi tao _font la new sf::Font
	this->_font->loadFromFile("Graphics/font.ttf"); // load font tu file

	this->_playerlose = new sf::Text("Game Over", *this->_font, 95U); // khoi tao _player1win la new sf::Text
	// dat vi tri goc cua _player1win
	this->_playerlose->setOrigin(this->_playerlose->getGlobalBounds().width / 2, this->_playerlose->getGlobalBounds().height / 2);
	// dat vi tri cua _player1win
	this->_playerlose->setPosition(window->getSize().x / 2 + 10, window->getSize().y / 15);

	this->_playagain = new sf::Text("Play Again ?", *this->_font, 32U); // khoi tao _playagain la new sf::Text
	// dat vi tri goc cua _playeragain
	this->_playagain->setOrigin(this->_playagain->getGlobalBounds().width / 2, this->_playagain->getGlobalBounds().height / 2);
	// dat vi tri cua _playeragain
	this->_playagain->setPosition(window->getSize().x / 2 - this->_playagain->getGlobalBounds().width / 2, window->getSize().y / 1.2);

	this->_quit = new sf::Text("Quit", *this->_font, 32U); // khoi tao _quit la new sf::Text
	// dat vi tri goc cua _quit
	this->_quit->setOrigin(this->_quit->getGlobalBounds().width / 2, this->_quit->getGlobalBounds().height / 2);
	// dat vi tri cua _quit
	this->_quit->setPosition(window->getSize().x / 2 + 180, window->getSize().y / 1.2);

	this->_names = new sf::Text("Names", *this->_font, 30U);
	this->_names->setPosition(window->getSize().x / 2 - DEFAULT_X - 105, DEFAULT_Y - 20);

	this->_scores = new sf::Text("Scores", *this->_font, 30U);
	this->_scores->setPosition(window->getSize().x / 2 + DEFAULT_X + 20, DEFAULT_Y - 20);

	this->_scoreText = new sf::Text[NUM_OF_ROWS];
	this->_nameText = new sf::Text[NUM_OF_ROWS];

	int x = window->getSize().x / 2 - DEFAULT_X - 80;
	int y = DEFAULT_Y + 30;

	for (int i = 0; i < NUM_OF_ROWS && i < this->_playerList.size(); i++)
	{
		if (i != 0)
		{
			y += this->_nameText[i - 1].getGlobalBounds().height + 40;
		}
		this->_nameText[i].setFont(*this->_font);
		this->_nameText[i].setFillColor(sf::Color::White);
		this->_nameText[i].setCharacterSize(20);
		this->_nameText[i].setString(this->_playerList[i].playerName);
		this->_nameText[i].setPosition(x, y);
		this->_nameText[i].setOrigin(this->_scoreText[i].getGlobalBounds().width / 2, this->_scoreText[i].getGlobalBounds().height / 2);
		this->_scoreText[i].setFont(*this->_font);
		this->_scoreText[i].setCharacterSize(25);
		this->_scoreText[i].setFillColor(sf::Color::White);
		this->_scoreText[i].setString(this->_playerList[i].playerScore);
		this->_scoreText[i].setOrigin(this->_scoreText[i].getGlobalBounds().width / 2, this->_scoreText[i].getGlobalBounds().height / 2);
		this->_scoreText[i].setPosition(x + 350, this->_nameText[i].getPosition().y + 3);
	}

	this->_text1 = new Textbox(20, sf::Color::White, true);
	this->_text1->setPosition({ 100, 100 });
	this->_text1->setLimit(true, 5);
	this->_text1->setFont(*this->_font);

	this->_btn1 = new Button("Enter", { 70, 25 }, 15, sf::Color::White, sf::Color::Black);
	this->_btn1->setFont(*this->_font);
	this->_btn1->setPosition({ (float)(window->getSize().x / 2), (float)(window->getSize().y / 1.4) });
}

// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: cap nhat end_game
void end_game::Update(sf::RenderWindow* window)
{
	// neu mui ten len duoc bam' va mui ten len chua dc bam' truoc do
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !this->_isLeft) 
	{
		this->_selected -= 1; // giam _selected di 1
	}
	// neu mui ten xuong duoc bam' va mui ten xuong chua dc bam' truoc do
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !this->_isRight)
	{
		this->_selected += 1; // tang _selected len 1
	}
	if (this->_selected > 1) // neu _selected lon hon 1
	{
		this->_selected = 0; // gan _selected bang 0
	}
	if (this->_selected < 0) // neu _selected nho hon 0
	{
		this->_selected = 1; // gan _selected bang 1
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) // neu bam nut enter
	{
		switch (this->_selected)
		{
		case 0: // _selected = 0
			coreState.setState(new main_game()); // goi ham setState voi tham so new main_game
			break;
		case 1: // _selected = 1
			quitGame = true; // gan quitGame la true
			break;
		}
	}

	this->_isLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left); // gan _isUp bang true neu nut mui ten len duoc bam'
	this->_isRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right); // gan _isDown bang true neu nut mui ten xuong duoc bam'

	sf::Event Event;
	for (int i = 0; i < NUM_OF_ROWS && i < this->_playerList.size(); i++)
	{
		if (this->_nameText[i].getString() == " ")
		{
			this->_text1->setPosition({ this->_nameText[i].getPosition().x,this->_nameText[i].getPosition().y });
			this->_btn1->setPosition({ (float)this->_nameText[i].getPosition().x + 70,(float)this->_nameText[i].getPosition().y + 2 });
			while (window->pollEvent(Event))
			{
				switch (Event.type)
				{
				case sf::Event::TextEntered:
					this->_text1->typedOn(Event);
				case sf::Event::MouseMoved:
					if (this->_btn1->isMouseOver(*window)) {
						this->_btn1->setBackColor(sf::Color::Green);
					}
					else {
						this->_btn1->setBackColor(sf::Color::White);
					}
					break;
				case sf::Event::MouseButtonPressed:
					if (this->_btn1->isMouseOver(*window)) {
						this->_nameText[i].setString(this->_text1->getText());
						this->_playerList[i].playerName = this->_text1->getText();
					}
				}
			}
			this->_text1->drawTo(*window);
			this->_btn1->drawTo(*window);
		}
	}
	std::ofstream writeFile(SCORE_FILE_PATH);
	for (int i = 0; i < this->_playerList.size(); i++)
	{
		writeFile << this->_playerList[i].playerName << "," << this->_playerList[i].playerScore << std::endl;
	}
	writeFile.close();

}


// Input: tham so dang con tro RenderWindow
// Output:
// Chuc nang: ve nhung thu can co cua end_game
void end_game::Render(sf::RenderWindow* window)
{
	this->_playagain->setFillColor(sf::Color::White); // set _playagain mau` trang
	this->_quit->setFillColor(sf::Color::White); // set _quit mau` trang
	switch (this->_selected)
	{
	case 0: // truong hop _selected = 0
		this->_playagain->setFillColor(sf::Color::Green); // set _playagain mau` xanh la
		break;
	case 1: // truong hop _selected = 1
		this->_quit->setFillColor(sf::Color::Green); // set _quit mau` xanh la
		break;
	}
	window->draw(*this->_playagain); // ve _playagain ra window 
	window->draw(*this->_quit); // ve _quit ra window
	window->draw(*this->_playerlose); // ve _player1win ra window

	for (int i = 0; i < NUM_OF_ROWS && i < this->_playerList.size(); i++)
	{
		window->draw(this->_scoreText[i]);
		if (this->_nameText[i].getString() != " ")
		{
			window->draw(this->_nameText[i]);
		}
	}
	window->draw(*this->_names);
	window->draw(*this->_scores);
}
 
// Input: tham so dang con tro sf::RenderWindow
// Output:
// Chuc nang: giai phong bo nho
void end_game::Destroy(sf::RenderWindow* window)
{
	delete this->_font; // xoa _font
	delete this->_playagain; // xoa _playagain
	delete this->_quit; // xoa _quit
	delete this->_playerlose; // xoa _player1win
	delete[] this->_nameText;
	delete[] this->_scoreText;
	delete this->_text1;
	delete this->_btn1;
	delete this->_scores;
	delete this->_names;
}

// Input: tham so dang int
// Output: doi tuong end_game
// Chuc nang: khoi tao end_game
end_game::end_game(int score)
{
	this->_score = score; // gan _player la tham so player
}
