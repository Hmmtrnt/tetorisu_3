#include "Stage.h"
#include "common.h"

Stage::Stage() :
	m_backHandle(-1)
{
}

Stage::~Stage()
{
}

void Stage::init()
{
	m_backHandle = LoadGraph("data/back2.jpg");
}

void Stage::end()
{
	DeleteGraph(m_backHandle);
}

void Stage::update()
{
}

void Stage::draw()
{
	DrawGraph(0, 0, m_backHandle, true);
}
