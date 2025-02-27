#include "Player.h"

Player::Player() {Animation animation;}

Player::~Player(){}

void Player::init(float x, float y, float sizeX, float sizeY) 
{
	this->playerPos.x = x;
	this->playerPos.y = y;

	this->playerSize.x = sizeX;
	this->playerSize.y = sizeY;

	this->playerRect.setSize(sf::Vector2f(playerSize.x, playerSize.y));
	this->playerRect.setFillColor(sf::Color(0, 0, 0, 100));
	this->playerRect.setPosition(sf::Vector2f(playerPos.x, playerPos.y));

	if (!playerTexture.loadFromFile("Res/Textures/wizard.png"))
		std::cout << "TEXTURE ERROR \n";

	this->playerSprite.setPosition(sf::Vector2f(playerPos.x, playerPos.y));
	this->playerSprite.setTexture(playerTexture);

	playerScaleX = 3; playerScaleY = 3;
	this->playerSprite.setScale(playerScaleX, playerScaleY);

	sf::Vector2f spriteSize(playerSprite.getGlobalBounds().width, playerSprite.getGlobalBounds().height);
	playerSprite.setOrigin(playerSize.x / 2.f, playerSize.y / 2.f);

	playerRect.setOrigin(playerSize.x / 2.f, playerSize.y / 2.f);

	std::cout << "\n PLAYER TEXTURE SIZE X: " << playerTexture.getSize().x << " PLAYER TEXTURE SIZE Y: " << playerTexture.getSize().y;
	std::cout << "\n PLAYER SPRITE SIZE X: " << playerSprite.getScale().x << " PLAYER TEXTURE Y: " << playerSprite.getScale().y;

	animRow = 0;
	animation.initAnimation(&playerTexture, sf::Vector2u(8, 7), 0.2f);

	std::cout << "Works";
}

void Player::update(float x, float y, float mouseX, float mouseY, float deltaTime )
{
	this->playerRect.setPosition(playerPos.x, playerPos.y);
	this->playerSprite.setPosition(playerPos.x, playerPos.y);
	
	this->deltaTime = deltaTime;

	this->animation.update(animRow, isPlayerMoving, deltaTime);
		this->playerSprite.setTextureRect(animation.uvRect);	

	float anglePlayer = getAngle(x, y, mouseX, mouseY, false);

	playerRect.setRotation(anglePlayer);
}

void Player::movePlayer(std::string keyboardInput)
{
	if (keyboardInput == "wd") {
		playerPos.x += playerSpeed * this->deltaTime;
		playerPos.y -= playerSpeed * this->deltaTime;
		this->playerSprite.setScale(playerScaleX, playerScaleY);
		animationSelection("diagonalUp");
	}
	else if (keyboardInput == "wa") {
		playerPos.x -= playerSpeed * this->deltaTime;
		playerPos.y -= playerSpeed * this->deltaTime;
		this->playerSprite.setScale(-playerScaleX, playerScaleY);
		animationSelection("diagonalUp");
	}
	else if (keyboardInput == "sd") {
		playerPos.x += playerSpeed * this->deltaTime;
		playerPos.y += playerSpeed * this->deltaTime;
		this->playerSprite.setScale(playerScaleX, playerScaleY);
		animationSelection("diagonalDown");
	}
	else if (keyboardInput == "sa") {
		playerPos.x -= playerSpeed * this->deltaTime;
		playerPos.y += playerSpeed * this->deltaTime;
		this->playerSprite.setScale(-playerScaleX, playerScaleY);
		animationSelection("diagonalDown");
	}
	else if (keyboardInput == "w") {
		playerPos.y -= playerSpeed * this->deltaTime;
		animationSelection("up");
	}
	else if (keyboardInput == "s") {
		playerPos.y += playerSpeed * this->deltaTime;
		animationSelection("down");
	}
	else if (keyboardInput == "d") {
		playerPos.x += playerSpeed * this->deltaTime;
		this->playerSprite.setScale(playerScaleX, playerScaleY);
		animationSelection("horizontal");
	}
	else if (keyboardInput == "a") {
		playerPos.x -= playerSpeed * this->deltaTime;
		this->playerSprite.setScale(-playerScaleX, playerScaleY);
		animationSelection("horizontal");
	}

	if (keyboardInput != "still") {
		isPlayerMoving = true;
	}
	else
		isPlayerMoving = false;
}

sf::Vector2i Player::returnPosition() {return sf::Vector2i(this->playerPos.x, this->playerPos.y);}

void Player::animationSelection(std::string name)
{
	if (name == "horizontal") {
		animRow = 0;
	}
	else if (name == "down") {
		animRow = 1;
	}
	else if (name == "diagonalUp") {
		animRow = 2;
	}
	else if (name == "up") {
		animRow = 3;	
	}
	else if (name == "diagonalDown") {
		animRow = 4;
	}
}

float Player::getAngle(float x1, float y1, float x2, float y2, bool radOrAngles)
{
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
