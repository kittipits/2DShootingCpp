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
	if (color_.a <= 0.0f){
		die();
	}

	color_.a -= 0.02f * delta_time;
	angle_ += 8.0f * delta_time;
	scale_ += GSvector2{ 0.05f, 0.05f } *delta_time;
}

void Explosion::draw() const
{
	gsDrawSprite2D(texture_, &position_, NULL, &center_, &color_, &scale_, angle_);
}
