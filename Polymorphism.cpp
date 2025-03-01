#include <iostream>
using namespace std;
// ������ ���� : ������

// ��ü���� (OOP Object Oriented Programming)
// - ��Ӽ�
// - ���м� = ĸ��ȭ
// - ������

// ������ (Polymorphism = Poly + morph) = ���� �Ȱ�����, ����� �ٸ��� ����
// - �����ε�(Overloading) = �Լ� �ߺ� ���� = �Լ� �̸��� ����
// - �������̵�(Overriding) = ������ = �θ� Ŭ������ �Լ��� �ڽ� Ŭ�������� ������

// ���ε�(Binding) = ���´�
// - ���� ���ε�(Static Binding) : ������ ������ ����
// - ���� ���ε�(Dynamic Binding) : ���� ������ ����

// �Ϲ� �Լ��� �������ε��� ����ϰ� ��
// ���� ���ε��� ���Ѵٸ�? -> �����Լ�(virtual function)

// �׷��� ���� ��ü�� � Ÿ������ ��� �˰� �����Լ��� ȣ�����ִ°ɱ�?
// - ���� �Լ� ���̺�(vftable)
// .vftable [] 4����Ʈ(32) 8����Ʈ(64)
// [VMove] [VDie]
// �����Լ� ���̺��� �������� ��ó�� �������� ��������

// ���� ���� �Լ� : ������ ���� '�������̽�' �� �����ϴ� �뵵�� ����ϰ� ���� ���
// �߻� Ŭ���� : ���� ���� �Լ��� 1�� �̻� ���ԵǸ� �ٷ� �߻� Ŭ������ ����
// - ���������� ��ü�� ����� ���� ��
class Player
{
public:
	Player()
	{
		_hp = 100;
	}
	void Move() { cout << "Move Player !" << endl; }
	void Move(int a) { cout << "Move Player (int) !" << endl; } // �����ε�
	virtual void VMove() { cout << "VMove Player !" << endl;  }
	virtual void VDie() { cout << "VDie Player !" << endl; }

	// ���� ���� �Լ� -- ��ӹ��� �ֵ���(Knight, Mage) ��� VAttack()�� ���� ����ض� ��� �й�
	virtual void VAttack() = 0; 

public:
	int _hp;
};

class Knight : public Player
{
public: 
	Knight()
	{
		_stamina = 100;
	}
	void Move() { cout << "Move Knight !" << endl; } // �������̵�

	// �����Լ��� �����Ǹ� �ϴ��� ���� �Լ���.
	virtual void VMove() { cout << "VMove Knight !" << endl; } 
	void VDie() { cout << "VDie Knight !" << endl; }// virtual�� ��� �����Լ��� �ν�
	void VAttack() { cout << "VDie VAttack !" << endl; }
public:
	int _stamina;
};

class Mage : public Player
{
public:
	void VAttack() { cout << "VDie VAttack !" << endl; }
public:
	int _mana;
};

void MovePlayer(Player* player)
{
	// ���� ���ε�
	player->Move();
	
	// ���� ���ε�
	player->VMove(); // �̰� player�� Move�Լ� ȣ�� --> �ƹ��� �ڽ�Ŭ������ Ÿ�� �ö�͵� �θ�Ŭ������ Move�� ȣ����
	player->VDie();
}

//void MoveKnight(Knight* knight)
//{
//	knight->Move();
//}

int main()
{
	// Player p; // ���� ���� �Լ��� �߰��� �Ŀ��� �߻�Ŭ������ �Ʊ⶧���� �ܵ����� ����� �� ���� ��.
	// p.Move(); // ù��° Move �� ����
	// p.Move(100); // �ι�° Move�� ����
	// MovePlayer(&p); // player�� �÷��̾�? Yes
	// MoveKnight(&p); // error�� �߻� --> player�� ���? No --> �θ�Ŭ�������� �ڽ�Ŭ������ Ž������ ����

	Knight k;
	k.Move();
	//MoveKnight(&k); // ���� ����? Yes
	MovePlayer(&k); // ���� �÷��̾��? Yes error �߻� X --> �ڽ�Ŭ������ �θ�Ŭ������ �´ٶ�� �����
	// �� ������ �̿��ϸ� �ᱹ ��� �ڽ�Ŭ������ �������ϴ� ���̶�� �θ�Ŭ������ �̿��ؼ� �� �� �ִٴ� �ǹ�.
	// ������ �����Լ��� ����Ѵٸ� �ڽ�Ŭ������ ������ �ִ� VMove�� �ҷ��� ����ϰԵ�


	return 0;
}