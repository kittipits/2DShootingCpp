#include "Explosion.h"
#include "TextureID.h"

Explosion::Explosion(IWorld* world, const GSvector2& position){
	world_ = world;
	name_ = "Explosion";
	tag_ = "EffectTag";
	position_ = position;
	enable_collider_ = false;
	texture_ = TextureBomb;
}

void Explosion::update(float delta_time){
	if (timer_ > 30.0f) {
		color_.a -= delta_time / 45;
	}
	timer_ += delta_time;
	
	if (color_.a <= 0.0f){
		die();
	}
}

void Explosion::draw() const
{
	gsDrawSprite2D(texture_, &position_, NULL, NULL, &color_, NULL, angle_);
}
