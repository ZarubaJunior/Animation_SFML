#include "Game.h"

void Game::initWindow()
{
	this->videoMode.height = 900;
	this->videoMode.width = 1400;

	this->window = new sf::RenderWindow(this->videoMode, "Animation Program");
	this->window->setFramerateLimit(60);	

	this->view = sf::View(sf::FloatRect(0.f, 0.f, this->videoMode.width, this->videoMode.height));
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
	else
		player.movePlayer("still");
}

float Game::getAngle(float x1, float y1, float x2, float y2, bool radOrAngles) {
	float deltaX = x2 - x1;
	float deltaY = y2 - y1;

	float angleRadians = std::atan2(deltaY, deltaX);

	if (!radOrAngles) {
		float angleDegrees = angleRadians * (180.f / 3.141592657f);
		return angleDegrees;
	}
	else
		return angleRadians;
}


void Game::updateEvents(float deltaTime)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*this->window);
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

	sf::Vector2i mousePos = sf::Mouse::getPosition(*this->window);
	this->view.setCenter(player.playerSprite.getPosition());
	this->window->setView(this->view);

	sf::Vector2f currentPlayerPos = player.playerSprite.getPosition();
	sf::Vector2f windowCenter(videoMode.width / 2.f, videoMode.height / 2.f);
	sf::Vector2f mouseOffset = (sf::Vector2f(mousePos) - windowCenter) * cameraCursorFactor;
	sf::Vector2f targetCenter = currentPlayerPos + mouseOffset;
	cameraCenter += (targetCenter - cameraCenter) * cameraSmoothing * deltaTime;
	view.setCenter(cameraCenter);
	window->setView(view);

	player.update(2,3, mousePos.x, mousePos.y, deltaTime);
	
	keyBoardInput();
	previousPlayerPos = currentPlayerPos;
}

void Game::render()
{
	if (this->window) {
	//	this->window->clear(sf::Color(73, 102, 66)); 
		this->window->clear(sf::Color(79, 119, 189));

		this->window->draw(this->text);
		this->window->draw(player.playerRect);
		this->window->draw(player.playerSprite);
		
		this->window->display();
	}
}
