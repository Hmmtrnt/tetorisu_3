#include "Mino.h"
#include "Stage.h"
#include "Pad.h"

Mino::Mino() :
	m_posX(0),
	m_posY(0),
	m_downFlame(0),
	m_hitBottomTime(0),
	m_countY(0.0f),
	m_speedY(0.0f),
	m_hitFlag(false),
	m_noFallFlag(false),
	m_gameOver(false)
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
	m_posY = -1;
	m_downFlame = 60;
	m_hitBottomTime = 120;
	m_countY = 0.0f;
	m_speedY = 0.5f;
	m_hitFlag = false;
	m_noFallFlag = true;
	m_gameOver = false;
	m_pStage->init();
}

void Mino::initVar2()
{
	m_posX = 4;
	m_posY = -1;
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
	/*gameOver();
	if (m_gameOver)
	{
		DrawString(300, 60, "GAME OVER", GetColor(0, 0, 0));
	}*/
}

void Mino::draw()
{
	// ---------------------------------------------
	// ƒQ[ƒ€•`‰æ
	// ---------------------------------------------
	// ƒXƒe[ƒW•`‰æ
	m_pStage->draw();

	// ƒ~ƒm‚Ì•`‰æ
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_minoArray[y][x] == 1)
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH, 
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_Red, "¡");
			}
		}
	}

	// ---------------------------------------------
	// Šm”F—p•`‰æ
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
		m_gameOver = 1;
	}
}

// ƒ~ƒm‚Ì“®‚«
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

// ƒ~ƒm‚Ì•Û‘¶
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

// ƒ~ƒm‚ÌŽ©—R—Ž‰º
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

// ƒ~ƒm‚ÌŒÅ’è
void Mino::fixMino()
{
	hitBottom();
	if (m_hitFlag)
	{
		saveMino();
		initVar2();
	}
}

// ƒ~ƒm‚Ì‘€ì
void Mino::operateMino()
{
	hitBottom();
	if (!m_hitFlag)
	{
		// ¶
		if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
		{
			hitLeft();
			if (!m_hitFlag)
			{
				m_posX--;
			}
		}
		// ‰E
		if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
		{
			hitRight();
			if (!m_hitFlag)
			{
				m_posX++;
			}
		}
		// —Ž‰º‘¬“xã¸
		if (Pad::isPress(PAD_INPUT_DOWN) == 1)
		{
			m_countY += DRAW_BLOCK_WIDTH;	
		}
	}
	
}

// ¶‚Ì•Ç”»’è
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

// ‰E‚Ì•Ç”»’è
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

// ’ê•Ó‚Ì“–‚½‚è”»’è
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