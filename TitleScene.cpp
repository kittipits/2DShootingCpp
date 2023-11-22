#include "TitleScene.h"
#include "TextureID.h"

void TitleScene::start(){
    gsLoadTexture(TextureTitleLogo, "Assets/TITLE1.png");
    gsLoadTexture(TextureTitleStart, "Assets/TITLE2.png");
    gsLoadTexture(TextureBG1, "Assets/BG1.png");
    gsLoadTexture(TextureBG2, "Assets/BG2.png");
    gsLoadTexture(TextureBG3, "Assets/BG3.png");

    is_end_ = false;
}

void TitleScene::update(float delta_time){
    if (gsGetKeyTrigger(GKEY_RETURN)) {
        is_end_ = true;
    }

    scroll_ += delta_time;
}

void TitleScene::draw() const{
    draw_background(TextureBG3, scroll_ * 0.5f);
    draw_background(TextureBG2, scroll_ * 2.0f);
    draw_background(TextureBG1, scroll_ * 3.0f);

    const static GSvector2 position_logo{ 64.0f, 100.0f };
    gsDrawSprite2D(TextureTitleLogo, &position_logo, NULL, NULL, NULL, NULL, 0.0f);
    const static GSvector2 position_start{ 170.0f, 260.0f };
    gsDrawSprite2D(TextureTitleStart, &position_start, NULL, NULL, NULL, NULL, 0.0f);
}

bool TitleScene::is_end() const{
    return is_end_;
}

std::string TitleScene::next() const{
    return "GamePlayScene";
}

void TitleScene::end(){
    gsDeleteTexture(TextureTitleLogo);
    gsDeleteTexture(TextureTitleStart);
    gsDeleteTexture(TextureBG1);
    gsDeleteTexture(TextureBG2);
    gsDeleteTexture(TextureBG3);
}

void TitleScene::draw_background(GSuint id, float scroll) const
{
    GSrect rect{ scroll, 0.0f, scroll + 640.0f, 480.0f };
    gsDrawSprite2D(id, NULL, &rect, NULL, NULL, NULL, 0.0f);
}
