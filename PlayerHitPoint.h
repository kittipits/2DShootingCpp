#ifndef PLAYER_HIT_POINT_H
#define PLAYER_HIT_POINT_H

class PlayerHitPoint {
public:
	PlayerHitPoint();
	void initialize();
	void draw() const;
	void add(int value);
	void sub(int value);
	int get() const;

private:
	int hp_;
	int max_hp_;
};

#endif

