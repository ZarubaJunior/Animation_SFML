#include "Game.h"

void Game::initWindow()
{
	this->videoMode.height = 900;
	this->videoMode.width = 1400;

	this->window = new sf::RenderWindow(this->videoMode, "Animation Program");
	this->window->setFramerateLimit(60);	
}

void Game::initVars() {this->window = nullptr;}

void Game::initText()
{
	if (!font.loadFromFile("Minecraft.ttf"))
		std::cout << "TEXTURE ERROR \n";

	text.setFont(font);
	text.setString("Animation Program \nby Rincewind");
	text.setCharacterSize(40);
	sf::FloatRect textBounds = text.getLocalBounds();
	text.setPosition(videoMode.width - textBounds.width -50, videoMode.height - textBounds.height - 50);
	text.setFillColor(sf::Color(112, 158, 101));
	text.setStyle(sf::Text::Bold);
}

Game::Game()
{
	player.init(200, 200, 100, 100 );
	this->initVars();
	this->initWindow();
	this->initText();
}

Game::~Game() {delete this->window;}

const bool Game::isRunning() const{return this->window && this->window->isOpen();}

void Game::keyBoardInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))		 // Move Up and Right
		player.movePlayer("wd");
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Move Down and Right
		player.movePlayer("sd");
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // Move Up and Left
		player.movePlayer("wa");
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // Move Down and Left
		player.movePlayer("sa");
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))												 // Move Up
		player.movePlayer("w"); 
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))												 // Move Down
		player.movePlayer("s");
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))												 // Move Right
		player.movePlayer("d");
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))												 // Move Left
		player.movePlayer("a");
}

void Game::updateEvents(float deltaTime)
{
	while (this->window && this->window->pollEvent(this->ev)) {
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}
void Game::update()
{
	deltaTime = clock.restart().asSeconds();
	this->updateEvents(deltaTime);
	
	player.update(2,3, deltaTime);

	keyBoardInput();
}

void Game::render()
{
	if (this->window) {
		this->window->clear(sf::Color(73, 102, 66));

		this->window->draw(this->text);
		this->window->draw(player.playerRect);
		this->window->draw(player.playerSprite);
		
		this->window->display();
	}
}
