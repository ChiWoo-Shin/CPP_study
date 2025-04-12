#include <iostream>
using namespace std;

// ������ ���� : ��ü���� ������

// 1) struct vs class

// C++ ������ struct�� class�� ���� ���� �����̴�.
// struct�� �⺻ ���� �����ڰ� public�̰� class�� private�̴�.
// �� �̷��� ������? C++�� C���� �Ļ��Ǿ� �����߱� ������, ȣȯ���� ��Ű�� ����.
// -> struct�� �׳� ����ü (������ ����)�� ǥ���ϴ� �뵵
// -> class�� ��ü ���� ���α׷����� Ư¡�� ��Ÿ���� �뵵

struct TestStruct
{
public: // struct�ȿ� �ƹ��͵� ������ default�� public
	int _a;
	int _b;
};

class TestClass
{
private: // class �ȿ� �ƹ��͵� ������ default �� private
	int _a;
	int _b;
};


// 2) static ����, static �Լ� (static = ���� = ������)

class Marine
{
public:
	// Ư�� ���� ��ü�� ������
	int _hp;

	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	static void setAttack() // ��ü�� �������� �ִ� �ֵ��� ȣ���ϸ� error�� �߻�
	{
		s_attack = 100; // ������ static���� �Ǿ��ִ°� ȣ���ص� ������ �ȵ�
	}

	// Ư�� ���� ��ü�� ����
	// �����̶�� 'Ŭ����' ��ü�� ����
	static int s_attack; // ���赵�����θ� ����
};

// static ������ � �޸�?
// �ʱ�ȭ �ϸ� .data
// ���ϸ� .bss

int Marine::s_attack = 0;

class Player
{
public:
	int _id;

};

// ���� ���� ��ü
static int s_global = 1;

int GenerateId()
{
	// �����ֱ� : ���α׷� ����/ ���� (�޸𸮿� �׻� �ö� ����)
	// ���ù��� : 
	// 1 2 3 4 5 6 �� ������� ����ִ� �Լ��� ����
	// ���� ���� ��ü
	static int s_id = 1;
	
	return s_id++;
}

int main()
{
	TestStruct ts;
	ts._a = 1;

	TestClass tc;
	// tc._a = 1; // error �߻� -- class�� �����Ҷ� public���� ���������� ������ private���� �����ϱ� ������

	Marine m1;
	m1._hp = 40;
	m1.TakeDamage(10);
	// m1.s_attack = 6;
	Marine::s_attack = 6;

	Marine m2;
	m2._hp = 40;
	// m2.s_attack = 6;
	m2.TakeDamage(5);

	// ���� ���ݷ� ���׷��̵� �Ϸ�! (Academy���� ���׷��̵� ��)
	Marine::s_attack = 7;
	Marine::setAttack();

	// ������ �ƴ� .data ����
	static int id = 10;
	int a = id;

	cout << GenerateId() << endl; // 1
	cout << GenerateId() << endl; // 2
	cout << GenerateId() << endl; // 3
	cout << GenerateId() << endl; // 4
	cout << GenerateId() << endl; // 5

	return 0;
}