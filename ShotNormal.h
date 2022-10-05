#pragma once

#include "ShotBase.h"

class ShotNormal : public ShotBase
{
public:
	ShotNormal(){ }
	virtual ~ShotNormal(){ }
	//初期化
	virtual void init();
	//ショット開始
	virtual void start(Vec2 pos);
	// 更新
	virtual void update();
	
	//発射確認
	int count;

};