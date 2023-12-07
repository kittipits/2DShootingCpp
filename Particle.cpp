#include "Particle.h"
#include "TextureID.h"

Particle::Particle(IWorld* world, const GSvector2& position, float angle, float speed){
	world_ = world;
	tag_ = "EffectTag";
	name_ = "Particle";
	position_ = position;
	velocity_ = GSvector2{ gsCos(angle), -gsSin(angle) } *speed;
	texture_ = TextureParticle;
}

void Particle::update(float delta_time){
	position_ += velocity_ * delta_time;
	velocity_.y += gravity_ * delta_time;
	angle_ += 8.0f * delta_time;
	color_.a -= 0.01f * delta_time;

	if (color_.a <= 0.0f) {
		die();
	}
}

void Particle::draw() const{
	gsDrawSprite2D(texture_, &position_, NULL, &center_, &color_, &scale_, angle_);
}
