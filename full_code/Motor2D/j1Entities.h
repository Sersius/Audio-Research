#ifndef __j1Entities_H__
#define __j1Entities_H__

#include "j1Module.h"

#include <vector>
#include <string>



enum EntityType
{
	PLAYER,
	ENEMY1,
	ENEMY2,
	ENEMY3,

	NO_TYPE
};

class Entity;
class Player;
class Enemy;

struct SDL_Texture;

class j1Entities : public j1Module
{
public:

	j1Entities();
	~j1Entities();

	bool Awake(pugi::xml_node& conf);

	bool Start();

	bool PreUpdate();

	bool Update(float dt);

	bool CleanUp();

	Player* GetPlayer()const;

	bool SpawnEntity(int x, int y, EntityType type);

public:

	std::vector<Entity*> entities;





};

#endif // __j1Enemies_H__