#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "Actor.h"

class Particle : public Actor {
public:
	Particle(IWorld* world, const GSvector2& position, float angle, float speed);
	virtual void update(float delta_time) override;
	virtual void draw() const override;

private:
	GScolor color_{ 1.0f, 1.0f, 1.0f, 1.0f };
	GSvector2 center_{ 16.0f, 16.0f };
	GSvector2 scale_{ 1.0f, 1.0f };
	float gravity_{ 0.1f };
};

#endif
