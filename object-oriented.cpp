#include <iostream>
using namespace std;

// ������ ���� : ��ü������ ����

// ����(procedural) ���� ���α׷���
// - procedure = �Լ�
// ������� �Լ��� ���� ������� �����δ�

// ������ + ����(����, ����)

// ��ü���� ���α׷��� = ��ü
// ��ü��? �÷��̾�, ����, GameRoom

// Knight�� �����غ���
// - �Ӽ� (������) : hp, attack, position(y, x)
// - ��� (����) : Move, attack, Die

// class�� ������ ���赵
class Knight // knight�� ���� ���赵
{
public:
	// ��� �Լ�
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		hp = 0;
		cout << "Die" << endl;
	}


public:
	// ��� ����
	int hp;
	int attack;
	int posY;
	int posX;
};

void Knight::Move(int y, int x)
{
	posY = y;
	posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << attack << endl;
}

// Instantiate ��ü�� �����!
int main()
{
	Knight k1;
	k1.hp = 100;
	k1.attack = 10;
	k1.posY = 0;
	k1.posX = 0;

	Knight k2;
	k2.hp = 80;
	k2.attack = 5;
	k2.posY = 1;
	k2.posY = 1;

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	return 0;
}