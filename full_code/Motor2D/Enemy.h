#ifndef __j1Enemy_H__
#define __j1Enemy_H__


#include "P2Point.h"
#include "Entity.h"

class Enemy : public Entity
{


public:
	uint death_1 = 0u;
	uint death_2 = 0u;
	uint death_3 = 0u;

private:


public:

	Enemy(int x, int y, EntityType type);
	~Enemy();

	void Update(float dt);

};

#endif