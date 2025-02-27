#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Animation.h"
#include "Player.h"

using namespace std;

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	sf::Clock clock;
	sf::View view;
	sf::Vector2f cameraCenter;
	sf::Vector2f previousPlayerPos;
	float lookAheadFactor = 0.5f;    // Adjust to control how far ahead the camera looks
	float cameraSmoothing = 5.0f;
	float cameraCursorFactor = 0.1f; 

private:
	Player player;
private:
	float deltaTime;
	unsigned int playerFrameRow = 6;
	sf::FloatRect playerBounds;
	sf::Vector2i playerPos;
	sf::Text text;
	sf::Font font;

public:
	Game();
	virtual ~Game();

	const bool isRunning() const;
	void updateEvents(float deltaTime);
	void update();
	void render();

private:
	void initWindow();
	void initVars();
	void initText();
	void keyBoardInput();
	float getAngle(float x1, float y1, float x2, float y2, bool radOrAngles);
};


