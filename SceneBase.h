// �V�[���̊��N���X
#pragma once

class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();

	virtual void init();		// ������
	virtual void end();			// �I������
	virtual SceneBase* update();		// �X�V����
	virtual void draw();		// �`��
};