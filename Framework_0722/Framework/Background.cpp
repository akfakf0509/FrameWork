#include "pch.h"
#include "Background.h"


Background::Background(const wchar_t * uri) : GameObject(uri)
{
	background_Ani = new Animation(this, 0.5f);
	background_Ani->PushBackSprite(L"Images/Background1.png");
	background_Ani->PushBackSprite(L"Images/Background2.png");
	background_Ani->PushBackSprite(L"Images/Background3.png");
	currentAnimation = background_Ani;
}


Background::~Background()
{
	SAFE_DELETE(background_Ani);
}

void Background::OnUpdate() {
	UpdateAnimation();
}