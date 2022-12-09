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
	// �Q�[���I�[�o�[����
	void gameOver();
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
	// �~�m�̏���
	void breakMino();
	// ���̓����蔻��
	void hitLeft();
	// �E�̓����蔻��
	void hitRight();
	// ��ӂ̓����蔻��
	void hitBottom();
	// ��ӂ̓����蔻��
	void hitTop();

	// �Q�[���I�[�o�[���擾
	bool getGameOver() { return m_gameOverFlag; }

private:
	// �~�m�̔z��̎󂯎��
	int m_minoArray[BLOCK_HEIGHT][BLOCK_WIDTH];
	// �~�m�̍��W
	int m_posX;
	int m_posY;
	// �~�m�̗�����t���[��
	int m_downFlame;
	// �~�m����ӂɗ��������̎���
	int m_hitBottomTime;
	// �~�m�̎��
	int m_id;
	// �~�m�����������
	int m_lineMino[20];

	// �\���p
	float m_countY;
	// �~�m�̗������x
	float m_speedY;

	// ����ɂ����������ǂ���
	bool m_hitFlag;
	// �����Ă��Ȃ��~�m�����邩�ǂ���
	bool m_noFallFlag;
	// �Q�[���I�[�o�[
	bool m_gameOverFlag;
	// ��̃~�m�����������ǂ���
	bool m_clearMinoFlag;

	// �X�e�[�W�̃|�C���^
	Stage* m_pStage;
};