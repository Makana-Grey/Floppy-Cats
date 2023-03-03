#include "Game.hpp"
#include "Floor.hpp"
#include "definitions.hpp"

Floor::Floor() {
	sprite_.setTexture(Game::getSpriteList());
	sprite_.setTextureRect(IntRect(FLOOR_X, FLOOR_Y, FLOOR_WIDTH, FLOOR_HEIGHT));

	float factor_y = Game::height / FLOOR_SIDE_PART / FLOOR_HEIGHT;

	sprite_.setScale(1. * Game::width / FLOOR_WIDTH, factor_y);
	sprite_.setPosition(0, Game::height - factor_y * FLOOR_HEIGHT);
}

const float& Floor::getCollider() {
	return sprite_.getPosition().y;
}


void Floor::draw(RenderTarget& target, RenderStates states) const {
	target.draw(sprite_, states);
}