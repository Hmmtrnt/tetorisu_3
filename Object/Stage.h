// �X�e�[�W
#pragma once
class Stage
{
public:
	Stage();
	virtual ~Stage();

	// ����������
	void init();
	// �I������
	void end();
	// �X�V����
	void update();
	// �`�揈��
	void draw();

private:
	// �w�i�̃n���h��
	int m_backHandle;
};