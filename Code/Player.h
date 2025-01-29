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
	void update(float x, float y, float deltaTime);
	void movePlayer(std::string keyboardInput);
	sf::Vector2i returnPosition();
	void animationSelection(std::string name);
private:
	// VARIABLES
public:
	sf::Sprite playerSprite;
	sf::RectangleShape playerRect;
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

