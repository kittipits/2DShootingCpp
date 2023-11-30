#ifndef IWORLD_H_
#define IWORLD_H_

#include <string>

// アクタークラスの前方宣言
class Actor;
class Field;
class PlayerHitPoint;

// ワールド抽象インターフェース
class IWorld {
public:
	virtual ~IWorld() = default;
	virtual void add_actor(Actor* actor) = 0;
	virtual Actor* find_actor(const std::string& name) const = 0;
	virtual Field& field() = 0;
	virtual PlayerHitPoint& player_hp() = 0;
	virtual void add_score(int score) = 0;
	virtual void game_over() = 0;
	virtual void game_clear() = 0;
};

#endif
