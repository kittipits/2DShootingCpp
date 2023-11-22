#ifndef PLAYER_BEAM_H_
#define PLAYER_BEAM_H_

#include "Actor.h"

// ÉvÉåÅ[ÉÑÅ[íe
class PlayerBeam : public Actor {
public:
	PlayerBeam(IWorld* world, const GSvector2& position, const GSvector2& velocity);
	virtual void update(float delta_time) override;
	virtual void react(Actor& other) override;
};


#endif
