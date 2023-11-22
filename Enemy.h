#ifndef ENEMY_H_
#define ENEMY_H_

#include "Actor.h"

// “GƒNƒ‰ƒX
class Enemy : public Actor {
public:
	Enemy(IWorld* world, const GSvector2& position);
	virtual void update(float delta_time) override;
	virtual void react(Actor& other) override;

private:
	float timer_{ 0.0f };
};

#endif
