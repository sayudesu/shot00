#include "DxLib.h"
#include "SceneMain.h"
#include "game.h"

namespace
{
	//ƒVƒ‡ƒbƒg‚Ì”­ËŠÔŠu
	constexpr int kShotInterval = 16;
}

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;
}
SceneMain::~SceneMain()
{

}

// ‰Šú‰»
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();
	m_player.setMain(this);

	for (auto& shot : m_pShotNormal)
	{
		shot = nullptr;
	}
	for (auto& shot : m_pShotBound)
	{
		shot = nullptr;
	}
}

// I—¹ˆ—
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);

	for (auto& shot : m_pShotNormal)
	{
		if (!shot) continue;
		delete shot;
		shot = nullptr;
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot) continue;
		delete shot;
		shot = nullptr;
	}
}

// –ˆƒtƒŒ[ƒ€‚Ìˆ—
void SceneMain::update()
{
	m_player.update();
	for (auto& shot : m_pShotNormal)
	{
		if (!shot) continue;
		shot->update();
		if(!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot) continue;
		shot->update();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}
}

// –ˆƒtƒŒ[ƒ€‚Ì•`‰æ
void SceneMain::draw()
{
	m_player.draw();

	for (auto& shot : m_pShotNormal)
	{
		if (!shot) continue;
		shot->draw();
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot) continue;
		shot->draw();
	}

	//Œ»İ‘¶İ‚µ‚Ä‚¢‚é’e‚Ì”‚ğ•\¦
	int shotNum = 0;
	for (auto& shot : m_pShotNormal)
	{
		if (!shot) continue;
		if (shot->isExist())shotNum++;
	}
	DrawFormatString(0, 0, GetColor(GetRand(255), GetRand(255), GetRand(255)), "N’e‚Ì”:%d", shotNum);
	shotNum = 0;
	for (auto& shot : m_pShotBound)
	{
		if (!shot) continue;
		if (shot->isExist())shotNum++;
	}
	DrawFormatString(0, 32, GetColor(GetRand(255), GetRand(255), GetRand(255)), "B’e‚Ì”:%d", shotNum);

}

bool SceneMain::createShot(Vec2 pos)
{
	for (auto& shot : m_pShotNormal)
	{
		if (shot) continue;

		shot = new ShotNormal;
		shot->setHandle(m_hShotGraphic);
		shot->start(pos);
		return true;
	}
	return false;
}

bool SceneMain::createShotBound(Vec2 pos)
{
	for (auto& shot : m_pShotBound)
	{
		if (shot) continue;

		shot = new ShotBound;
		shot->setHandle(m_hShotGraphic);
		shot->start(pos);
		return true;
	}
	return false;
}
