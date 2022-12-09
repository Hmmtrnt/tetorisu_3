// 共通
#pragma once
#include "DxLib.h"

// ミノの幅
#define BLOCK_HEIGHT	4		// 縦
#define BLOCK_WIDTH		4		// 横

// ミノの種類
#define BLOCK_TYPE 7
#define BLOCK_ROTATE_TYPE 4

// ステージの幅
#define STAGE_HEIGHT 21
#define STAGE_WIDTH 12

// 描画するミノ動詞の幅
#define DRAW_BLOCK_WIDTH 20

namespace kMino
{
	// ミノの大きさ
	constexpr int kBlockHeight = 4;		// 縦
	constexpr int kBlockWidth = 4;		// 横

	// 色
	const int kColor_Red = GetColor(255, 0, 0);		// 赤
	const int kColor_Black = GetColor(0, 0, 0);		// 黒

	// ミノの形
	constexpr int kMinos[BLOCK_HEIGHT * BLOCK_TYPE][BLOCK_WIDTH * BLOCK_ROTATE_TYPE] = {
		// Oミノ	⇒これ以降は回転したミノ
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,1,1,0,	0,1,1,0,	0,1,1,0,	0,1,1,0},
		{0,1,1,0,	0,1,1,0,	0,1,1,0,	0,1,1,0},
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		// Iミノ
		{0,0,0,0,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		{0,0,0,0,	0,2,0,0,	2,2,2,2,	0,0,2,0},
		{2,2,2,2,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		{0,0,0,0,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		// Sミノ
		{0,0,0,0,	3,0,0,0,	0,0,0,0,	0,3,0,0},
		{0,3,3,0,	3,3,0,0,	0,3,3,0,	0,3,3,0},
		{3,3,0,0,	0,3,0,0,	3,3,0,0,	0,0,3,0},
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		// Zミノ
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{4,4,0,0,	0,4,0,0,	4,4,0,0,	0,0,4,0},
		{0,4,4,0,	4,4,0,0,	0,4,4,0,	0,4,4,0},
		{0,0,0,0,	4,0,0,0,	0,0,0,0,	0,4,0,0},
		// Jミノ
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{5,0,0,0,	0,5,5,0,	0,0,0,0,	0,5,0,0},
		{5,5,5,0,	0,5,0,0,	5,5,5,0,	0,5,0,0},
		{0,0,0,0,	0,5,0,0,	0,0,5,0,	5,5,0,0},
		// Lミノ
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,0,6,0,	0,6,0,0,	0,0,0,0,	6,6,0,0},
		{6,6,6,0,	0,6,0,0,	6,6,6,0,	0,6,0,0},
		{0,0,0,0,	0,6,6,0,	6,0,0,0,	0,6,0,0},
		// Tミノ
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,7,0,0,	0,7,0,0,	0,0,0,0,	0,7,0,0},
		{7,7,7,0,	0,7,7,0,	7,7,7,0,	7,7,0,0},
		{0,0,0,0,	0,7,0,0,	0,7,0,0,	0,7,0,0},
	};
	// テスト用ミノ
	/*constexpr int kMinos[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{1,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};*/
}

namespace color
{
	// ミノ
	const int kColor_Yellow = GetColor(255, 255, 0);	// 黄O
	const int kColor_LightBlue = GetColor(0, 0, 120);	// 水I
	const int kColor_Green = GetColor(0, 200, 0);		// 緑S
	const int kColor_Red = GetColor(255, 0, 0);			// 赤Z
	const int kColor_Blue = GetColor(0, 0, 255);		// 青J
	const int kColor_Orange = GetColor(255, 120, 0);	// 橙L
	const int kColor_Purple = GetColor(255, 0, 255);	// 紫T

	// ステージ
	const int kColor_Black = GetColor(0, 0, 0);			// 黒
}