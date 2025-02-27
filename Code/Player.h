#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:
	Player();
	~Player();

	void init(float x, float y, float sizeX, float sizeY);
	void update(float x, float y, float mouseX, float mouseY, float deltaTime);
	void movePlayer(std::string keyboardInput);
	sf::Vector2i returnPosition();
	void animationSelection(std::string name);
	float getAngle(float x1, float y1, float x2, float y2, bool radOrAngles);
private:
	// VARIABLES
public:
	sf::Sprite playerSprite;
	sf::RectangleShape playerRect;
	bool isPlayerMoving = false;
private:	
	Animation animation;	
	std::vector<float> playerVelocity = { 500, 500, 500, 500 };
	sf::Vector2f playerPos;
	sf::Vector2u playerSize;
	sf::Texture playerTexture;
	float playerScaleX, playerScaleY;
	sf::Vector2u playerSpriteSize;
	float deltaTime;
	unsigned int playerFrameRow = 6;
	float playerSpeed = 500.f;
	int animRow;
	
};

