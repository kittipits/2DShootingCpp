#include "MyEnemy.h"
#include "IWorld.h"
#include "Field.h"
#include "EnemyBeam.h"
#include "Enemy.h"
#include "EnemyBlue.h"
#include "TextureID.h"
#include "Explosion.h"
#include "SoundID.h"

#include <Math.h>		//�O�p�֐� (sin cos)

//�R���X�g���N�^
MyEnemy::MyEnemy(IWorld* world, const GSvector2& position){
	world_ = world;
	tag_ = "EnemyTag";
	name_ = "MyEnemy";
	position_ = position;
	velocity_ = GSvector2{ -1.0f, 0.0f };
	collider_ = BoundingRectangle{ -36.0f,-36.0f,36.0f,36.0f };
	texture_ = TextureBoss;
}

//�X�V
void MyEnemy::update(float delta_time){
	Actor* player = world_->find_actor("Player");	//�v���[���[��T��
	angle_ += delta_time;		//�`��p�̊p�x�����炷
	timer_ -= delta_time;		//�^�C�}�[�����炷

	const BoundingRectangle& area = world_->field().area();		//�G���A���̔���
	float left = position_.x + collider_.min().x;				//���@�̍��[
	float right = position_.x + collider_.max().x;				//���@�̉E�[
	float top = position_.y + collider_.min().y;				//���@�̏�[
	float bottom = position_.y + collider_.max().y;				//���@�̉��[

	//�o��
	if (state_ == Appear){
		position_ += velocity_ * delta_time;

		//���ɐi��ŁA���1�J�n
		if (position_.x <= 500.0f){
			state_ = First;
			velocity_ = GSvector2{ -2.5f, -2.5f };
			timer_ = 120;
		}
	}

	//���1
	else if (state_ == First){
		//�ړ�
		position_ = position_.clamp(area.min() - collider_.min(), area.max() - collider_.max());
		if (left <= area.min().x || right >= area.max().x){
			velocity_.x = -velocity_.x;
		}
		if (top <= area.min().y || bottom >= area.max().y){
			velocity_.y = -velocity_.y;
		}
		position_ += velocity_ * delta_time;

		//����
		if (timer_ < 0) {
			timer_ = 120;
			count_ = 0;
		}
		if (timer_ >= 50) {
			count_++;
		}
		count_ = CLAMP(count_, 5, 55);

		if (player != nullptr && count_ % 10 == 0) {
			GSvector2 velocity = (player->position() - position_).normalized() * (6.5f - count_ / 20);
			world_->add_actor(new EnemyBeam{ world_, position_, velocity });
		}

		//HP��50�ɂȂ�����A���1�I��
		if (hp_ <= 50) {
			state_ = FadeOut;
			velocity_ = GSvector2{ 0.0f, 0.0f };
			count_ = 0;
			tag_ = "Invulnerable";
		}
	}

	//�����ɂȂ�܂Ńt�F�[�h�A�E�g
	else if (state_ == FadeOut)
	{
		color_.a -= delta_time / 100;

		if (color_.a <= 0.0f) {
			state_ = Second;
			color_.a = 0.0f;
		}
	}

	//���2
	else if (state_ == Second){
		//���@�������Ȃ����A�U�R�𐶐�����
		if (timer_ < 0.0f) {
			GSvector2 position{
			world_->field().area().max().x + 32.0f,
			gsRandf(0.0f, world_->field().area().max().y - 32.0f) };

			int number = gsRand(0, 1);
			Actor* zako_add;
			switch (number) {
				case 0: zako_add = new Enemy{ world_, position };		break;
				case 1: zako_add = new EnemyBlue{ world_, position };	break;
			}
			zako_actors_.push_back(zako_add);
			world_->add_actor(zako_add);
			timer_ = gsRandf(15.0f, 30.0f);
		}

		//�U�R�����񂾂�J�E���g�𑝂₵�āA�폜����
		for (auto zako = zako_actors_.begin(); zako != zako_actors_.end();) {
			if ((*zako)->is_dead()) {
				count_++;
				zako = zako_actors_.erase(zako);
			}
			else {
				++zako;
			}
		}

		//�U�R��30�̓|������A���2�I��
		if (count_ >= 30){
			state_ = FadeIn;
			position_ = GSvector2{ 500.0f, 200.0f };
		}
	}

	//�s�����ɂȂ�܂Ńt�F�[�h�C��
	else if (state_ == FadeIn) {
		color_.a += delta_time / 100;

		if (color_.a >= 1.0f) {
			state_ = Third;
			velocity_ = GSvector2{ -2.5f, -2.5f };
			tag_ = "EnemyTag";
			timer_ = 120;
			color_.a = 1.0f;
		}
	}

	//���3
	else if (state_ == Third){
		//�ړ�
		theta_ += 0.05f * delta_time;

		position_ = position_.clamp(area.min() - collider_.min(), area.max() - collider_.max());
		if (left <= area.min().x || right >= area.max().x){
			velocity_.x = -velocity_.x;
		}
		else{
			float rand_velocity_x = (gsRandf(cos(theta_) / 12, cos(theta_) / 6));
			velocity_.x = velocity_.x + rand_velocity_x;
		}
		if (top <= area.min().y || bottom >= area.max().y){
			velocity_.y = -velocity_.y;
		}
		else{
			float rand_velocity_y = (gsRandf(sin(theta_) / 12, sin(theta_) / 6));
			velocity_.y = velocity_.y + rand_velocity_y;
		}

		velocity_ = velocity_.clamp(GSvector2{ -5,-5 }, GSvector2{ 5,5 });
		position_ += velocity_ * delta_time;

		//����
		if (timer_ < 0) {
			timer_ = 120;
			count_ = 0;
		}
		if (timer_ >= 50) {
			count_++;
		}
		count_ = CLAMP(count_, 5, 55);

		if (player != nullptr && count_ % 6 == 0) {
			float rand_pos_x = gsRandf(player->position().x, player->position().x + 32.0f);
			float rand_pos_y = gsRandf(player->position().y, player->position().y + 32.0f);
			GSvector2 rand_pos{ rand_pos_x, rand_pos_y };
			float speed = gsRandf(4.0f, 6.0f);
			GSvector2 velocity = ( rand_pos - position_).normalized() * speed;
			world_->add_actor(new EnemyBeam{ world_, position_, velocity });
		}

		//HP��0�ɂȂ�����A���S
		if (hp_ <= 0) {
			state_ = Dead;
			velocity_ = GSvector2{ 0.0f, 0.0f };
			timer_ = 120;
			count_ = 0;
			world_->add_score(1000);
		}
	}

	//���S
	else if (state_ == Dead){
		//����
		color_.a -= delta_time / 200;
		if (timer_ > 0) count_++;
		float explosion_x = gsRandf(position_.x - 64.0f, position_.x);
		float explosion_y = gsRandf(position_.y - 64.0f, position_.y);
		GSvector2 explosion_pos{ explosion_x, explosion_y };
		if (count_ % 6 == 0) {
			world_->add_actor(new Explosion{ world_, explosion_pos });
			gsPlaySE(Se_ExplosionPlayer);
		}
		count_ = CLAMP(count_, 1, 121);
		
		//���΂炭�҂��āA�V�[����ύX
		if (timer_ <= 0) {
			gameclear_timer_ -= delta_time;
		}

		if (gameclear_timer_ < 0) {
			die();
			world_->game_clear();
		}
	}

	if (world_->field().is_outside(collider())) {
		die();
	}
}

