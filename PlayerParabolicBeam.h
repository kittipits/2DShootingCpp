#ifndef PLAYER_PARABOLIC_BEAM_H_
#define PLAYER_PARABOLIC_BEAM_H_

#include "Actor.h"

class PlayerParabolicBeam : public Actor {
public:
	PlayerParabolicBeam(IWorld* world, const GSvector2& position, const GSvector2& velocity);
	virtual void update(float delta_time) override;
	virtual void react(Actor& other) override;

private:
	float gravity_{ 0.1f };
};


#endif
