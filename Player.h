#ifndef PLAYER_H_
#define PLAYER_H_

#include "Actor.h"

// プレーヤークラス
class Player : public Actor {
public:
	Player(IWorld* world, const GSvector2& position);
	virtual void update(float delta_time) override;
	virtual void react(Actor& other) override;
	virtual void draw() const override;

private:
	void take_damage();

	float timer_{ 0.0f };
	float invul_timer_{ 120.0f };
	float gameover_timer_{ 150.0f };
	bool flip_{ false };
	GScolor color_{ 1.0f, 1.0f, 1.0f, 1.0f };
	bool is_invulnurable{ false };
	bool is_movable{ true };
	bool is_exploded{ false };
};

#endif
