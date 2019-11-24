#pragma once
#include "GameObject.h"
class Enemy :
	public GameObject
{
public:	
	int health;
	float speed;
	float angle;
public:
	Enemy(const wchar_t * uri, int type, float speed, int health);
	~Enemy();

	void OnUpdate();
	void Move();
	bool Hit(int damage);

	Animation * hurt;
	Animation * idle;
};

