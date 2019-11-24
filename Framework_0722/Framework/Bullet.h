#pragma once
#include "GameObject.h"
class Bullet :
	public GameObject
{
public:
	float damage_time;
	int damage;
	float standard_x;
	float standard_y;
	bool is_fire;
public:
	Bullet(const wchar_t * uri, float standard_x, float standard_y, int damage);
	~Bullet();

	Animation * fire;
	Animation * idle;
	Animation * destroy;

	void OnUpdate();
	void Damage();
	void Destory();
};

