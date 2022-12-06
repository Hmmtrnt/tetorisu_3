// �X�e�[�W
#pragma once
#include "common.h"

class Stage
{
public:
	Stage();
	virtual ~Stage();

	// ����������
	void init();
	// �I������
	void end();
	// �X�V����
	void update();
	// �`�揈��
	void draw();

	// �X�e�[�W�̔z��
	int m_stageArray[STAGE_HEIGHT][STAGE_WIDTH];

private:
	// �w�i�̃n���h��
	int m_backHandle;
};