//�Փ˔���
void MyEnemy::react(Actor& other){
	if (other.tag() == "PlayerTag" || other.tag() == "PlayerBulletTag") {
		if (state_ == First || state_ == Third){
			take_damage();
		}
	}
}

//�`��
void MyEnemy::draw() const{
	//���@�̕`��
	gsDrawSprite2D(texture_, &position_, NULL, &center_, &color_, NULL, angle_);

	//HP�o�[�̕`��
	GSrect hp_rect{ 120.0f, 420.0f, 120.0f + hp_ * 4.0f, 450.0f };
	GScolor hp_color{ 1.0f, 0.2f, 0.2f, 0.8f };
	gsDrawRectangle2D(&hp_rect, &hp_color);

	//BOSS�����̕`��
	GSvector2 ui_pos{ 56.0f, 427.0f };
	gsDrawSprite2D(TextureLetterBoss, &ui_pos, NULL, NULL, NULL, NULL, 0.0f);
	
	//���2�̖ڕW�̕\��
	if (state_ == Second){
		int remain = 30 - count_;
		gsFontParameter(0, 16, "�l�r �S�V�b�N");
		gsTextPos(150, 427);
		gsDrawText("Destroy %d Enemies", remain);
	}
}

//�_���[�W����
void MyEnemy::take_damage(){
	hp_ -= 1;
}
