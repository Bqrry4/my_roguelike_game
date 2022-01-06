#pragma once
#include "AnimatedObj.h"
#include "Entity.h"

class ProjectileObject : public AnimatedObj
{
	float vx, vy;
	int lifespan; //deplacement in pixels

	int Damage;

	Direction direction;

public:
	ProjectileObject() : AnimatedObj(), vx(0.0f), vy(0.0f), lifespan(0), Damage(30), direction(Direction::Left)
	{
		Interact = true;
		collide.Is = true;
		//collide.WithOthers = true;
	}
	~ProjectileObject() = default;
	ProjectileObject(const ProjectileObject& projectile) = default;

	bool Parse(XMLElement* root, int iObject = 0, XMLElement* xmlElem = nullptr);

	void Movement();
	void Update();

	int DoDamage() { return Damage; }
	Direction FlyDirection() { return direction; }
	void SetDirection(Direction direction) { this->direction = direction; }
};

