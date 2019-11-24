#pragma once
#include "GameObject.h"
class Background :
	public GameObject
{
public:
	Background(const wchar_t * uri);
	~Background();

	Animation *background_Ani;

	void OnUpdate();
};