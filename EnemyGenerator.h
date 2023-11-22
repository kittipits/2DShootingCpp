#ifndef ENEMY_GENERATOR_H_
#define ENEMY_GENERATOR_H_

#include "Actor.h"

class EnemyGenerator : public Actor {
public :
	EnemyGenerator(IWorld* world);
	virtual void update(float delt_time) override;
	virtual void draw() const override;

private:
	float timer_{ 0.0f };
	float count_{ 0.0f };
};

#endif