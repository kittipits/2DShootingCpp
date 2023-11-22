#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include "Actor.h"

// ”š”­ƒNƒ‰ƒX
class Explosion : public Actor {
public:
	Explosion(IWorld* world, const GSvector2& position);
	virtual void update(float delta_time) override;
	virtual void draw() const;

private:
	float timer_{ 0.0f };
	GScolor color_{ 1.0f, 1.0f, 1.0f, 1.0f };
};

#endif
