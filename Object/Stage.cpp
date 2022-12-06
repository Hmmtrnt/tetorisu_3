#include "Stage.h"
#include "common.h"

Stage::Stage() :
	m_backHandle(-1)
{
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			m_stageArray[y][x] = 0;
		}
	}
}

Stage::~Stage()
{
}

void Stage::init()
{
	// ”Õ–Ê‚ÌŠO˜g
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			m_stageArray[y][0] = 9;
			m_stageArray[y][11] = 9;
			m_stageArray[20][x] = 9;
		}
	}
	// ”wŒi‚Ìƒnƒ“ƒhƒ‹
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

	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			if (m_stageArray[y][x] == 1)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, color::kColor_Red, "¡");
			}
			else if (m_stageArray[y][x] == 9)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, color::kColor_Black, "¡");
			}
		}
	}
}
