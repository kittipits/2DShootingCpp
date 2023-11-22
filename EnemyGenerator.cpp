#include "EnemyGenerator.h"
#include "IWorld.h"
#include "Field.h"
#include "Enemy.h"
#include "EnemyBlue.h"
#include "MyEnemy.h"

EnemyGenerator::EnemyGenerator(IWorld* world){
	world_ = world;
	tag_ = "Generator";
	name_ = "EnemyGenerator";
	timer_ = 0.0f;
	enable_collider_ = false;
}

void EnemyGenerator::update(float delta_time){
	if (timer_ < 0.0f && count_ <= 100) {
		GSvector2 position{
		world_->field().area().max().x + 32.0f,
		gsRandf(0.0f, world_->field().area().max().y - 32.0f)};

		Actor* enemy = new Enemy{ world_, position };

		if (count_ >= 100) enemy = new MyEnemy{ world_, GSvector2{world_->field().area().max().x, 200.0f} };
		else if (count_ >= 50) enemy = new EnemyBlue{ world_, position };

		world_->add_actor(enemy);
		timer_ = gsRandf(30.0f, 60.0f);
		count_++;
	}
	timer_ -= delta_time;
}

void EnemyGenerator::draw() const{
}
