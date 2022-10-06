#include "DxLib.h"
#include "game.h"
#include "SceneMain.h"
#include "ShotNormal.h"
#include "ShotBound.h"
#include <cassert>

namespace
{
	//�V���b�g�̔��ˊԊu
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

// ������
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();
	m_player.setMain(this);
}

// �I������
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);

	for (auto& pShot : m_pShotVt)
	{
		
		assert(pShot); //null(false)(0)�̏ꍇ�~�߂�

		delete pShot;
		pShot = nullptr;
	}
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();

	std::vector<ShotBase*>::iterator it = m_pShotVt.begin();
	while (it != m_pShotVt.end())
	{
		auto& pShot = (*it);

		if (!pShot)
		{
			it++;
			continue;
		}
		pShot->update();
		if (!pShot->isExist())
		{
			delete pShot;
			pShot = nullptr;

			//vrctor�̗v�f�폜
			it = m_pShotVt.erase(it);
			continue;
        }

		it++;
	}
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();

	for (auto& pShot : m_pShotVt)
	{
		if (!pShot) continue;
		pShot->draw();
	}

	//���ݑ��݂��Ă���e�̐���\��
	DrawFormatString(0, 0, GetColor(GetRand(255), GetRand(255), GetRand(255)), "�e�̐�:%d", m_pShotVt.size());
}

bool SceneMain::createShotNormal(Vec2 pos)
{
	ShotNormal* pShot = new ShotNormal;
	pShot->setHandle(m_hShotGraphic);
	pShot->start(pos);
	m_pShotVt.push_back(pShot);
	
	return true;

	for (auto& pShot : m_pShotVt)
	{
		if (pShot) continue;

		pShot = new ShotNormal;
		pShot->setHandle(m_hShotGraphic);
		pShot->start(pos);
		return true;
	}
	return false;
}

bool SceneMain::createShotBound(Vec2 pos)
{
	ShotBound* pShot = new ShotBound;
	pShot->setHandle(m_hShotGraphic);
	pShot->start(pos);
	m_pShotVt.push_back(pShot);

	return true;


	for (auto& pShot : m_pShotVt)
	{
		if (pShot) continue;

		pShot = new ShotBound;
		pShot->setHandle(m_hShotGraphic);
		pShot->start(pos);
		return true;
	}
	return false;
}
