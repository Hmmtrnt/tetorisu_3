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
	// ?Ֆʂ̊O?g
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			m_stageArray[y][0] = 9;
			m_stageArray[y][11] = 9;
			m_stageArray[20][x] = 9;
		}
	}
	// ?w?i?̃n???h??
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
								 y * DRAW_BLOCK_WIDTH, color::kColor_Yellow, "??");
			}
			if (m_stageArray[y][x] == 2)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, color::kColor_LightBlue, "??");
			}
			if (m_stageArray[y][x] == 3)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, color::kColor_Green, "??");
			}
			if (m_stageArray[y][x] == 4)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, color::kColor_Red, "??");
			}
			if (m_stageArray[y][x] == 5)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, color::kColor_Blue, "??");
			}
			if (m_stageArray[y][x] == 6)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, color::kColor_Orange, "??");
			}
			if (m_stageArray[y][x] == 7)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, color::kColor_Purple, "??");
			}
			else if (m_stageArray[y][x] == 9)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, color::kColor_Black, "??");
			}
		}
	}
}
