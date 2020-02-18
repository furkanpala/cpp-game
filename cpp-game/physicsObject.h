#ifndef PHYSICS_OBJECT_HPP
#define PHYSICS_OBJECT_HPP
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "gameSettings.h"
class physicsObject
{
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f velocity;

	public:
		physicsObject(std::list<physicsObject*>& objList, sf::Sprite& s, float x = DEFAULT_POS_X, float y = DEFAULT_POS_Y, float vx = DEFAULT_SPAWN_SPEED_X, float vy = DEFAULT_SPAWN_SPEED_Y) {	
			sprite = s;
			position.x = x; 
			position.y = y;
			velocity.x = vx;
			velocity.y = vy;
			objList.push_back(this);
		}

		sf::Sprite getSprite() {
			return sprite;
		}

		void pUpdate() {
			velocity.y += GRAVITY;
			position += velocity;
			std::cout << "vel: " << velocity.x << " " << velocity.y << std::endl;
			std::cout << "pos: " << position.x << " " << position.y << std::endl;
		}

};
#endif
