#pragma once
#include "GObject.h"
#include "Entity.h"

class MovableObject : public GObject
{
	float vx, vy;
	Direction direction;

	void Movement();
public:
	MovableObject() : vy(0.f), vx(0.f), direction(Direction::Left)
	{
		Interact = true;
		collide.Is = true;
		collide.WithOthers = true;
	}
	~MovableObject() = default;
	void Update();

	void Move(Direction);
};
