#include "Actor.h"

void Actor::update(float delta_time){}

void Actor::draw() const {
    gsDrawSprite2D(texture_, &position_, NULL, NULL, NULL, NULL, angle_);
}

void Actor::draw_gui() const{}

void Actor::react(Actor& other){}

void Actor::collide(Actor& other) {
    if (enable_collider_ && other.enable_collider_) {
        if (is_collide(other)) {
            react(other);
            other.react(*this);
        }
    }
}

void Actor::die() {
    dead_ = true;
}

bool Actor::is_collide(const Actor& other) const {
    return collider().intersects(other.collider());
}

bool Actor::is_dead() const {
    return dead_;
}

const std::string& Actor::name() const {
    return name_;
}

const std::string& Actor::tag() const {
    return tag_;
}

GSvector2 Actor::position() const {
    return position_;
}

float Actor::rotation() const {
    return angle_;
}

GSvector2 Actor::velocity() const {
    return velocity_;
}

BoundingRectangle Actor::collider() const {
    return collider_.translate(position_);
}
