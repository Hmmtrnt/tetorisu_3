#include "SceneResult.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "DxLib.h"
#include "Pad.h"

SceneResult::SceneResult()
{

}

SceneResult::~SceneResult()
{

}

// ������
void SceneResult::init()
{

}

// �I������
void SceneResult::end()
{

}

// �X�V����
SceneBase* SceneResult::update()
{
	if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneTitle);
	}
	else if (Pad::isTrigger(PAD_INPUT_1))
	{
		return (new SceneMain);
	}

	return this;
}

// �`�揈��
void SceneResult::draw()
{
	DrawString(0, 0, "SceneResult", GetColor(255, 255, 255));
}