#include "Mino.h"
#include "Stage.h"
#include "Pad.h"

Mino::Mino() :
	m_posX(0),
	m_posY(0),
	m_countY(0.0f),
	m_speedY(0.0f),
	m_hitFlag(false),
	flag(0)
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_minoArray[y][x] = 0;
		}
	}
	m_pStage = new Stage;
}

Mino::~Mino()
{
	delete m_pStage;
}

void Mino::init()
{
	m_posX = 4;
	m_posY = 0;
	m_countY = 0.0f;
	m_speedY = 0.5f;
	m_hitFlag = false;
	flag = 0;
}

void Mino::end()
{
}

void Mino::update()
{
	moveMino();
	operateMino();
	if (m_posY >= 17)
	{
		m_speedY = 0;
	}
}

void Mino::draw()
{
	// ---------------------------------------------
	// �m�F�p�`��
	// ---------------------------------------------
	DrawFormatString(300, 0, color::kColor_Black, "m_posX = %d", m_posX);
	DrawFormatString(300, 20, color::kColor_Black, "m_posY = %d", m_posY);
	DrawFormatString(300, 40, color::kColor_Black, "m_countY = %d", m_countY);

	// ---------------------------------------------
	// �Q�[���`��
	// ---------------------------------------------
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_minoArray[y][x] == 1)
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH, 
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_Red, "��");
			}
		}
	}
}

void Mino::makeMino()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_minoArray[y][x] = kMino::kMinos[y][x];
		}
	}
}

void Mino::moveMino()
{
	m_countY += m_speedY;
	m_posY = (int)m_countY / DRAW_BLOCK_WIDTH;
}

// �~�m�̑���
void Mino::operateMino()
{
	if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		hitLeft();
		if (!m_hitFlag)
		{
			m_posX--;
		}
	}
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		hitRight();
		if (!m_hitFlag)
		{
			m_posX++;
		}
	}
}

// ���̕ǔ���
void Mino::hitLeft()
{
	m_hitFlag = false;
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_minoArray[y][x] != 0)
			{
				if (m_pStage->m_stageArray[m_posY + y][m_posX + (x - 1)] != 0)
				{
					m_hitFlag = true;
				}
				// �~�m�̊Ԃɓ��荞�܂Ȃ��悤�ɂ���
				else if ((int)(m_countY - (m_posY * DRAW_BLOCK_WIDTH)) > 0)
				{
					if (m_pStage->m_stageArray[m_posY + y][m_posX + (x - 1)] != 0)
					{
						m_hitFlag = true;
					}
				}
			}
		}
	}
}

// �E�̕ǔ���
void Mino::hitRight()
{
	m_hitFlag = false;
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_minoArray[y][x] != 0)
			{
				if (m_pStage->m_stageArray[m_posY + y][m_posX + (x + 1)] != 0)
				{
					m_hitFlag = true;
				}
				// �~�m�̊Ԃɓ��荞�܂Ȃ��悤�ɂ���
				else if ((int)(m_countY - (m_posY * DRAW_BLOCK_WIDTH)) > 0)
				{
					if (m_pStage->m_stageArray[m_posY + y][m_posX + (x + 1)] != 0)
					{
						m_hitFlag = true;
					}
				}
			}
		}
	}
}
