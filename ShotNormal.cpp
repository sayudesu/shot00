#include "ShotNormal.h"
#include "game.h"

namespace
{	//手裏剣の速度
	constexpr float kShotSpeed = 8.0f;
	//手裏剣が落ちる速度
	constexpr float kDropSpeed = 0.2f;
	//バウンドする速度
	constexpr float kBoundSpeed = 3.0f;
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

	if (m_pos.x -= m_vec.x)
	{
		m_vec.y -= kDropSpeed;
	//	m_vec.x += kDropSpeed;
		
		if (m_vec.y -= kDropSpeed)
		{
			m_vec.x += kDropSpeed;
		}
		
	}	
}