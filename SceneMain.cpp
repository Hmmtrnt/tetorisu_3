#include "SceneMain.h"
#include "SceneResult.h"
#include "DxLib.h"
#include "Pad.h"
//#include "mino.h"
//#include "stage.h"

SceneMain::SceneMain()
{
	
}

SceneMain::~SceneMain()
{
	
}

// ‰Šú‰»
void SceneMain::init()
{
	
}

// I—¹ˆ—
void SceneMain::end()
{
	
}

// XVˆ—
SceneBase* SceneMain::update()
{
	
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
}