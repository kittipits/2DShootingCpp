#include "EnemyBlue.h"
#include "IWorld.h"
#include "Field.h"
#include "EnemyBeam.h"
#include "TextureID.h"
#include "Explosion.h"
#include "SoundID.h"
#include "Particle.h"

EnemyBlue::EnemyBlue(IWorld* world, const GSvector2& position){
	world_ = world;
	tag_ = "EnemyTag";
	name_ = "EnemyBlue";
	position_ = position;
	velocity_ = GSvector2{ -1.0f, -1.5f };
	collider_ = BoundingRectangle{ 0.0f,0.0f,32.0f,32.0f };
	texture_ = TextureEnemyBlue;
}

void EnemyBlue::update(float delta_time){
	float area_bottom = world_->field().area().max().y - collider_.max().y;
	position_ += velocity_ * delta_time;
	position_.y = CLAMP(position_.y, 0.0f, area_bottom);

	if (position_.y <= 0.0f || position_.y >= area_bottom){ 
		velocity_.y = -velocity_.y;
	}

	timer_ += delta_time;
	if (timer_ > 90.0f) {
		GSvector2 velocity = GSvector2(-1.0f, 0.0f) * 4.0f;
		world_->add_actor(new EnemyBeam{ world_, position_, velocity });
		timer_ = 0.0f;
	}

	if (world_->field().is_outside(collider())) {
		die();
	}
}

void EnemyBlue::react(Actor& other){
	if (other.tag() == "PlayerTag" || other.tag() == "PlayerBulletTag") {
		die();
		world_->add_actor(new Explosion{ world_, position_ });
		for (int i = 0; i < 20; ++i) {
			world_->add_actor(new Particle{ world_, position_, gsRandf(0.0f, 360.0f), gsRandf(1.0f, 3.0f) });
		}

		gsPlaySE(Se_ExplosionPlayer);
		world_->add_score(100);
	}
}
