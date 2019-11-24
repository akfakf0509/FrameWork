#pragma once
#include "GameObject.h"
class CheckBullet :
	public GameObject
{
public:
	float speed;
	int damage;
public:
	CheckBullet(const wchar_t * uri, float speed, int damage);
	~CheckBullet();

	void OnUpdate();
	void OnLateUpdate();
	void Move();
	bool CheckOutOfScreen();
};

