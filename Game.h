#pragma once


// ���� ����
class Player;
class Field;

// is - a
// has - a


class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:

	// Player _player; // �̷��� �ϸ� Player�� �־�߸� ������ �����ϴ� �� - ��� ���� ���·� ���ϰ� ������,
	// ��ó�� ��� ������ Knight ���� �� ū ũ�⸦ ������ �ֱ� ������ �����Ͱ� ©������ Ȯ���� ����

	// [ 4~8 ] --->>> [       ]
	Player* _player;
	// �̷��� �����ϸ� player�� include ���� �ʾƵ� ������ ������ ����
	// ���漱���� ���� ���Ŀ� player�� �����ϰ� �� ���̶�� �͸� �������ָ� ��.
	Field* _field;
};

