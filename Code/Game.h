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
};


