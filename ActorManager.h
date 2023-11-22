#ifndef ACTOR_MANAGER_H_
#define ACTOR_MANAGER_H_

#include <list>
#include <string>

// アクタークラスの前方宣言
class Actor;

// アクターマネージャークラス
class ActorManager {
public:
	ActorManager() = default;		// コン
	~ActorManager();				// デス

	void add(Actor* actor);			// 追加
	void update(float delta_time);	// 更新
	void draw() const;				// 描画
	void draw_gui() const;			// GUI

	void collide();									// 衝突
	void remove();									// 削除
	Actor* find(const std::string& name) const;		// 検索
	void clear();									// 消去

	// コピー禁止
	ActorManager(const ActorManager& other) = delete;
	ActorManager& operator = (const ActorManager& other) = delete;

private:
	std::list<Actor*> actors_;
};

#endif
