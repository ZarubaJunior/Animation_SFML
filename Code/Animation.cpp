#include "Animation.h"

Animation::Animation()
{

}

Animation::~Animation()
{
}

void Animation::initAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

void Animation::update(int row, bool playerMoving, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;
	if (totalTime >= switchTime && playerMoving == true) {
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)
			currentImage.x = 0;
	}
	if (playerMoving == false)
		currentImage.x = 0;

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}
