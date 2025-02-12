#include <iostream>
using namespace std;

// ���� ����


struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void PrintInfoByRef(StatInfo& info);
void PrintInfoByPtr(StatInfo* info);
void CreateMonster(StatInfo* info);

int main()
{
	int number = 1;

	int* pointer = &number;
	*pointer = 2;

	// �ο췹��(�����) ���� �۵� ����� int*�� �Ȱ���
	// �����غ��� �����Ϳ� 100% ����
	int& reference = number;

	// C++ ���������� number��� �ٱ��Ͽ� �Ǵٸ� �̸��� �ο��� ��.
	// number��� �ٱ��Ͽ� reference ��� �ٸ� �̸��� ������
	// ������ reference �ٱ��Ͽ��ٰ� �� �����ų� ������,
	// ���� number �ٱ��� �� ��(��¥ ��) �� �����ų� �ְԵ�

	reference = 3;

	// �׷��� ������ �� �ٸ� �̸��� ���� ������?
	// ���� ���� ����!
	// �������� '->' ����� ���ְ� '.' �� �� �״�� �� �� �ְ� ���� �����Ϳ� �Ϲ� ������ �߰��ܰ� ������ ����

	StatInfo info;
	CreateMonster(&info);

	PrintInfoByRef(info);
	PrintInfoByPtr(&info);

	return 0;
}

void PrintInfoByRef(StatInfo& info)
{
	cout << "-------PrintInfoByRef-------" << endl;
	cout << "HP : "<< info.hp << endl;
	cout << "ATT : "<< info.attack << endl;
	cout << "DEF : "<< info.defence << endl;
	cout << "-------------------" << endl;
}

void PrintInfoByPtr(StatInfo* info)
{
	cout << "-------PrintInfoByPtr-------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "-------------------" << endl;
}

void CreateMonster(StatInfo* info)
{
	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
}