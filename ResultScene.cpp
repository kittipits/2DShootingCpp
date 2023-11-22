#include "ResultScene.h"
#include "TextureID.h"
#include "IWorld.h"
#include "NumberTexture.h"

#include <fstream>
using namespace std;

void ResultScene::start(){
    gsLoadTexture(TextureGameClear, "Assets/CLEAR.png");
    gsLoadTexture(TextureBG1, "Assets/BG1.png");
    gsLoadTexture(TextureBG2, "Assets/BG2.png");
    gsLoadTexture(TextureBG3, "Assets/BG3.png");
    ifstream score_input("score.txt");
    int score;
    score_input >> score;
    score_.add(score);
    score_input.close();

    ifstream high_score_input("highscore.txt");
    high_score_input >> high_score_;
    high_score_input.close();
    if (score > high_score_) high_score_ = score;
    ofstream high_score_output("highscore.txt");
    high_score_output << high_score_;
    high_score_output.close();

    is_end_ = false;
}

void ResultScene::update(float delta_time){
    if (gsGetKeyTrigger(GKEY_RETURN)) {
        is_end_ = true;
    }

    scroll_ += delta_time;
}

void ResultScene::draw() const{
    draw_background(TextureBG3, scroll_ * 0.5f);
    draw_background(TextureBG2, scroll_ * 2.0f);
    draw_background(TextureBG1, scroll_ * 3.0f);

    const static GSvector2 position_logo{ 80.0f, 100.0f };
    gsDrawSprite2D(TextureGameClear, &position_logo, NULL, NULL, NULL, NULL, 0.0f);

    static const NumberTexture number{ TextureNumber, 16, 16 };
    number.draw(GSvector2{ 304.0f, 300.0f }, score_.get(), 7);
    GSvector2 ui_pos{ 240.0f, 300.0f };
    gsDrawSprite2D(TextureLetterScore, &ui_pos, NULL, NULL, NULL, NULL, 0.0f);

    GSrect rect{ 220.0f, 350.0f, 420.0f, 380.0f };
    GScolor color{ 0.0f, 0.0f, 0.0f, 1.0f };
    gsDrawRectangle2D(&rect, &color);
    gsFontParameter(0, 16, "‚l‚r ƒSƒVƒbƒN");
    gsTextPos(250, 357);
    gsDrawText("HIGH SCORE : %d", high_score_);
}

bool ResultScene::is_end() const{
    return is_end_;
}

std::string ResultScene::next() const{
    return "TitleScene";
}

void ResultScene::end(){
    gsDeleteTexture(TextureGameClear);
    gsDeleteTexture(TextureBG1);
    gsDeleteTexture(TextureBG2);
    gsDeleteTexture(TextureBG3);
}

void ResultScene::draw_background(GSuint id, float scroll) const{
    GSrect rect{ scroll, 0.0f, scroll + 640.0f, 480.0f };
    gsDrawSprite2D(id, NULL, &rect, NULL, NULL, NULL, 0.0f);
}
