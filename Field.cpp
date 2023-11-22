#include "Field.h"
#include "TextureID.h"

void Field::initialize(){
    scroll_ = 0.0f;
}

void Field::update(float delta_time){
    scroll_ += delta_time;
}

void Field::draw() const{
    draw_background(TextureBG3, scroll_ * 0.5f);
    draw_background(TextureBG2, scroll_ * 2.0f);
    draw_background(TextureBG1, scroll_ * 3.0f);
}

bool Field::is_outside(const BoundingRectangle& rect) const{
    return !extend_area_.intersects(rect);
}

const BoundingRectangle& Field::area() const{
    return area_;
}

void Field::draw_background(GSuint id, float scroll) const{
    GSrect rect{ scroll, 0.0f, scroll + 640.0f, 480.0f };
    gsDrawSprite2D(id, NULL, &rect, NULL, NULL, NULL, 0.0f);
}
