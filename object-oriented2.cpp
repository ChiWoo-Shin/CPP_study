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
	// �� �߿��� ���ڸ� 1���� �޴� [��Ÿ ������]��
	// [Ÿ�Ժ�ȯ ������]��� �θ��⵵ ��

	// Ÿ�Ժ�ȯ �뵵�� ������� �ʰ� ��������θ� ����ϱ� ���ؼ� explicit�� �տ� ���̸��
	explicit Knight(int hp)
	{
		cout << "Knight(int) ������ ȣ��" << endl;
		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	Knight(int hp, int attack, int posX, int posY)
	{
		_hp = hp;
		_attack = attack;
		_posY = posY;
		_posX = posX;
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

void HelloKnight(Knight k)
{
	cout << "Hello Knight" << endl;
}

// Instantiate ��ü�� �����!
int main()
{
	// [1] �⺻ ������
	Knight k1;
	k1._hp = 100;

	// [3] �Ϲ� ������
	// Knight k1(100);
	Knight k5(100, 0, 0, 0);

	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	// [2] ���� ������
	Knight k2(k1); // ���� �����ڸ� �ּ�ó���ص� ���� �����ϴ� ���� Ȯ���� �� ���� --> �⺻������ �����ɼ� �ִ� ��� ���� �� �� ����
	
	Knight k3 = k1; // ���� �����ڸ� ����ؼ� knight�� ����

	Knight k4; // �⺻ �����ڸ� ����� ��
	k4 = k1; // ���縦 ������

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	// �Ͻ��� ����ȯ -> �����Ϸ��� �˾Ƽ� �ٲ�ġ��
	int num = 1;
	float f = (float)num; // ����� < �츮�� �ڵ�� num�� float �ٱ��Ͽ� ������� �ֹ�
	double d = num; // �Ͻ��� << ���� ���ߴµ� �����Ϸ��� �˾Ƽ� ó����

	Knight k6;
	k6 = (Knight)1; // [Ÿ�� ��ȯ ������]�� ���ؼ� ������ �����̵� --> Explicit�� �߰��� ���� ������ �߻��� --> ��������� ��ȯ�� �ϸ� ������ ������

	HelloKnight((Knight)5); // --> Explicit�� �߰��� ���� ������ �߻��� --> ��������� ��ȯ�� �ϸ� ������ ������

	return 0;
}