#include <iostream>
using namespace std;

// ������ ���� : �����ڿ� �Ҹ���

// ������(Consttructor) �� �Ҹ���(DeConstuctor)
// Ŭ������ '�Ҽ�'�� �Լ����� ��� �Լ���� ��
// �� �߿��� ������ Ư���� �Լ� 2���� �ִµ�, �ٷ� [����]�� [��]�� �˸��� �Լ���
// - ����(ź��) -> ������ (������ ���� ����)
// - ��(�Ҹ�) -> �Ҹ��� (���� 1����)

// �Ͻ���(implicit) ������
// �����ڸ� ��������� ������ ������,
// �ƹ� ���ڵ� ���� �ʴ� [�⺻ ������]�� �����Ϸ��� ���� �ڵ����� �������.
// -> �׷��� �츮�� �����(Explicit)����  �ƹ� ������ �ϳ� �����,
// �ڵ����� ��������� [�⺻ ������]�� �� �̻� ��������� ����.

// class�� ������ ���赵
class Knight // knight�� ���� ���赵
{
public:
	// [1] �⺻ ������ (���ڰ� ����) -- ���� �����ڸ� ��������� ������ ������ �����Ϸ��� �ڵ����� ������� --> �Ͻ��� ������
	Knight() // �����Ҷ� ������ ȣ���
	{
		cout << "Knight() �⺻ ������ ȣ��" << endl;
		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// [2] ���� ������ - �ڱ� �ڽ��� Ŭ���� ���� Ÿ���� ���ڷ� ����
	// (�Ϲ������� '�Ȱ���' �����͸� ���� ��ü�� �����Ǳ� �����
	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_attack = knight._attack;
		_posY = knight._posY;
		_posX = knight._posX;
	}

	// [3] ��Ÿ ������
	Knight(int hp)
	{
		cout << "Knight(int) ������ ȣ��" << endl;
		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// �Ҹ��� -- return 0; ���Ŀ� ȣ��ǰ�����
	~Knight()
	{
		cout << "~Knight() �Ҹ��� ȣ��" << endl;
	}

	
	// ��� �Լ�
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		//this: // Knight* this �ڱ� �ڽ��� ����Ű�� ������
		_hp = 0;
		this->_hp = 1;
		cout << "Die" << endl;
	}


public:
	// ��� ���� --> ���� ���� ǥ����� : m_hp, mHp, _hp
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

// Instantiate ��ü�� �����!
int main()
{
	// [1] �⺻ ������
	Knight k1;
	k1._hp = 100;

	// [3] �Ϲ� ������
	Knight k1(100);

	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	// [2] ���� ������
	Knight k2(k1);

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	return 0;
}