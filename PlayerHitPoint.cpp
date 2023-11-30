#include "PlayerHitPoint.h"
#include "GuageTexture.h"
#include "TextureID.h"
#include <algorithm>

const int PlayerMaxHitPoint = 10;

PlayerHitPoint::PlayerHitPoint() :
    hp_{ PlayerMaxHitPoint }, max_hp_{ PlayerMaxHitPoint } {
}

void PlayerHitPoint::initialize(){
    hp_ = PlayerMaxHitPoint;
}

void PlayerHitPoint::add(int value){
    hp_ = std::min(hp_ + value, max_hp_);
}

void PlayerHitPoint::sub(int value){
    hp_ = std::max(hp_ - value, 0);
}

int PlayerHitPoint::get() const{
    return hp_;
}

void PlayerHitPoint::draw() const {
    static const GuageTexture guage{ TextureGuageGreen, TextureGuageRed, 16, 16 };
    static const GScolor guage_color{ 1.0f, 1.0f, 1.0f, 1.0f };
    static const GScolor background_color{ 1.0f, 1.0f, 1.0f, 0.8f };
    guage.draw(GSvector2{ 264, 2 }, 100, 16, hp_, max_hp_, guage_color, background_color);

    GSvector2 ui_pos{ 200.0f, 0.0f };
    gsDrawSprite2D(TextureLetterShip, &ui_pos, NULL, NULL, NULL, NULL, 0.0f);

}