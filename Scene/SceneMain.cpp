#include "SceneMain.h"
#include "SceneResult.h"
#include "DxLib.h"
#include "Pad.h"
#include "mino.h"
#include "stage.h"

SceneMain::SceneMain()
{
	m_pMino = new Mino;
	m_pStage = new Stage;
}

SceneMain::~SceneMain()
{
	delete m_pMino;
	delete m_pStage;
}

// ‰Šú‰»
void SceneMain::init()
{
	//m_pStage->init();
	m_pMino->init();
}

// I—¹ˆ—
void SceneMain::end()
{
	//m_pStage->end();
	m_pMino->end();
}

// XVˆ—
SceneBase* SceneMain::update()
{
	//m_pStage->update();
	m_pMino->update();
	if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneResult);
	}
	return this;
}

// •`‰æˆ—
void SceneMain::draw()
{
	DrawString(0, 0, "SceneMain", GetColor(255, 255, 255));
	//m_pStage->draw();
	m_pMino->makeMino();
	m_pMino->draw();
}