#include <iostream>
using namespace std;

// ������ ���� : ��Ӽ�

// ��ü���� (OOP Object Oriented Programming)
// - ��Ӽ�
// - ���м�
// - ������

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// ���(Interitance) ? �θ� -> �ڽĿ��� ������ �����ش�

// ������(N�� ��������)/�Ҹ���(1���� ���� ����)
// - Knight�� �����ϸ� -> Player�� ������? Knight�� ������?
// -> �� �� ȣ��ȴ�.
// �����ڿ� �Ҹ��ڴ� ����ϴ� ������ �ƴ϶� �ڽŵ� ������ ����
// �������� ������ {�θ� ������ -> �ڽ� ������ -> �ڽ� �Ҹ��� -> �θ� �Ҹ���}
// ������ �����δ� ������� ����� �ڽ� ������ ȣ���� Ÿ�� ��ó�� �������� �θ� �����ڸ� ȣ���ϰԵ�

class Player
{
public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player() �⺻ ������ ȣ��" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player() ������ ȣ��" << endl;
	}

	~Player()
	{
		cout << "~Player() �Ҹ��� ȣ��" << endl;
	}

	void Move() { cout << " Player Move ȣ�� " << endl; }
	void Attack() { cout << " Player Attack ȣ�� " << endl; }
	void Die() { cout << " Player Die ȣ�� " << endl; }

public:
	int _hp;
	int _attack;
	int _defence;

	// StatInfo _statInfo; �� ����
};

// class�� ������ ���赵
class Knight : public Player // ����� �޴� ��� ": public"
{
public:
	Knight()
	/*
	��(����)ó�� ����
	- ���⼭ Player() �����ڸ� ȣ��
	*/
	{
		_stamina = 100;
		cout << "Knight() �⺻ ������ ȣ��" << endl;
	}

	Knight(int stamina) : Player(100)
	/*
	��(����)ó�� ����
	- ���⼭ Player() �⺻ �����ڸ� ȣ��

	������ ������� Ư�� �����ڸ� ���� ���� �����ϰ� �Ǹ�
	�ش� ������ - Player(int hp) �� ȣ��ǰ� ��

	*/
	{
		_stamina = stamina;
		cout << "Knight(int hp) Ÿ�Ժ�ȯ ������ ȣ��" << endl;
	}
	~Knight()
	{
		cout << "~Knight() �Ҹ��� ȣ��" << endl;
	}
	/*
	��ó�� ����
	- ���⼭ ~Player() �Ҹ��ڸ� ȣ��
	*/

	// ������ : �θ���� �����ֽ� ������ �ź��ϰ� ���ο� �̸����� ����� ����
	void Move() { cout << " Knight Move ȣ�� " << endl; }

public:
	int _stamina; // �ش� Ŭ������ �ʿ��Ѱ͸� ���� ���� ������
};

class Mage : public Player
{
public:

public:
	int _mana;
};

int main()
{
	Knight k;

	k._hp = 100;
	k._attack = 10;
	k._defence = 5;
	k._stamina = 50;

	k.Move(); // �������� �Լ��� ������ ����ϰԵ�
	k.Player::Move(); // �������� �Լ��� �ƴ� �θ𿡰� ��ӹ��� �Լ��� ���

	k.Attack();
	k.Die();

	Knight k2(100);

	return 0;
}