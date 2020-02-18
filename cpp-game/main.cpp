#include <SFML/Graphics.hpp>
#include <list>
#include "gameSettings.h"
#include "physicsObject.h"




void Wupdate(std::list<physicsObject*>& objList)
{
	for (auto i = objList.begin(); i != objList.end(); i++) {
		(*i)->pUpdate();
	}
}

void Wdraw(std::list<physicsObject*> objList, sf::RenderWindow& window)
{
	for (auto i = objList.begin(); i != objList.end(); i++) {
		window.draw((*i)->getSprite());
	}
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "DEMO");
	window.setFramerateLimit(FRAME_LIMIT);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		sf::Sprite ball;
		sf::Texture ballTexture;
		ballTexture.loadFromFile("ball.png");
		ball.setTexture(ballTexture);
		ball.setScale(0.2, 0.2);

		std::list<physicsObject*> allObjects;
		physicsObject objectBall(allObjects, ball, 100, 100, 0, 10);


		Wupdate(allObjects);
		Wdraw(allObjects, window);
		window.display();
	}

	return 0;
}