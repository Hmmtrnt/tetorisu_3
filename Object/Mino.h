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
	// ��ڈȍ~�ɕK�v�ȏ�����
	void initVar2();
	// �I������
	void end();
	// �X�V����
	void update();
	// �`��
	void draw();
	// �~�m����
	void makeMino();
	// �~�m�̕ۑ�
	void saveMino();
	// �~�m�̎��R����
	void moveMino();
	// �~�m�̌Œ�
	void fixMino();
	// �~�m�̑���
	void operateMino();
	// ���̓����蔻��
	void hitLeft();
	// �E�̓����蔻��
	void hitRight();
	// ��ӂ̓����蔻��
	void hitBottom();

private:
	// �~�m�̔z��̎󂯎��
	int m_minoArray[BLOCK_HEIGHT][BLOCK_WIDTH];
	// �~�m�̍��W
	int m_posX;
	int m_posY;
	// �~�m�̗�����t���[��
	int m_downFlame;

	// �\���p
	float m_countY;
	// �~�m�̗������x
	float m_speedY;

	// ����ɂ����������ǂ���
	bool m_hitFlag;
	// �����Ă��Ȃ��~�m�����邩�ǂ���
	bool m_noFallFlag;

	// �X�e�[�W�̃|�C���^
	Stage* m_pStage;
};