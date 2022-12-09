#include "Mino.h"
#include "Stage.h"
#include "Pad.h"

Mino::Mino() :
	m_posX(0),
	m_posY(0),
	m_downFlame(0),
	m_hitBottomTime(0),
	m_id(0),
	m_countY(0.0f),
	m_speedY(0.0f),
	m_hitFlag(false),
	m_noFallFlag(false),
	m_gameOverFlag(false),
	m_clearMinoFlag(false)
{
	for (int i = 0; i < 20; i++)
	{
		m_lineMino[i] = 0;
	}
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
	m_downFlame = 60;
	m_hitBottomTime = 120;
	m_countY = 0.0f;
	m_speedY = 0.5f;
	m_hitFlag = false;
	m_noFallFlag = true;
	m_gameOverFlag = false;
	m_clearMinoFlag = false;
	m_pStage->init();
}

void Mino::initVar2()
{
	m_posX = 4;
	m_posY = 0;
	//m_hitBottomTime = 120;
	m_countY = 0.0f;
	m_noFallFlag = true;
}

void Mino::end()
{
	m_pStage->end();
}

void Mino::update()
{
	
	if (m_noFallFlag)
	{
		makeMino();
	}
	moveMino();
	operateMino();
	m_pStage->update();
	fixMino();
	gameOver();
	
}

void Mino::draw()
{
	// ---------------------------------------------
	// �Q�[���`��
	// ---------------------------------------------
	// �X�e�[�W�`��
	m_pStage->draw();

	// �~�m�̕`��
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_minoArray[y][x] == 1)
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH, 
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_Yellow, "��");
			}
			if (m_minoArray[y][x] == 2) 
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_LightBlue, "��");
			}
			if (m_minoArray[y][x] == 3)
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_Green, "��");
			}
			if (m_minoArray[y][x] == 4)
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_Red, "��");
			}
			if (m_minoArray[y][x] == 5)
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_Blue, "��");
			}
			if (m_minoArray[y][x] == 6)
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_Orange, "��");
			}
			if (m_minoArray[y][x] == 7)
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_Purple, "��");
			}
		}
	}
	if (m_gameOverFlag)
	{
		DrawString(300, 60, "GAME OVER", GetColor(0, 0, 0));
	}

	// ---------------------------------------------
	// �m�F�p�`��
	// ---------------------------------------------
	DrawFormatString(300, 0, color::kColor_Black, "m_posX = %d", m_posX);
	DrawFormatString(300, 20, color::kColor_Black, "m_posY = %d", m_posY);
	DrawFormatString(300, 40, color::kColor_Black, "m_countY = %d", m_countY);
}

void Mino::gameOver()
{
	hitTop();
	if (m_hitFlag)
	{
		m_gameOverFlag = true;
	}
}

// �~�m�̓���
void Mino::makeMino()
{
	if (m_noFallFlag)
	{
		m_id = (rand() % BLOCK_TYPE);
		for (int y = 0; y < BLOCK_HEIGHT; y++)
		{
			for (int x = 0; x < BLOCK_WIDTH; x++)
			{
				m_minoArray[y][x] = kMino::kMinos[(m_id * BLOCK_HEIGHT) + y][x];
			}
		}
		m_noFallFlag = false;
	}
}

// �~�m�̕ۑ�
void Mino::saveMino()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_pStage->m_stageArray[m_posY + y][m_posX + x] += m_minoArray[y][x];
		}
	}
}

// �~�m�̎��R����
void Mino::moveMino()
{
	m_downFlame--;
	if (m_downFlame <= 0)
	{
		hitBottom();
		if (!m_hitFlag)
		{
			if (!m_noFallFlag)
			{
				m_downFlame = 60;
				m_countY += DRAW_BLOCK_WIDTH;
			}
		}
	}
	m_posY = (int)m_countY / DRAW_BLOCK_WIDTH;
}

// �~�m�̌Œ�
void Mino::fixMino()
{
	hitBottom();
	if (m_hitFlag)
	{
		saveMino();
		breakMino();
		if (!m_clearMinoFlag)
		{
			initVar2();
		}
	}
}

// �~�m�̑���
void Mino::operateMino()
{
	hitBottom();
	if (!m_hitFlag)
	{
		// ��
		if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
		{
			hitLeft();
			if (!m_hitFlag)
			{
				m_posX--;
			}
		}
		// �E
		if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
		{
			hitRight();
			if (!m_hitFlag)
			{
				m_posX++;
			}
		}
		// �������x�㏸
		if (Pad::isPress(PAD_INPUT_DOWN) == 1)
		{
			m_countY += DRAW_BLOCK_WIDTH;	
		}
	}
	
}

void Mino::breakMino()
{
	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
	{
		m_lineMino[i] = 0;
	}
	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
	{
		for (int j = 0; j < STAGE_WIDTH - 1; j++)
		{
			if (m_pStage->m_stageArray[i][j] == 0)
			{
				m_lineMino[i] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
	{
		if (m_lineMino[i] == 0)
		{
			m_clearMinoFlag = true;
			break;
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
			}
		}
	}
}

// ��ӂ̓����蔻��
void Mino::hitBottom()
{
	m_hitFlag = false;
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_minoArray[y][x] != 0)
			{
				if (m_pStage->m_stageArray[m_posY + (y + 1)][m_posX + x] != 0)
				{
					m_hitFlag = true;
					/*m_hitBottomTime--;
					if (m_hitBottomTime <= 0)
					{
						m_hitFlag = true;
						m_hitBottomTime = 120;
					}*/
				}
			}
		}
	}
}

void Mino::hitTop()
{
	m_hitFlag = false;
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_minoArray[y][x] != 0)
			{
				if (m_pStage->m_stageArray[m_posY + y][m_posX + x] != 0)
				{
					m_hitFlag = true;
				}
			}
		}
	}
}