#include "j1App.h"
#include "j1Render.h"
#include "j1Entities.h"
#include "j1Textures.h"
#include "Entity.h"
#include "j1Audio.h"
#include "j1Window.h"
#include "P2Log.h"
#include "Enemy.h"
#include "Player.h"


j1Entities::j1Entities()
{
	name = "entities";
}

// Destructor
j1Entities::~j1Entities()
{
	LOG("Unloading entities spritesheet");

}

bool j1Entities::Awake(pugi::xml_node& config)
{
	LOG("Loading Entities from config file");
	bool ret = true;



	return ret;
}

bool j1Entities::Start()
{
	bool ret = true;



	if (!ret)
		return false;

	return ret;
}

bool j1Entities::PreUpdate()
{
	for (int i = 0; i < entities.capacity(); i++) {
		if (entities[i]->to_destroy) {
			delete(entities[i]);
			entities[i] = nullptr;
			entities.erase(entities.cbegin() + i);
			entities.shrink_to_fit();
		}
	}
	return true;
}

// Called before render is available
bool j1Entities::Update(float dt)
{

	for (int i = 0; i < entities.capacity(); i++)
		if (entities.at(i) != nullptr) entities[i]->Update(dt);

	for (int i = 0; i < entities.capacity(); i++)
		if (entities.at(i) != nullptr) entities[i]->Draw();

	return true;
}

// Called before quitting
bool j1Entities::CleanUp()
{
	LOG("Freeing all enemies");





	return true;
}

bool j1Entities::SpawnEntity(int x, int y, EntityType type)
{
	// find room for the new entity
	bool ret = false;

	switch (type)
	{
	case EntityType::PLAYER: {
		Player* player = new Player(x, y, PLAYER);
		entities.push_back(player);
		ret = true;
		break;
	}
	case EntityType::ENEMY1: {
		Enemy* enemy = new Enemy(x, y, ENEMY1);
		entities.push_back(enemy);
		ret = true;
		break;
	}
	case EntityType::ENEMY2: {
		Enemy* enemy = new Enemy(x, y, ENEMY2);
		entities.push_back(enemy);
		ret = true;
		break;
	}
	case EntityType::ENEMY3: {
		Enemy* enemy = new Enemy(x, y, ENEMY3);
		entities.push_back(enemy);
		ret = true;
		break;
	}
	default:
		break;
	}


	return ret;
}

Player* j1Entities::GetPlayer() const {

	for (uint i = 0; i < entities.capacity(); ++i)
	{
		if (entities.at(i) != nullptr)
		{
			if (entities[i]->type == PLAYER)
				return (Player*)entities[i];
		}
	}

	return nullptr;

}