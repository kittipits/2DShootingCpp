#ifndef TITLE_SCENE_H_
#define TITLE_SCENE_H_

#include "IScene.h"
#include <gslib.h>

class TitleScene : public IScene {
public:
	virtual void start() override;
	virtual void update(float delta_time) override;
	virtual void draw() const override;
	virtual bool is_end() const override;
	virtual std::string next() const override;
	virtual void end() override;

private:
	void draw_background(GSuint id, float scroll) const;
	bool is_end_{ false };
	float scroll_{ 0.0f };
};

#endif
