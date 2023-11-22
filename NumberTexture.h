#ifndef NUMBER_TEXTURE_H_
#define NUMBER_TEXTURE_H_

#include <gslib.h>
#include <string>

class NumberTexture {
public:
	NumberTexture(GSuint texture, int width, int height);
	void draw(const GSvector2& position, int num, int digit, char fill = '0') const;
	void draw(const GSvector2& position, int num) const;
	void draw(const GSvector2& position, const std::string& num) const;

private:
	GSuint texture_;
	int width_;
	int height_;
};

#endif
