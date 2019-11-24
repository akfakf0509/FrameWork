#include "pch.h"
#include "MainScene.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "GameManager.h"

MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}

	
void MainScene::Initialize() {
	Background * background = new Background(L"Images/Background.png");
	background->SetPosition(280, 410);
	PushBackGameObject(background);

	Player * player = new Player(L"Images/Player.png");
	player->SetPosition(280, 700);
	PushBackGameObject(player);

	Enemy * enemy = new Enemy(L"Images/Enemy2.png", 2, 1, 3);
	PushBackGameObject(enemy);

	GAMEMGR->player = player;
	GAMEMGR->enemyList.push_back(enemy);
}