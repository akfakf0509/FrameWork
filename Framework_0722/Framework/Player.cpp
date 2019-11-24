#include "pch.h"
#include "Player.h"


Player::Player(const wchar_t * uri) : GameObject(uri), angle(0), damage(1)
{
}


Player::~Player()
{
}

void Player::OnUpdate() {
	Rotate();
	Attack();
}

void Player::Rotate() {
	if (FWINPUT->GetKeyPressed(VK_RIGHT)) {
		++angle;
	}
	if (FWINPUT->GetKeyPressed(VK_LEFT)) {
		--angle;
	}
	SetRotation(angle, pos.x, pos.y);
}

void Player::Attack() {
	if (FWINPUT->GetKeyDown(VK_SPACE)) {
		bullet = new Bullet(L"Images/Player_Fire1.png", pos.x, pos.y, damage);
		bullet->SetPosition(pos.x, pos.y - 450);
		scene->PushBackGameObject(bullet);
	}
	if (FWINPUT->GetKeyPressed(VK_SPACE)) {
		bullet->SetRotation(angle, pos.x, pos.y);
	}
	if (FWINPUT->GetKeyUp(VK_SPACE)) {
		bullet->Destory();
	}
}