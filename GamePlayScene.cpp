#include "GamePlayScene.h"
#include "Player.h"
#include "EnemyGenerator.h"
#include "TextureID.h"
#include "SoundID.h"

void GamePlayScene::start(){
	// テクスチャの読み込み
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
	gsLoadTexture(TextureParticle, "Assets/particle.png");
	
	gsLoadSE(Se_ExplosionPlayer, "Assets/explosion_player.wav", 1, GWAVE_DEFAULT);
	gsLoadSE(Se_WeaponPlayer, "Assets/weapon_player.wav", 5, GWAVE_DEFAULT);
	gsLoadBGM(Music_BackGround, "Assets/music_background.ogg", GS_TRUE);
	gsPlayBGM(Music_BackGround);

	//プレーヤー
	world_.add_actor(new Player{ &world_, GSvector2{0.0f, 200.0f} });
	//敵生成
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

	gsDeleteSE(Se_ExplosionPlayer);
	gsDeleteSE(Se_WeaponPlayer);
	gsStopBGM();
	gsDeleteBGM(Music_BackGround);
}
