#include "pch.h"
#include "Enemy.h"


Enemy::Enemy(const wchar_t * uri, int type, float speed, int health) : GameObject(uri), speed(speed), health(health), angle(0)
{
	SetPosition(Random(50, 240), 50);

	hurt = new Animation(this, 0.3f);
	idle = new Animation(this, 0.3f);
	switch (type) {
	case 1:
		hurt->PushBackSprite(L"Images/Enemy1_hurt.png");
		hurt->PushBackSprite(L"Images/Enemy1.png");
		idle->PushBackSprite(L"Images/Enemy1.png");
		break;
	case 2:
		hurt->PushBackSprite(L"Images/Enemy2_hurt.png");
		hurt->PushBackSprite(L"Images/Enemy2.png");
		idle->PushBackSprite(L"Images/Enemy2.png");
		break;
	case 3:
		hurt->PushBackSprite(L"Images/Enemy3_hurt.png");
		hurt->PushBackSprite(L"Images/Enemy3.png");
		idle->PushBackSprite(L"Images/Enemy3.png");
		break;
	}
	currentAnimation = idle;
}


Enemy::~Enemy()
{
	SAFE_DELETE(hurt);
	SAFE_DELETE(idle);
}

void Enemy::OnUpdate() 
{
	UpdateAnimation();
	if (hurt->repeat) {
		SwapAnimation(idle);
	}
	Move();
}

void Enemy::Move() 
{
	angle++;
	SetRotation(angle, pos.x, pos.y);
	SetPosition(pos.x, pos.y + speed);
}

bool Enemy::Hit(int damage) {
	if (currentAnimation == idle) {
		SwapAnimation(hurt);
	}
	health -= damage;
	if (health <= 0)
		return true;
	else
		return false;
}