#include <iostream>
using namespace std;

// ������ ���� : �ʱ�ȭ ����Ʈ
// ��� ���� �ʱ�ȭ ? �پ��� ������ ����
// �ʱ�ȭ �� �ؾ��ұ�?
// - ���� ���濡 �߿�
// - ������ �� �ּҰ��� ����Ǿ� ���� ���

// �ʱ�ȭ ���
// - ������ ������
// - �ʱ�ȭ ����Ʈ
// - C++11 ����

// �ʱ�ȭ ����Ʈ
// - �ϴ� ��� ���迡�� ���ϴ� �θ� ������ ȣ���� �� �ʿ��ϴ�
// - ������ ������ �ʱ�ȭ vs �ʱ�ȭ ����Ʈ
// -- �Ϲ� ������ �� ���� ����
// -- ��� Ÿ���� Ŭ������ ��� ���̰� ����
// -- �����԰� ���ÿ� �ʱ�ȭ�� �ʿ��� ��� (���� Ÿ��, const Ÿ��)

class Inventory
{
public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int size) { cout << "Inventory(int size)" << endl; _size = size; }

	~Inventory() { cout << "~Inventory()" << endl; }

public:
	int _size = 10;
};

class Player
{
public:
	Player() { }
	Player(int id) { }
};

// Is-A (Knight Is-A Player?) OK --> ��� ����
// Is-A (Knight Is-A Inventory?) No

// Has-A (Knight Has-A Inventory?) OK --> ���� ����

class Knight : public Player
{
public:
	Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100) // �ʱ�ȭ �Ҷ��� �̺κ�(�ʱ�ȭ ����Ʈ)�� �̿��ؼ� �ϴ°� ����
		/*
		��ó�� ����

		Inventory() �� �����ڰ� ȣ���
		Knight�� �Ҹ�ɶ� ~Inventory() �� ���� �Ҹ��

		*/
	{
		_hp = 100;
		//_inventory = Inventory(20); // ���⼭ ����� ������ ������� _inventory�� ��������Ե�, �̷��� �Ǹ� �ռ� ������� _inventory�� �Ҹ��Ű�� �ڽſ��� �´� �����ڸ� �ٽ� ������
		
		// ���⼭ �����ϸ� �ҿ��� ����
		// �̹� ��ó���� ���� �����̱� ������ ���� �������� ����
		// _hpRef = _hp; 
		// _hpConst = 100;
	}
	
public:
	int _hp;
	Inventory _inventory;

	int& _hpRef;
	// int& _hpRef = _hp; --> C++11 ���� (mordern C++)
	const int _hpConst;
	// const int _hpConst = 100; --> C++11 ���� (mordern C++)
};

int main()
{
	Knight k;

	cout << k._hp << endl;

	return 0;
}