#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "j1Module.h"
#include "j1Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer : public j1Module
{
public:
	j1Player();
	~j1Player();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* collider1, Collider* collider2);
	void resetPlayer();

public:
	bool enable_movement = false;
	int counter = 0;
	int speed = 2;
	SDL_Texture * graphics = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation upward;
	Animation downward;
	Animation upwardreturn;
	Animation downwardreturn;
	Animation* current_animation;
	iPoint position;
	iPoint camera_offset;
	Uint32 start_time;
	Uint32 aux_time;
	Collider* collider;
	bool dead = false;
	bool godmode = false;
	char _godmode[8] = "godmode";
};

#endif