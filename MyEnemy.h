#ifndef MY_ENEMY_H_
#define MY_ENEMY_H_

#include "Actor.h"
#include <list>

enum State {
	Appear,
	First,
	Second,
	Third,
	FadeIn,
	FadeOut,
	Dead
};

class MyEnemy : public Actor {
public:
	MyEnemy(IWorld* world, const GSvector2& position);
	virtual void update(float delta_time) override;
	virtual void react(Actor& other) override;
	virtual void draw() const override;

private:
	void take_damage();

	int hp_{ 100 };
	int count_{ 0 };
	float timer_{ 0.0f };
	float theta_{ 0.0f };
	GSvector2 center_{ 64.0f, 64.0f };
	GScolor color_{ 1.0f, 1.0f, 1.0f, 1.0f };
	State state_{ Appear };
	std::list<Actor*> zako_actors_;
	float gameclear_timer_{ 150.0f };
};

#endif