#include "ShotBound.h"
#include "game.h"
#include <DxLib.h>

namespace
{	//�藠���̑��x
	constexpr float kShotSpeed = 8.0f;
	//�藠���������鑬�x
	constexpr float kDropSpeed = 0.6f;
	//�o�E���h���鑬�x
	constexpr float kBoundSpeed = 3.0f;
	//�����x
	constexpr float kAcceleration = 30.0f;
}

void ShotBound::init()
{
	//�藠�����ˊm�F
	count = 0;
}

//�V���b�g�J�n
void ShotBound::start(Vec2 pos)
{
	ShotBase::start(pos);

	float randAngle = static_cast<float>(GetRand(359));
	float rad = randAngle * DX_PI_F / 180.0; //���W�A��

	m_vec.x = -kShotSpeed;
	m_vec.y = 0.0f;
}
// �X�V
void ShotBound::update()
{
	if (!m_isExist) return;
	m_pos -= m_vec;

	m_vec.y -= kDropSpeed;

	if (m_pos.y >= 0)
	{
		m_vec.y += kBoundSpeed;
	}
}