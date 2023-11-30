#ifndef ACTOR_H_
#define ACTOR_H_

#include <gslib.h>
#include <string>
#include "BoundingRectangle.h"

// ���[���h���ۃC���^�[�t�F�[�X�̑O���錾
class IWorld;

// �A�N�^�[�N���X
class Actor {
public:
public:
	Actor() = default;				// �R���X�g���N�^
	virtual ~Actor() = default;		// �f�X�g���N�^

	virtual void update(float delta_time);
	virtual void draw() const;
	virtual void draw_gui() const;

	// �Փˎ����A�N�V����
	virtual void react(Actor& other);
	// �Փ˔���
	void collide(Actor& other);
	// ���S����
	void die();
	// �Փ˔��肵�Ă��邩�H
	bool is_collide(const Actor& other) const;
	// ���S���Ă��邩�H
	bool is_dead() const;

	//�Q�b�^�[�֐�
	const std::string& name() const;
	const std::string& tag() const;
	GSvector2 position() const;
	float rotation() const;
	GSvector2 velocity() const;
	BoundingRectangle collider() const;

	// ���b�Z�[�W����
	virtual void handle_message(const std::string& message, void* param);
	
	// �R�s�[�֎~
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

