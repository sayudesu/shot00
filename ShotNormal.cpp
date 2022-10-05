#include "ShotNormal.h"
#include "game.h"

namespace
{	//�藠���̑��x
	constexpr float kShotSpeed = 8.0f;
	//�藠���������鑬�x
	constexpr float kDropSpeed = 0.2f;
	//�o�E���h���鑬�x
	constexpr float kBoundSpeed = 3.0f;
}
//�V���b�g�J�n
void ShotNormal::start(Vec2 pos)
{
	ShotBase::start(pos);

	m_vec.x = -kShotSpeed;
	m_vec.y = 0.0f;
}
// �X�V
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