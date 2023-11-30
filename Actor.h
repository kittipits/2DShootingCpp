#ifndef ACTOR_H_
#define ACTOR_H_

#include <gslib.h>
#include <string>
#include "BoundingRectangle.h"

// ワールド抽象インターフェースの前方宣言
class IWorld;

// アクタークラス
class Actor {
public:
public:
	Actor() = default;				// コンストラクタ
	virtual ~Actor() = default;		// デストラクタ

	virtual void update(float delta_time);
	virtual void draw() const;
	virtual void draw_gui() const;

	// 衝突時リアクション
	virtual void react(Actor& other);
	// 衝突判定
	void collide(Actor& other);
	// 死亡する
	void die();
	// 衝突判定しているか？
	bool is_collide(const Actor& other) const;
	// 死亡しているか？
	bool is_dead() const;

	//ゲッター関数
	const std::string& name() const;
	const std::string& tag() const;
	GSvector2 position() const;
	float rotation() const;
	GSvector2 velocity() const;
	BoundingRectangle collider() const;

	// メッセージ処理
	virtual void handle_message(const std::string& message, void* param);
	
	// コピー禁止
	Actor(const Actor& other) = delete;
	Actor& operator = (const Actor& other) = delete;

protected:
	IWorld*				world_{ nullptr };
	std::string			name_;
	std::string			tag_;
	GSvector2			position_{ 0.0f, 0.0f };
	float				angle_{ 0.0f };
	GSvector2			velocity_{ 0.0f,0.0f };
	bool				enable_collider_{ true };
	BoundingRectangle	collider_{ 0.0f,0.0f,0.0f,0.0f };
	bool				dead_{ false };
	GSuint				texture_{ 0 };
};

#endif

