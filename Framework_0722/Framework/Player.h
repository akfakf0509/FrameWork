#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Player :
	public GameObject
{
public:
	float angle;
	int damage;

	Bullet * bullet;
public:
	Player(const wchar_t * uri);
	~Player();

	void OnUpdate();
	void Rotate();
	void Attack();
};