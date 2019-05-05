#ifndef __j1Player_H__
#define __j1Player_H__

#include "p2Point.h"
#include "Entity.h"

class Player : public Entity
{

private:

public:

	Player(int x, int y, EntityType type);
	~Player();

	void Update(float dt);

};

#endif