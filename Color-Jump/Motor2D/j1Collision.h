//#ifndef __j1Collision_H__
//#define __j1Collision_H__
//
//#define MAX_COLLIDERS 700
//
//#include "j1Module.h"
//
//enum COLLIDER_TYPE
//{
//	COLLIDER_NONE = -1,
//	COLLIDER_WALL,
//	COLLIDER_PLAYER,
//	COLLIDER_ENEMY,
//	COLLIDER_POWERUP,
//	COLLIDER_MAX,
//};
//
//struct Collider
//{
//	SDL_Rect rect;
//	bool to_delete = false;
//	COLLIDER_TYPE type;
//	//Module* callback = nullptr;
//
//	Collider(SDL_Rect rectangle, COLLIDER_TYPE type, j1Module* callback = nullptr) :
//		rect(rectangle),
//		type(type),
//		callback(callback)
//	{}
//
//	COLLIDER_TYPE gettype() { return type; }
//
//	void SetPos(int x, int y)
//	{
//		rect.x = x;
//		rect.y = y;
//	}
//
//
//
//
//	bool CheckCollision(const SDL_Rect& r) const;
//};
//
//class j1Collision : public j1Module
//{
//public:
//
//	j1Collision();
//	~j1Collision();
//
//	update_status PreUpdate();
//	update_status Update();
//	bool CleanUp() override;
//
//	Collider* AddCollider(SDL_Rect rect, COLLIDER_TYPE type, j1Module* callback = nullptr);
//	void DebugDraw();
//
//private:
//
//	Collider * colliders[MAX_COLLIDERS];
//	bool matrix[COLLIDER_MAX][COLLIDER_MAX];
//	bool debug = false;
//};
//
//#endif // __j1Collision_H__
