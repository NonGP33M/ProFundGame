#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

enum animationState {LEFT, RIGHT, TOP, DOWN};

class Player
{
private:
	sf::RectangleShape playerSprite;
	sf::RectangleShape playerHitBox;
	sf::Texture playerTexture;
	sf::IntRect currentFrame;
	sf::Vector2f knockBackDir;
	float movementSpeed = 2.f;
	int animStates = TOP;
	int animCount = 0;
	bool dead = false;
	bool isMoving = false;
	bool ableToMove = true;
	bool isAttacking = false;

	bool isKnockingBack = false;

	float knockBackSpeed = 5;
	float animationTimer = 0;
	float attackTimer = 0;

public:
	Player();
	inline const sf::FloatRect getBound() { return playerHitBox.getGlobalBounds(); }
	inline const sf::Vector2f getPos() { return playerHitBox.getPosition(); }
	inline const sf::Vector2u getSize() { return playerTexture.getSize(); }
	inline const int getPlayerState() { return animStates; }
	inline const bool movingCheck() { return isMoving; }
	inline const bool attackingCheck() { return isAttacking; }
	inline const bool deadCheck() { return dead; }
	inline const bool knockingBackCheck() { return isKnockingBack; }
	inline void animationReset() { animStates = TOP; }
	inline void isDead() { dead = true; currentFrame.left = 0; }
	inline void setMoving(bool set) { ableToMove = set; animCount = 0; }
	inline void attacking() { isAttacking = true; attackTimer = 0; }
	void knockback(sf::Vector2f knockBackDir);
	void timeTicking(float deltatime);
	void knockBackUpdate();
	void movement();
	void animation();
	void attack();
	void update();
	void render(sf::RenderTarget& other);
	void reset();
};

