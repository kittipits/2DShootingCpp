#ifndef FIELD_H_
#define FIELD_H_

#include "BoundingRectangle.h"

// フィールドクラス
class Field {
public:
	Field() = default;
	void initialize();
	void update(float delta_time);
	void draw() const;
	bool is_outside(const BoundingRectangle& rect) const;
	const BoundingRectangle& area() const;

private:
	void draw_background(GSuint id, float scroll) const;

private:
	BoundingRectangle area_{ 0.0f, 0.0f, 640.0f, 480.0f };
	BoundingRectangle extend_area_{ -128.0f, -128.0f, 640.0f + 128.0f, 480.0f + 128.0f };
	float scroll_{ 0.0f };
};

#endif
