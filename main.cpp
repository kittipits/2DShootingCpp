#include <GSgame.h>
#include "SceneManager.h"
#include "TitleScene.h"
#include "GamePlayScene.h"
#include "ResultScene.h"
#include "GameOverScene.h"

// ゲームクラス
class MyGame : public gslib::Game {
	SceneManager scene_manager_;

	// 開始
	void start() override {
		scene_manager_.add("TitleScene", new TitleScene());
		scene_manager_.add("GamePlayScene", new GamePlayScene());
		scene_manager_.add("ResultScene", new ResultScene());
		scene_manager_.add("GameOverScene", new GameOverScene());
		scene_manager_.change("TitleScene");
	}

	// 更新
	void update(float delta_time) override {
		scene_manager_.update(delta_time);
	}

	// 描画
	void draw() override {
		scene_manager_.draw();
	}

	// 終了
	void end() override {
		scene_manager_.end();
		scene_manager_.clear();
	}
};

// メイン関数
int main() {
	return MyGame().run();
}