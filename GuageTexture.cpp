#include "GuageTexture.h"

GuageTexture::GuageTexture(GSuint guage_texture, GSuint background_texture, 
	int texture_width, int texture_height){
	guage_texture_ = guage_texture;
	background_texture_ = background_texture;
	texture_width_ = texture_width;
	texture_height_ = texture_height;
}

void GuageTexture::draw(const GSvector2& position, 
	int width, int height, int value, int max_value, 
	const GScolor& guage_color, const GScolor& background_color) const{
	if (value > max_value) {
		value = max_value;
	}

	float rate = value / static_cast<float>(max_value);
	GSvector2 guage_scaling;

	guage_scaling.x = (width / static_cast<float>(texture_width_)) * rate;
	guage_scaling.y = height / static_cast<float>(texture_height_);
	gsDrawSprite2D(guage_texture_, &position, NULL, NULL, &guage_color, &guage_scaling, 0.0f);

	if (rate < 1.0f) {
		GSvector2 background_position;
		background_position.x = position.x + width * rate;
		background_position.y = position.y;
		GSvector2 background_scaling;
		background_scaling.x = (width / static_cast<float>(texture_width_)) * (1.0f - rate);
		background_scaling.y = guage_scaling.y;
		gsDrawSprite2D(background_texture_, &background_position,
			NULL, NULL, &background_color, &background_scaling, 0.0f);
	}

}
