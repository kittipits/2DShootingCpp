#include "GamePlayScene.h"
#include "Player.h"
#include "EnemyGenerator.h"
#include "TextureID.h"

void GamePlayScene::start(){
	// �e�N�X�`���̓ǂݍ���
	gsLoadTexture(TexturePlayer, "Assets/SHIP.png");
	gsLoadTexture(TextureEnemy, "Assets/ENEMY.png");
	gsLoadTexture(TextureEnemyBlue, "Assets/ENEMY2.png");
	gsLoadTexture(TextureBoss, "Assets/BOSS.png");
	gsLoadTexture(TexturePlayerBeam, "Assets/BEAM.png");
	gsLoadTexture(TextureEnemyBeam, "Assets/EBEAM.png");
	gsLoadTexture(TextureBG1, "Assets/BG1.png");
	gsLoadTexture(TextureBG2, "Assets/BG2.png");
	gsLoadTexture(TextureBG3, "Assets/BG3.png");
	gsLoadTexture(TextureBomb, "Assets/BOMB.png");
	gsLoadTexture(TextureNumber, "Assets/NUM.png");
	gsLoadTexture(TextureLetterScore, "Assets/NSCORE.png");
	gsLoadTexture(TextureLetterShip, "Assets/NSHIP.png");
	gsLoadTexture(TextureLetterBoss, "Assets/NBOSS.png");
	gsLoadTexture(TextureGuageRed, "Assets/grp1.png");
	gsLoadTexture(TextureGuageGreen, "Assets/grp2.png");

	//�v���[���[
	world_.add_actor(new Player{ &world_, GSvector2{0.0f, 200.0f} });
	//�G����
	world_.add_actor(new EnemyGenerator{ &world_ });
}

void GamePlayScene::update(float delta_time){
	world_.update(delta_time);
}

void GamePlayScene::draw() const{
	world_.draw();
}

bool GamePlayScene::is_end() const{
	return world_.is_game_over() || world_.is_game_clear();
	//return world_.find_actor("Player") == nullptr;
}

std::string GamePlayScene::next() const{
	if (world_.is_game_clear()) {
		return "ResultScene";
	}
	return "GameOverScene";
}

void GamePlayScene::end(){
	world_.clear();
	gsDeleteTexture(TexturePlayer);
	gsDeleteTexture(TextureEnemy);
	gsDeleteTexture(TextureEnemyBlue);
	gsDeleteTexture(TextureBoss);
	gsDeleteTexture(TextureBG1);
	gsDeleteTexture(TextureBG2);
	gsDeleteTexture(TextureBG3);
	gsDeleteTexture(TexturePlayerBeam);
	gsDeleteTexture(TextureEnemyBeam);
	gsDeleteTexture(TextureBomb);
	gsDeleteTexture(TextureGuageRed);
	gsDeleteTexture(TextureGuageGreen);
}
