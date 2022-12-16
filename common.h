// ã§í 
#pragma once
#include "DxLib.h"

// É~ÉmÇÃïù
#define BLOCK_HEIGHT	4		// èc
#define BLOCK_WIDTH		4		// â°

// É~ÉmÇÃéÌóﬁ
#define BLOCK_TYPE 7
#define BLOCK_ROTATE_TYPE 4

// ÉXÉeÅ[ÉWÇÃïù
#define STAGE_HEIGHT 21
#define STAGE_WIDTH 12

// ï`âÊÇ∑ÇÈÉ~ÉmìØémÇÃïù
#define DRAW_BLOCK_WIDTH 20

namespace kMino
{
	// É~ÉmÇÃëÂÇ´Ç≥
	constexpr int kBlockHeight = 4;		// èc
	constexpr int kBlockWidth = 4;		// â°

	// êF
	const int kColor_Red = GetColor(255, 0, 0);		// ê‘
	const int kColor_Black = GetColor(0, 0, 0);		// çï

	// É~ÉmÇÃå`
	constexpr int kMinos[BLOCK_HEIGHT * BLOCK_TYPE][BLOCK_WIDTH * BLOCK_ROTATE_TYPE] = {
		// OÉ~Ém	ÅÀÇ±ÇÍà»ç~ÇÕâÒì]ÇµÇΩÉ~Ém
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,1,1,0,	0,1,1,0,	0,1,1,0,	0,1,1,0},
		{0,1,1,0,	0,1,1,0,	0,1,1,0,	0,1,1,0},
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		// IÉ~Ém
		{0,0,0,0,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		{0,0,0,0,	0,2,0,0,	2,2,2,2,	0,0,2,0},
		{2,2,2,2,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		{0,0,0,0,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		// SÉ~Ém
		{0,0,0,0,	3,0,0,0,	0,0,0,0,	0,3,0,0},
		{0,3,3,0,	3,3,0,0,	0,3,3,0,	0,3,3,0},
		{3,3,0,0,	0,3,0,0,	3,3,0,0,	0,0,3,0},
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		// ZÉ~Ém
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{4,4,0,0,	0,4,0,0,	4,4,0,0,	0,0,4,0},
		{0,4,4,0,	4,4,0,0,	0,4,4,0,	0,4,4,0},
		{0,0,0,0,	4,0,0,0,	0,0,0,0,	0,4,0,0},
		// JÉ~Ém
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{5,0,0,0,	0,5,5,0,	0,0,0,0,	0,5,0,0},
		{5,5,5,0,	0,5,0,0,	5,5,5,0,	0,5,0,0},
		{0,0,0,0,	0,5,0,0,	0,0,5,0,	5,5,0,0},
		// LÉ~Ém
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,0,6,0,	0,6,0,0,	0,0,0,0,	6,6,0,0},
		{6,6,6,0,	0,6,0,0,	6,6,6,0,	0,6,0,0},
		{0,0,0,0,	0,6,6,0,	6,0,0,0,	0,6,0,0},
		// TÉ~Ém
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,7,0,0,	0,7,0,0,	0,0,0,0,	0,7,0,0},
		{7,7,7,0,	0,7,7,0,	7,7,7,0,	7,7,0,0},
		{0,0,0,0,	0,7,0,0,	0,7,0,0,	0,7,0,0},
	};
	// ÉeÉXÉgópÉ~Ém
	/*constexpr int kMinos[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{1,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};*/
}

namespace color
{
	// É~Ém
	const int kColor_Yellow = GetColor(255, 255, 0);	// â©O
	const int kColor_LightBlue = GetColor(0, 0, 120);	// êÖI
	const int kColor_Green = GetColor(0, 200, 0);		// óŒS
	const int kColor_Red = GetColor(255, 0, 0);			// ê‘Z
	const int kColor_Blue = GetColor(0, 0, 255);		// ê¬J
	const int kColor_Orange = GetColor(255, 120, 0);	// ûÚL
	const int kColor_Purple = GetColor(255, 0, 255);	// éáT

	// ÉXÉeÅ[ÉW
	const int kColor_Black = GetColor(0, 0, 0);			// çï
}