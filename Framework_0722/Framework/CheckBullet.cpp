#include "pch.h"
#include "CheckBullet.h"
#include "Enemy.h"
#include "GameManager.h"

CheckBullet::CheckBullet(const wchar_t * uri, float speed, int damage) : GameObject(uri), speed(speed), damage(damage)
{
}


CheckBullet::~CheckBullet()
{
}

void CheckBullet::OnUpdate()
{
	Move();
}

void CheckBullet::OnLateUpdate()
{
	list<Enemy*>::iterator i;
	for (i = GAMEMGR->enemyList.begin();
		i != GAMEMGR->enemyList.end();
		i++)
	{
		if ((*i)->col->Intersected(pos))
		{
			if ((*i)->Hit(1))
			{
				scene->Destroy(*i);
				i = GAMEMGR->enemyList.erase(i);
				if (i == GAMEMGR->enemyList.end())
					break;
			}
			scene->Destroy(this);
		}
	}
}

bool CheckBullet::CheckOutOfScreen()
{
	D2D1_SIZE_U size
		= sprite->bitmap->GetPixelSize();

	return pos.x < scale.x*size.width*(-1.0f) ||
		pos.x > FWGRAPHIC->GetWidth() + size.width*scale.x ||
		pos.y < scale.y*size.height*(-1.0f) ||
		pos.y > FWGRAPHIC->GetHeight() + size.height*scale.y;
}

void CheckBullet::Move() {
	float rad = PI * rot.angle * 2.0f - 1.57f;

	pos.x += (speed
		* cosf(rad)
		* FWAPP->DeltaTime());
	pos.y += (speed
		* sinf(rad)
		* FWAPP->DeltaTime());

	if (CheckOutOfScreen())
	{
		scene->Destroy(this);
	}
}