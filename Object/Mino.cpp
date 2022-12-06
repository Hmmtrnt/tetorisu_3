#include "Mino.h"
#include "Stage.h"
#include "Pad.h"

Mino::Mino() :
	m_posX(0),
	m_posY(0),
	m_downFlame(0),
	m_countY(0.0f),
	m_speedY(0.0f),
	m_hitFlag(false),
	m_noFallFlag(false)
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
	m_downFlame = 60;
	m_countY = 0.0f;
	m_speedY = 0.5f;
	m_hitFlag = false;
	m_noFallFlag = true;
	m_pStage->init();
}

void Mino::initVar2()
{
	m_posX = 4;
	m_posY = 0;
	m_countY = 0;
	m_noFallFlag = true;
}

void Mino::end()
{
	m_pStage->end();
}

void Mino::update()
{
	moveMino();
	operateMino();
	m_pStage->update();
}

void Mino::draw()
{
	// ---------------------------------------------
	// �Q�[���`��
	// ---------------------------------------------
	// �X�e�[�W�`��
	m_pStage->draw();

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

	// ---------------------------------------------
	// �m�F�p�`��
	// ---------------------------------------------
	DrawFormatString(300, 0, color::kColor_Black, "m_posX = %d", m_posX);
	DrawFormatString(300, 20, color::kColor_Black, "m_posY = %d", m_posY);
	DrawFormatString(300, 40, color::kColor_Black, "m_countY = %d", m_countY);
}

// �~�m�̓���
void Mino::makeMino()
{
	if (m_noFallFlag)
	{
		for (int y = 0; y < BLOCK_HEIGHT; y++)
		{
			for (int x = 0; x < BLOCK_WIDTH; x++)
			{
				m_minoArray[y][x] = kMino::kMinos[y][x];
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

void Mino::fixMino()
{
	hitBottom();
	if (!m_hitFlag)
	{
		saveMino();
		initVar2();
	}
}

// �~�m�̑���
void Mino::operateMino()
{
	hitBottom();
	if (!m_hitFlag)
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
		if (Pad::isPress(PAD_INPUT_DOWN) == 1)
		{
			m_countY += DRAW_BLOCK_WIDTH;	
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
				}
			}
		}
	}
}