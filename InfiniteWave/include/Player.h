#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Animation.h"
#include "Entity.h"

enum status { IDLE_ANIM = 0, WALK_ANIM = 1, SHOOT_ANIM = 2};

class Player : public Entity
{
public:
	Player();

	void Update(float deltaTime);
	void lookAt(sf::Vector2f mousePos);

	//In-game function
	void Move(sf::Vector2i dir, float deltaTime) override;
	void PlayerMove();
	void Reload();
	void Shoot();
	
	sf::Vector2f getPosition() const;
	
private:
	unsigned short int status{};
	unsigned short int holdAmmo = 18;

	sf::RectangleShape& playerRect;
	sf::Texture idleBodyTex;
	sf::Texture walkBodyTex;
	sf::Texture shootBodyTex;
	sf::Texture reloadBodyTex;
	
	sf::Texture idleFootTex;
	sf::Texture walkFootTex;
	sf::Texture shootFootTex;
	sf::Texture reloadFootTex;
};
