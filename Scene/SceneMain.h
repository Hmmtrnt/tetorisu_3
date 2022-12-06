// ���C�����
#pragma once
#include "SceneBase.h"

class Mino;
class Stage;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init();			// ������
	virtual void end();				// �I������
	virtual SceneBase* update();	// �X�V����
	virtual void draw();			// �`�揈��

private:
	Mino* m_pMino;
	Stage* m_pStage;
};