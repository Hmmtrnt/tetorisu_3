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
	// 二個目以降に必要な初期化
	void initVar2();
	// 終了処理
	void end();
	// 更新処理
	void update();
	// 描画
	void draw();
	// ゲームオーバー処理
	void gameOver();
	// ミノ生成
	void makeMino();
	// ミノの保存
	void saveMino();
	// ミノの自由落下
	void moveMino();
	// ミノの固定
	void fixMino();
	// ミノの操作
	void operateMino();
	// ミノを消去する行のサーチ
	void searchMino();
	// ミノを消去
	void breakMino();
	// 左の当たり判定
	void hitLeft();
	// 右の当たり判定
	void hitRight();
	// 底辺の当たり判定
	void hitBottom();
	// 上辺の当たり判定
	void hitTop();

	// ゲームオーバー情報取得
	bool getGameOver() { return m_gameOverFlag; }

private:
	// ミノの配列の受け取り
	int m_minoArray[BLOCK_HEIGHT][BLOCK_WIDTH];
	// ミノの座標
	int m_posX;
	int m_posY;
	// ミノの落ちるフレーム
	int m_downFlame;
	// ミノが底辺に落ちた時の時間
	int m_hitBottomTime;
	// ミノ
	int breakCount;
	// ミノの種類
	int m_id;
	// ミノがそろった列
	int m_lineMino[STAGE_HEIGHT - 1];

	// 表示用
	float m_countY;
	// ミノの落下速度
	float m_speedY;

	// 判定にあたったかどうか
	bool m_hitFlag;
	// ゲームオーバー判定に当たったかどうか
	bool m_gameOverHitFlag;
	// 落ちていないミノがあるかどうか
	bool m_noFallFlag;
	// ゲームオーバー
	bool m_gameOverFlag;
	// 列のミノが消えたかどうか
	bool m_clearMinoFlag;

	// ステージのポインタ
	Stage* m_pStage;
};