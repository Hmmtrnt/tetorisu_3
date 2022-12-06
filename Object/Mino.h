// �~�m
#pragma once
#include "common.h"

class Stage;

class Mino
{
public:
	Mino();
	virtual ~Mino();
	
	// ������
	void init();
	// �I������
	void end();
	// �X�V����
	void update();
	// �`��
	void draw();
	// �~�m����
	void makeMino();
	// �~�m�̓���
	void moveMino();
	//�~�m�̑���
	void operateMino();
	// ���̓����蔻��
	void hitLeft();
	// �E�̓����蔻��
	void hitRight();

private:
	// �~�m�̔z��̎󂯎��
	int m_minoArray[BLOCK_HEIGHT][BLOCK_WIDTH];
	// �~�m�̍��W
	int m_posX;
	int m_posY;

	// �\���p
	float m_countY;
	// �~�m�̗������x
	float m_speedY;

	// ����ɂ����������ǂ���
	bool m_hitFlag;
	int flag;

	// �X�e�[�W�̃|�C���^
	Stage* m_pStage;
};