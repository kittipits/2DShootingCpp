#ifndef ACTOR_MANAGER_H_
#define ACTOR_MANAGER_H_

#include <list>
#include <string>

// �A�N�^�[�N���X�̑O���錾
class Actor;

// �A�N�^�[�}�l�[�W���[�N���X
class ActorManager {
public:
	ActorManager() = default;		// �R��
	~ActorManager();				// �f�X

	void add(Actor* actor);			// �ǉ�
	void update(float delta_time);	// �X�V
	void draw() const;				// �`��
	void draw_gui() const;			// GUI

	void collide();									// �Փ�
	void remove();									// �폜
	Actor* find(const std::string& name) const;		// ����
	void clear();									// ����

	// �R�s�[�֎~
	ActorManager(const ActorManager& other) = delete;
	ActorManager& operator = (const ActorManager& other) = delete;

private:
	std::list<Actor*> actors_;
};

#endif
