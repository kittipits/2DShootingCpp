#ifndef GUAGE_TEXTURE_H
#define GUAGE_TEXTURE_H

#include <gslib.h>

class GuageTexture {
public: 
	GuageTexture(GSuint guage_texture, GSuint background_texture,
		int texture_width, int texture_height);

	void draw(const GSvector2& position,
		int width, int height, int value, int max_value,
		const GScolor& guage_color = GScolor{ 1.0f, 1.0f, 1.0f, 1.0f },
		const GScolor& background_color = GScolor{ 1.0f, 1.0f, 1.0f, 1.0f }) const;

private:
	GSuint guage_texture_;
	GSuint background_texture_;
	int texture_width_;
	int texture_height_;
};

#endif 

