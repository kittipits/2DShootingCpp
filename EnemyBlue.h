#ifndef ENEMY_BLUE_H_
#define ENEMY_BLUE_H_

#include "Actor.h"

class EnemyBlue : public Actor {
public:
	EnemyBlue(IWorld* world, const GSvector2& position);
	virtual void update(float delta_time) override;
	virtual void react(Actor& other) override;

private:
	float timer_{ 0.0f };
};

#endif
