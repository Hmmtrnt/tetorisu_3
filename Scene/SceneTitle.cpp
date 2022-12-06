#include "SceneTitle.h"
#include "SceneMain.h"
#include "DxLib.h"
#include "Pad.h"

SceneTitle::SceneTitle()
{

}

SceneTitle::~SceneTitle()
{

}

// ������
void SceneTitle::init()
{

}

// �I������
void SceneTitle::end()
{

}

// �X�V����
SceneBase* SceneTitle::update()
{
	if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneMain);
	}

	return this;
}

// �`��
void SceneTitle::draw()
{
	DrawString(0, 0, "�e�g���X", GetColor(255, 255, 255));
}