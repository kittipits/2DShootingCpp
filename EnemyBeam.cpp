#include "EnemyBeam.h"
#include "IWorld.h"
#include "Field.h"
#include "TextureID.h"

EnemyBeam::EnemyBeam(IWorld* world, const GSvector2& position, const GSvector2& velocity){
	world_ = world;
	tag_ = "EnemyBulletTag";
	name_ = "EnemyBeam";
	position_ = position;
	velocity_ = velocity;
	collider_ = BoundingRectangle{ 0.0f, 0.0f, 16.0f, 16.0f };
	texture_ = TextureEnemyBeam;

}

void EnemyBeam::update(float delta_time){
	position_ += velocity_ * delta_time;
	if (world_->field().is_outside(collider())) {
		die();
	}
}

void EnemyBeam::react(Actor& other){
	if (other.tag() == "PlayerTag") {
		die();
	}
}
