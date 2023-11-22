#include "World.h"

void World::update(float delta_time) {
	field_.update(delta_time);
	actors_.update(delta_time);
	actors_.collide();
	actors_.remove();
}

void World::draw() const {
	field_.draw();
	actors_.draw();
	score_.draw();
}

void World::clear() {
	actors_.clear();
	score_.clear();
	is_game_over_ = false;
	is_game_clear_ = false;
}

void World::add_actor(Actor* actor) {
	actors_.add(actor);
}

Actor* World::find_actor(const std::string& name) const {
	return actors_.find(name);
}

Field& World::field() {
	return field_;
}

void World::add_score(int score) {
	score_.add(score);
}

void World::game_over(){
	is_game_over_ = true;
}

void World::game_clear(){
	is_game_clear_ = true;
}

bool World::is_game_over() const{
	return is_game_over_;
}

bool World::is_game_clear() const{
	ofstream score_file("score.txt");
	score_file << score_.get();
	score_file.close();
	return is_game_clear_;
}
