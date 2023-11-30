#include "ActorManager.h"
#include "Actor.h"

ActorManager::~ActorManager() {
	clear();
}

void ActorManager::add(Actor* actor) {
	actors_.push_back(actor);
}

void ActorManager::update(float delta_time){
	for (auto actor : actors_) {
		actor->update(delta_time);
	}
}
void ActorManager::draw() const {
	for (auto actor : actors_) {
		actor->draw();
	}
}

void ActorManager::draw_gui() const {
	for (auto actor : actors_) {
		actor->draw_gui();
	}
}

void ActorManager::collide() {
	for (auto i = actors_.begin(); i != actors_.end(); ++i) {
		for (auto j = std::next(i); j != actors_.end(); ++j) {
			(*i)->collide(**j);
		}
	}
}

void ActorManager::remove() {
	for (auto i = actors_.begin(); i != actors_.end();) {
		if ((*i)->is_dead()) {
			delete* i;
			i = actors_.erase(i);
		}
		else {
			++i;
		}
	}
}

Actor* ActorManager::find(const std::string& name) const {
	for (auto actor : actors_) {
		if (actor->name() == name) {
			return actor;
		}
	}
	return nullptr;
}

void ActorManager::clear() {
	for (auto actor : actors_) {
		delete actor;
	}
	actors_.clear();
}

std::vector<Actor*> ActorManager::find_with_tag(const std::string& tag) const{
	std::vector<Actor*> result;
	for (auto actor : actors_) {
		if (actor->tag() == tag) {
			result.push_back(actor);
		}
	}
	return result;
}

void ActorManager::send_message(const std::string& message, void* param){
	for (auto actor : actors_) {
		actor->handle_message(message, param);
	}
}
