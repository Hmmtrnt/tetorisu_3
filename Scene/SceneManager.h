// �Q�[���}�l�[�W���[
#pragma once

class SceneBase;

class SceneManager
{
public:
	SceneManager();
	virtual ~SceneManager() {}

	void init();		// ������
	void end();			// �I��
	void update();		// ���t���[���̏���
	void draw();		// �`��

private:
	// �V�[���x�[�X�|�C���^
	SceneBase* m_pScene;
};