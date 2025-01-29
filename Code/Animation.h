#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
class Animation
{
public:
	Animation();
	~Animation();
	void initAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

	void update(int row, float deltaTime);
public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

