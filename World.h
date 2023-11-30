#ifndef WORLD_H_
#define WORLD_H_

#include "IWorld.h"
#include "ActorManager.h"
#include "Field.h"
#include "Score.h"
#include "PlayerHitPoint.h"

#include <fstream>
#include <iostream>
using namespace std;

//ワールドクラス
class World : public IWorld {
public:
	World() = default;
	void update(float delta_time);
	void draw() const;
	void clear();
	virtual void add_actor(Actor* actor) override;
	virtual Actor* find_actor(const std::string& name) const override;
	virtual Field& field() override;
	virtual PlayerHitPoint& player_hp() override;
	virtual void add_score(int score) override;
	virtual void game_over() override;
	virtual void game_clear() override;

	bool is_game_over() const;
	bool is_game_clear() const;

	// コピー禁止
	World(const World& other) = delete;
	World& operator = (const World& other) = delete;

private:
	ActorManager actors_;
	Field field_;
	Score score_;
	PlayerHitPoint player_hp_;
	bool is_game_over_{ false };
	bool is_game_clear_{ false };
};

#endif
