// ����
#pragma once
#include "DxLib.h"

// �~�m�̕�
#define BLOCK_HEIGHT	4		// �c
#define BLOCK_WIDTH		4		// ��

// �~�m�̎��
#define BLOCK_TYPE 7
#define BLOCK_ROTATE_TYPE 4

// �X�e�[�W�̕�
#define STAGE_HEIGHT 21
#define STAGE_WIDTH 12

// �`�悷��~�m���m�̕�
#define DRAW_BLOCK_WIDTH 20

namespace kMino
{
	// �~�m�̑傫��
	constexpr int kBlockHeight = 4;		// �c
	constexpr int kBlockWidth = 4;		// ��

	// �F
	const int kColor_Red = GetColor(255, 0, 0);		// ��
	const int kColor_Black = GetColor(0, 0, 0);		// ��

	// �~�m�̌`
	constexpr int kMinos[BLOCK_HEIGHT * BLOCK_TYPE][BLOCK_WIDTH * BLOCK_ROTATE_TYPE] = {
		// O�~�m	�˂���ȍ~�͉�]�����~�m
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,1,1,0,	0,1,1,0,	0,1,1,0,	0,1,1,0},
		{0,1,1,0,	0,1,1,0,	0,1,1,0,	0,1,1,0},
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		// I�~�m
		{0,0,0,0,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		{0,0,0,0,	0,2,0,0,	2,2,2,2,	0,0,2,0},
		{2,2,2,2,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		{0,0,0,0,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		// S�~�m
		{0,0,0,0,	3,0,0,0,	0,0,0,0,	0,3,0,0},
		{0,3,3,0,	3,3,0,0,	0,3,3,0,	0,3,3,0},
		{3,3,0,0,	0,3,0,0,	3,3,0,0,	0,0,3,0},
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		// Z�~�m
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{4,4,0,0,	0,4,0,0,	4,4,0,0,	0,0,4,0},
		{0,4,4,0,	4,4,0,0,	0,4,4,0,	0,4,4,0},
		{0,0,0,0,	4,0,0,0,	0,0,0,0,	0,4,0,0},
		// J�~�m
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{5,0,0,0,	0,5,5,0,	0,0,0,0,	0,5,0,0},
		{5,5,5,0,	0,5,0,0,	5,5,5,0,	0,5,0,0},
		{0,0,0,0,	0,5,0,0,	0,0,5,0,	5,5,0,0},
		// L�~�m
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,0,6,0,	0,6,0,0,	0,0,0,0,	6,6,0,0},
		{6,6,6,0,	0,6,0,0,	6,6,6,0,	0,6,0,0},
		{0,0,0,0,	0,6,6,0,	6,0,0,0,	0,6,0,0},
		// T�~�m
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,7,0,0,	0,7,0,0,	0,0,0,0,	0,7,0,0},
		{7,7,7,0,	0,7,7,0,	7,7,7,0,	7,7,0,0},
		{0,0,0,0,	0,7,0,0,	0,7,0,0,	0,7,0,0},
	};
	// �e�X�g�p�~�m
	/*constexpr int kMinos[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{1,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};*/
}

namespace color
{
	// �~�m
	const int kColor_Yellow = GetColor(255, 255, 0);	// ��O
	const int kColor_LightBlue = GetColor(0, 0, 120);	// ��I
	const int kColor_Green = GetColor(0, 200, 0);		// ��S
	const int kColor_Red = GetColor(255, 0, 0);			// ��Z
	const int kColor_Blue = GetColor(0, 0, 255);		// ��J
	const int kColor_Orange = GetColor(255, 120, 0);	// ��L
	const int kColor_Purple = GetColor(255, 0, 255);	// ��T

	// �X�e�[�W
	const int kColor_Black = GetColor(0, 0, 0);			// ��
}