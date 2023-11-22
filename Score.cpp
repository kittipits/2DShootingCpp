#include "Score.h"
#include "NumberTexture.h"
#include "TextureID.h"
#include <gslib.h>
#include <algorithm>    //std::min


Score::Score(int score) : 
    score_{ score } {
}

void Score::initialize(int score){
    score_ = score;
}

void Score::add(int score){
    score_ = std::min(score_ + score, 9999999);
}

void Score::draw() const{
    static const NumberTexture number{ TextureNumber, 16, 16 };
    number.draw(GSvector2{ 64.0f, 0.0f }, score_, 7);
    GSvector2 ui_pos{ 0.0f, 0.0f };
    gsDrawSprite2D( TextureLetterScore, &ui_pos, NULL, NULL, NULL, NULL, 0.0f);
}

int Score::get() const{
    return score_;
}

void Score::clear(){
    score_ = 0;
}
