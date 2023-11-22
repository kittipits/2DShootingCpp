#ifndef ENEMY_BEAM_H_
#define ENEMY_BEAM_H_

#include "Actor.h"

// “G’eƒNƒ‰ƒX
class EnemyBeam : public Actor {
public: 
	EnemyBeam(IWorld* world, const GSvector2& position, const GSvector2& velocity);
	virtual void update(float delta_time) override;
	virtual void react(Actor& other) override;
};


#endif