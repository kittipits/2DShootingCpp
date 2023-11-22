#include "PlayerParabolicBeam.h"
#include "IWorld.h"
#include "Field.h"
#include "TextureID.h"

PlayerParabolicBeam::PlayerParabolicBeam(IWorld* world, const GSvector2& position, const GSvector2& velocity){
	world_ = world;
	tag_ = "PlayerBulletTag";
	name_ = "PlayerParabolicBeam";
	position_ = position;
	velocity_ = velocity;
	collider_ = BoundingRectangle{ 0.0f, 0.0f, 16.0f, 8.0f };
	texture_ = TexturePlayerBeam;
}

void PlayerParabolicBeam::update(float delta_time){
	gravity_ *= 1.1f;
	velocity_.y += gravity_;

	position_ += velocity_ * delta_time;


	if (world_->field().is_outside(collider())) {
		die();
	}

}

void PlayerParabolicBeam::react(Actor& other){
	if (other.tag() == "EnemyTag") {
		die();
	}
}
