#include "Player.h"
#include "IWorld.h"
#include "Field.h"
#include "PlayerBeam.h"
#include "PlayerParabolicBeam.h"
#include "TextureID.h"
#include "Explosion.h"
#include "PlayerHitPoint.h"

Player::Player(IWorld* world, const GSvector2& position) {
	world_ = world;
	tag_ = "PlayerTag";
	name_ = "Player";
	position_ = position;
	collider_ = BoundingRectangle{ 0.0f,0.0f,64.0f,40.0f };
	texture_ = TexturePlayer;
}

void Player::update(float delta_time) {
	GSvector2 direction{ 0.0f, 0.0f };
	if (gsGetKeyState(GKEY_LEFT) && is_movable) {
		direction.x = -1.0f;
	}
	if (gsGetKeyState(GKEY_RIGHT) && is_movable) {
		direction.x = 1.0f;
	}
	if (gsGetKeyState(GKEY_UP) && is_movable) {
		direction.y = -1.0f;
	}
	if (gsGetKeyState(GKEY_DOWN) && is_movable) {
		direction.y = 1.0f;
	}

	float speed = 8.0f;
	velocity_ = direction.normalized() * speed;
	position_ += velocity_ * delta_time;

	// 画面外に移動できないように制限する
	const BoundingRectangle& area = world_->field().area();
	position_ = position_.clamp(area.min(), area.max() - collider_.max());

	// 発射の処理
	timer_ += delta_time;
	if (timer_ >= 5.0f){
		timer_ = 0;
	}

	if (gsGetKeyState(GKEY_LCONTROL)){
		flip_ = true;
	}
	else{
		flip_ = false;
	}

	float bullet_direction;
	GSvector2 shoot_position;
	
	if (flip_){
		bullet_direction = -1.0f;
		shoot_position = GSvector2{ -2.0f, 25.0f };
	}
	else{
		bullet_direction = 1.0f;
		shoot_position = GSvector2{ 50.0f, 25.0f };
	}

	if (gsGetKeyTrigger(GKEY_SPACE) || gsGetKeyTrigger(GKEY_Z) || gsGetKeyTrigger(GKEY_X)) {
		timer_ = 0;
	}

	if (gsGetKeyState(GKEY_SPACE) && timer_ == 0 && is_movable) {
		world_->add_actor(new PlayerBeam{ world_, position_ + shoot_position, GSvector2{bullet_direction * 8.0f, 0.0f} });
		world_->add_actor(new PlayerParabolicBeam{ world_, position_ + shoot_position, GSvector2{bullet_direction * 8.0f, -8.0f} });
	}

	if (gsGetKeyState(GKEY_Z) && timer_ == 0 && is_movable){
		world_->add_actor(new PlayerParabolicBeam{ world_, position_ + shoot_position, GSvector2{bullet_direction * 8.0f, -8.0f} });
		
	}

	if (gsGetKeyState(GKEY_X) && timer_ == 0 && is_movable){
		world_->add_actor(new PlayerBeam{ world_, position_ + shoot_position, GSvector2{bullet_direction * 8.0f, 0.0f} });
	}

	if (is_invulnurable) {
		invul_timer_ -= delta_time;
		color_.g -= delta_time / 30;
		color_.b -= delta_time / 30;
		if (color_.g <= 0.0f) color_.g = 0.5f;
		if (color_.b <= 0.0f) color_.b = 0.5f;
		color_.a -= delta_time / 60;
		if (color_.a <= 0.5f) color_.a = 0.75f;

		if (invul_timer_ < 0.0f){
			invul_timer_ = 120.0f;
			is_invulnurable = false;
		}
	}
	else {
		color_ = GScolor{ 1.0f,1.0f,1.0f,1.0f };
	}

	if (world_->player_hp().get() <= 0) {
		is_movable = false;
		color_ = GScolor{ 0.0f,0.0f,0.0f,0.0f };
		gameover_timer_ -= delta_time;
	}

	if (gameover_timer_ < 0) {
		die();
		world_->game_over();
	}
}

void Player::react(Actor& other) {
	if ((other.tag() == "EnemyTag" || other.tag() == "EnemyBulletTag") && !is_invulnurable) {
		//爆発エフェクトを生成
		//world_->add_actor(new Explosion{ world_, position_ });
		// HP減算
		world_->player_hp().sub(1);

		// HPが尽きたら
		//if (world_->player_hp().get() <= 0) {
			// 死亡状態にする
			//die();
			// ゲームオーバーの通知をする
			//world_->game_over();
		//}
		is_invulnurable = true;
	}
}

void Player::draw() const
{
	GSrect rect;
	if (flip_){
		rect = GSrect{ 64.0f, 0.0f, 0.0f, 64.0f };
	}
	else {
		rect = GSrect{ 0.0f, 0.0f, 64.0f, 64.0f };
	}

	gsDrawSprite2D(texture_, &position_, &rect, NULL, &color_, NULL, angle_);

	//HPバー


	//GSrect hp_rect{ 264.0f, 0.0f, 264.0f + world_->player_hp().get(_ * 8.0f, 16.0f };
	//GScolor hp_color{ 1.0f, 0.2f, 0.2f, 0.8f };
	//gsDrawRectangle2D(&hp_rect, &hp_color);
}
