#include "SceneMain.h"
#include "SceneResult.h"
#include "DxLib.h"
#include "Pad.h"
#include "mino.h"
#include "stage.h"

SceneMain::SceneMain()
{
	m_pMino = new Mino;
}

SceneMain::~SceneMain()
{
	delete m_pMino;
}

// 初期化
void SceneMain::init()
{
	m_pMino->init();
}

// 終了処理
void SceneMain::end()
{
	m_pMino->end();
}

// 更新処理
SceneBase* SceneMain::update()
{
	m_pMino->update();
	m_pMino->hitTop();
	if (m_pMino->getGameOver())
	{
		return (new SceneResult);
	}
	/*if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneResult);
	}*/
	return this;
}

// 描画処理
void SceneMain::draw()
{
	DrawString(0, 0, "SceneMain", GetColor(255, 255, 255));
	m_pMino->makeMino();
	m_pMino->draw();
}