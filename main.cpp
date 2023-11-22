#include <GSgame.h>
#include "SceneManager.h"
#include "TitleScene.h"
#include "GamePlayScene.h"
#include "ResultScene.h"
#include "GameOverScene.h"

// �Q�[���N���X
class MyGame : public gslib::Game {
	SceneManager scene_manager_;

	// �J�n
	void start() override {
		scene_manager_.add("TitleScene", new TitleScene());
		scene_manager_.add("GamePlayScene", new GamePlayScene());
		scene_manager_.add("ResultScene", new ResultScene());
		scene_manager_.add("GameOverScene", new GameOverScene());
		scene_manager_.change("TitleScene");
	}

	// �X�V
	void update(float delta_time) override {
		scene_manager_.update(delta_time);
	}

	// �`��
	void draw() override {
		scene_manager_.draw();
	}

	// �I��
	void end() override {
		scene_manager_.end();
		scene_manager_.clear();
	}
};

// ���C���֐�
int main() {
	return MyGame().run();
}