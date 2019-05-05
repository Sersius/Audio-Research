#include "j1App.h"
#include "Entity.h"
#include "j1Render.h"

Entity::Entity(int x, int y, EntityType type) : position(x, y), type(type)
{
}

Entity::~Entity()
{
}

void Entity::Draw()
{
	switch (type) {
	case PLAYER:
		SDL_SetRenderDrawColor(App->render->renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(App->render->renderer, &rect);
		break;
	case ENEMY1:
		SDL_SetRenderDrawColor(App->render->renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(App->render->renderer, &rect);
		break;
	case ENEMY2:
		SDL_SetRenderDrawColor(App->render->renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(App->render->renderer, &rect);
		break;
	case ENEMY3:
		SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 255, 255);
		SDL_RenderFillRect(App->render->renderer, &rect);
		break;
	default:
		break;
	}
}