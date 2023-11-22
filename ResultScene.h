#ifndef RESULT_SCENE_H_
#define RESULT_SCENE_H_

#include "IScene.h"
#include <gslib.h>

#include "Score.h"

class ResultScene : public IScene {
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
	Score score_;
	int high_score_;
};

#endif