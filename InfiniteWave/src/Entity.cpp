#include "Entity.h"

#include <iostream>

#include "Obstacle.h"

void Entity::checkCollision(Obstacle& obs, float deltaTime)
{
	const sf::FloatRect entityBounds = ColliderBody.getGlobalBounds();
	const sf::FloatRect obstacleBounds = obs.getCollider()->getGlobalBounds();

	sf::FloatRect nextPosition = entityBounds;
	nextPosition.left += velocity.x;
	nextPosition.top += velocity.y;

	if (obstacleBounds.intersects(nextPosition))
	{
		
		//TODO
		//Right
		//Bottom DONE
		if (entityBounds.top < obstacleBounds.top &&
			entityBounds.top + entityBounds.height < obstacleBounds.top + obstacleBounds.height &&
			entityBounds.left < obstacleBounds.left + obstacleBounds.width &&
			entityBounds.left + entityBounds.width > obstacleBounds.left)
		{
			std::cout << "Collided Bottom\n";
			velocity.y = 0.0f;
			entityRect.setPosition(entityRect.getPosition().x,entityRect.getPosition().y);
			ColliderBody.setPosition(entityRect.getPosition().x, entityRect.getPosition().y);
		}
		//Top
		else if (entityBounds.top > obstacleBounds.top &&
			entityBounds.top + entityBounds.height > obstacleBounds.top + obstacleBounds.height &&
			entityBounds.left < obstacleBounds.left + obstacleBounds.width &&
			entityBounds.left + entityBounds.width > obstacleBounds.left)
		{
			std::cout << "Collided Top\n";
			velocity.y = 0.0f;
			entityRect.setPosition(entityRect.getPosition().x,entityRect.getPosition().y);
			ColliderBody.setPosition(entityRect.getPosition().x, entityRect.getPosition().y);
		}
		//Right
		if (entityBounds.left < obstacleBounds.left &&
			entityBounds.top < obstacleBounds.top + obstacleBounds.height &&
			entityBounds.top + entityBounds.height > obstacleBounds.top)
		{
			std::cout << "Collided Right\n";
			velocity.x = 0.0f;
			entityRect.setPosition(entityRect.getPosition().x,entityRect.getPosition().y);
			ColliderBody.setPosition(entityRect.getPosition().x, entityRect.getPosition().y);
		}
		//Left
		else if (entityBounds.left > obstacleBounds.left &&
			entityBounds.top < obstacleBounds.top + obstacleBounds.height &&
			entityBounds.top + entityBounds.height > obstacleBounds.top)
		{
			std::cout << "Collided Left\n";
			velocity.x = 0.0f;
			entityRect.setPosition(entityRect.getPosition().x,entityRect.getPosition().y);
			ColliderBody.setPosition(entityRect.getPosition().x, entityRect.getPosition().y);
		}
	}
}

sf::RectangleShape* Entity::getDraw()
{
	return &entityRect;
}