// �~�m
#pragma once
#include "common.h"

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
};