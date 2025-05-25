#include <iostream>
using namespace std;

// ĳ���� (Ÿ�� ��ȯ)

class Player
{
public:
	 virtual ~Player() { }
};

class Knight : public Player
{
public:
};

class Archer : public Player
{
public:
};

class Dog
{

};

// 1) static_cast
// 2) dynamic_cast
// 3) const_cast
// 4) reinterpret_cast

void PrintName(char* str)
{
	cout << str << endl;
}

int main()
{
	// static_cast : Ÿ�� ��Ģ�� ���纼 �� ������� ĳ���ø� ���
	// 1) int <-> float
	// 2) Player* -> Knight* (�ٿ� ĳ����) << ��, �������� ���� ����

	int hp = 100;
	int maxHp = 200;
//	float ratio = hp/maxHp; // -> 0
//	float ratio = (float)hp / maxHp; // -> 0.5
	float ratio = static_cast<float>(hp) / maxHp;

	// �θ� -> �ڽ�  �ڽ� -> �θ�
	Player* p = new Archer();
	Knight* k1 = static_cast<Knight*>(p);
	

	// dynamic_cast : ��� ���迡���� ������ ����ȯ ����
	// RTTI (RunTime Type Information)
	// �������� Ȱ���ϴ� ���
	// - virtual �Լ��� �ϳ��� �����, ��ü�� �޸𸮿� ���� �Լ� ���̺� (vftable) �ּҰ� ���Ե�
	// - ���� �߸��� Ÿ������ ĳ������ ������, nullptr ��ȯ **************
	// �̸� �̿��ؼ� �´� Ÿ������ ĳ������ �ߴ��� Ȯ���Ҷ� ����
	// Ȯ���ϴ� ������ �ֱ� ������ static_cast���� ������ ������.
	Knight* k2 = dynamic_cast<Knight*>(p); // virtual �Լ� ���� ����ϸ� "���� - 'dynamic_cast': 'Player'��(��) ���� ������ �ƴմϴ�."�� �߻�

	// const_cast : const�� ���̰ų� ���ų� �Ҷ� Ȱ��
	PrintName("Rookiss");
	// ���������� const char[8] �� char*�� ��ȯ�� �� ���ٴ� ������ �߻���
	// �̸� �ذ��ϱ� ���ؼ� const_cast<char*> �� �־�� �ϴµ�
	// PrintName(const_cast<char*>("Rookiss"));
	// ���� �ش� ������ �߻����� ����

	// reinterpret_cast
	// ���� �����ϰ� ������ ������ ĳ����
	// 're-interpret' : �ٽ� �����ϴ�/ �����ϴ�
	// - �����Ͷ� ���� ������� �ٸ� Ÿ�� ��ȯ ��
	// __int64 address = k2; // �ƹ� �������� ���⶧���� ������ �߻�
	__int64 address = reinterpret_cast<__int64>(k2);
	// ����(Ȱ��) E0144	"Knight *" ������ ���� ����Ͽ� "long long" ������ ����Ƽ�� �ʱ�ȭ�� �� �����ϴ�.

	Dog* dog1 = reinterpret_cast<Dog*>(k2); // �����ͳ����� ��ȯ ����
	
	void* p = malloc(1000);
	// ����Ҷ��� �̷��� void�� �޴� ���� Dog ���� �����ͷ� ��ȯ�Ҷ� �����
	Dog* dog2 = reinterpret_cast<Dog*>(p);

	return 0;
}