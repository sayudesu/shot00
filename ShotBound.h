#pragma once

#include "ShotBase.h"

class ShotBound : public ShotBase
{
public:
	ShotBound() { }
	virtual ~ShotBound() { }
	//������
	virtual void init();
	//�V���b�g�J�n
	virtual void start(Vec2 pos);
	// �X�V
	virtual void update();

	//���ˊm�F
	int count;

};