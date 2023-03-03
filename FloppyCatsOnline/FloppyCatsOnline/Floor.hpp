#include "GameObject.hpp"
#include "Collidable.hpp"
#include <SFML/Graphics.hpp>

#ifndef _floor_hpp
#define _floor_hpp

class Floor : public GameObject, public Collidable<float> {
private:
	Sprite sprite_;
public:
	Floor();
	virtual const float& getCollider() override;
	virtual void draw(RenderTarget& target, RenderStates states) const override;
};

#endif // !_floor_hpp