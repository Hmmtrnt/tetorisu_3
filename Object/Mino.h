// ミノ
#pragma once
#include "common.h"

class Stage;

class Mino
{
public:
	Mino();
	virtual ~Mino();
	
	// 初期化
	void init();
	// 終了処理
	void end();
	// 更新処理
	void update();
	// 描画
	void draw();
	// ミノ生成
	void makeMino();
	// ミノの動き
	void moveMino();
	//ミノの操作
	void operateMino();
	// 左の当たり判定
	void hitLeft();
	// 右の当たり判定
	void hitRight();

private:
	// ミノの配列の受け取り
	int m_minoArray[BLOCK_HEIGHT][BLOCK_WIDTH];
	// ミノの座標
	int m_posX;
	int m_posY;

	// 表示用
	float m_countY;
	// ミノの落下速度
	float m_speedY;

	// 判定にあたったかどうか
	bool m_hitFlag;
	int flag;

	// ステージのポインタ
	Stage* m_pStage;
};