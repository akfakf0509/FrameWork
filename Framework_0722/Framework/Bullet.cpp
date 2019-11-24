#include "pch.h"
#include "Bullet.h"
#include "CheckBullet.h"
#include "GameManager.h"

Bullet::Bullet(const wchar_t * uri, float standard_x, float standard_y,  int damage) : GameObject(uri), is_fire(false), standard_x(standard_x), standard_y(standard_y), damage(damage), damage_time(0.5f)
{
	fire = new Animation(this, 0.15f);
	fire->PushBackSprite(L"Images/Player_Fire1.png");
	fire->PushBackSprite(L"Images/Player_Fire2.png");
	fire->PushBackSprite(L"Images/Player_Fire3.png");
	fire->PushBackSprite(L"Images/Player_Fire4.png");
	fire->PushBackSprite(L"Images/Player_Fire5.png");
	fire->PushBackSprite(L"Images/Player_Fire6.png");
	currentAnimation = fire;

	idle = new Animation(this, 0.3f);
	idle->PushBackSprite(L"Images/Player_Fire6.png");
	idle->PushBackSprite(L"Images/Player_Fire5.png");

	destroy = new Animation(this, 0.3f);
	destroy->PushBackSprite(L"Images/Player_Fire6.png");
	destroy->PushBackSprite(L"Images/Player_Fire5.png");
	destroy->PushBackSprite(L"Images/Player_Fire4.png");
}


Bullet::~Bullet()
{
	SAFE_DELETE(fire);
	SAFE_DELETE(idle);
	SAFE_DELETE(destroy);
}

float tmp_damage_time = 0;
void Bullet::OnUpdate() {
	if (fire->repeat) {
		SwapAnimation(idle);
		is_fire = true;
	}	
	if (destroy->repeat) {
		scene->Destroy(this);
	}
	UpdateAnimation();

	if (is_fire) {
		tmp_damage_time += FWAPP->DeltaTime();
		if (tmp_damage_time >= damage_time) {
			tmp_damage_time = 0;
			Damage();
		}
	}
}

void Bullet::Damage() {
	CheckBullet * checkbullet = new CheckBullet(L"Images/Check_Bullet.png", 3000, damage);
	checkbullet->SetPosition(standard_x, standard_y);
	checkbullet->SetRotation(rot.angle, standard_x, standard_y);
	scene->PushBackGameObject(checkbullet);
}

void Bullet::Destory() {
	SwapAnimation(destroy);
}