#include "ShotNormal.h"
#include "game.h"
#include <DxLib.h>

namespace
{	//手裏剣の速度
	constexpr float kShotSpeed = 8.0f;
	//手裏剣が落ちる速度
	constexpr float kDropSpeed = 0.6f;
	//バウンドする速度
	constexpr float kBoundSpeed = 3.0f;
	//加速度
	constexpr float kAcceleration = 30.0f;
}

void ShotNormal::init()
{
	//手裏剣発射確認
	count = 0;
}

//ショット開始
void ShotNormal::start(Vec2 pos)
{
	ShotBase::start(pos);

	m_vec.x = -kShotSpeed;
	m_vec.y = 0.0f;
}
// 更新
void ShotNormal::update()
{
	if (!m_isExist) return;
	m_pos -= m_vec;

	m_vec.y -= kDropSpeed;	

	if (m_pos.y >= Game::kScreenHeight)
	{
		m_vec.y += kBoundSpeed;		
	}
}