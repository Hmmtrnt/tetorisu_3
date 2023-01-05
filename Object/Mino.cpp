#include "Mino.h"
#include "Stage.h"
#include "Pad.h"

Mino::Mino() :
	m_posX(0),
	m_posY(0),
	m_downFlame(0),
	m_hitBottomTime(0),
	breakCount(0),
	m_id(0),
	m_countY(0.0f),
	m_speedY(0.0f),
	m_hitFlag(false),
	m_gameOverHitFlag(false),
	m_noFallFlag(false),
	m_gameOverFlag(false),
	m_clearMinoFlag(false)
{
	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
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
	breakCount = 0;
	m_countY = 0.0f;
	m_speedY = 0.5f;
	m_hitFlag = false;
	m_gameOverHitFlag = false;
	m_noFallFlag = true;
	m_gameOverFlag = false;
	m_clearMinoFlag = false;
	m_pStage->init();
}

void Mino::initVar2()
{
	m_posX = 4;
	m_posY = 0;
	//breakCount = 0;
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
	if (!m_clearMinoFlag)
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
	else
	{
		breakMino();
		m_pStage->draw();
	}
	
	
}

void Mino::draw()
{
	// ---------------------------------------------
	// ゲーム描画
	// ---------------------------------------------
	// ステージ描画
	m_pStage->draw();

	// ミノの描画
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_minoArray[y][x] == 1)
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH, 
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_Yellow, "■");
			}
			if (m_minoArray[y][x] == 2) 
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_LightBlue, "■");
			}
			if (m_minoArray[y][x] == 3)
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_Green, "■");
			}
			if (m_minoArray[y][x] == 4)
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_Red, "■");
			}
			if (m_minoArray[y][x] == 5)
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_Blue, "■");
			}
			if (m_minoArray[y][x] == 6)
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_Orange, "■");
			}
			if (m_minoArray[y][x] == 7)
			{
				DrawFormatString(m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 (int)m_countY + y * DRAW_BLOCK_WIDTH, color::kColor_Purple, "■");
			}
		}
	}

	// ---------------------------------------------
	// 確認用描画
	// ---------------------------------------------
	DrawFormatString(300, 0, color::kColor_Black, "m_posX = %d", m_posX);
	DrawFormatString(300, 20, color::kColor_Black, "m_posY = %d", m_posY);
	DrawFormatString(300, 40, color::kColor_Black, "m_countY = %d", m_countY);
}

void Mino::gameOver()
{
	//hitTop();
	if (m_gameOverHitFlag)
	{
		m_gameOverFlag = true;
	}
}

// ミノの動き
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

// ミノの保存
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

// ミノの自由落下
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

// ミノの固定
void Mino::fixMino()
{
	hitBottom();
	if (m_hitFlag)
	{
		saveMino();
		searchMino();
		if (!m_clearMinoFlag)
		{
			initVar2();
		}
		/*else
		{
			breakMino();
			m_clearMinoFlag = false;
		}*/
	}
}

// ミノの操作
void Mino::operateMino()
{
	hitBottom();
	if (!m_hitFlag)
	{
		// 左
		if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
		{
			hitLeft();
			if (!m_hitFlag)
			{
				m_posX--;
			}
		}
		// 右
		if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
		{
			hitRight();
			if (!m_hitFlag)
			{
				m_posX++;
			}
		}
		// 落下速度上昇
		if (Pad::isPress(PAD_INPUT_DOWN) == 1)
		{
			m_countY += DRAW_BLOCK_WIDTH;	
		}
	}
	
}

// 消去する列の確認
// m_lineMino[i] = 1; 確認済
// m_lineMino[i] = 0; 消去するべき列
void Mino::searchMino()
{
	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
	{
		m_lineMino[i] = 0;
	}
	// 揃っている列の捜索
	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
	{
		for (int j = 1; j < STAGE_WIDTH - 1; j++)
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
			/*if (m_clearMinoFlag)
			{
				printfDx("成功");
			}*/
			break;
		}
	}
}

// ミノの消去
void Mino::breakMino()
{
	int remain_line_point[20] = { 0 };
	int remain_line_index = 0;

	if (breakCount < 10)
	{
		for (int i = 0; i < STAGE_HEIGHT - 1; i++)
		{
			if (m_lineMino[i] == 0)
			{
				m_pStage->m_stageArray[i][breakCount] = 0;
			}
		}
		breakCount++;
	}
	else
	{
		for (int i = STAGE_HEIGHT - 2; i >= 0; i--)
		{
			if (m_lineMino[i] != 0)
			{
				remain_line_point[remain_line_index] = i;
				remain_line_index++;
			}
		}
		remain_line_index = 0;
		for (int i = STAGE_HEIGHT - 1; i >= 0; i--)
		{
			for (int j = 1; j < STAGE_WIDTH - 1; j++)
			{
				m_pStage->m_stageArray[i][j] = m_pStage->m_stageArray[remain_line_point[remain_line_index]][j];
			}
			remain_line_index++;
		}
		m_clearMinoFlag = false;
		breakCount = 0;
		initVar2();
	}
}

// 左の壁判定
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

// 右の壁判定
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

// 底辺の当たり判定
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
	/*m_gameOverHitFlag = false;*/
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_minoArray[y][x] != 0)
			{
				if (m_pStage->m_stageArray[m_posY + y][m_posX + x] != 0)
				{
					m_gameOverHitFlag = true;
				}
			}
		}
	}
}