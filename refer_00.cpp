#include <iostream>
using namespace std;

// ���� ����

#define OUT

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void PrintInfoByRef(StatInfo& info);
void ChangeInfo(OUT StatInfo& info);
void PrintInfoByPtr(StatInfo* info);
void CreateMonster(StatInfo* info);

int main()
{
	StatInfo info;

	// ������ vs ���� ������ ���
	// ���� : �Ȱ��� !
	// ���Ǽ� : ���� ��!

	// 1) ���Ǽ� ����
	// ���Ǽ��� ���ٴ°� �� �������� �ƴϴ�.
	// �����ʹ� �ּҸ� �ѱ�� Ȯ���ϰ� ������ �ѱ�ٴ� ��Ʈ�� �� �� ����
	// ������ �ڿ������� �𸣰� ����ĥ �� ����!
	// ex) ������� ��ģ�ٸ�?
	// const�� ����ؼ� �̷� ������� ��ġ�� �κ��� ���� ����

	// ����� �����͵� const�� ��� ����
	// *�� �������� �տ� ���̴��� �ڿ� ���̴��Ŀ� ���� �ǹ̰� �ٲ�Ե�

	// 2) �ʱ�ȭ ����
	// ���� Ÿ���� �ٱ����� 2��° �̸�(��Ī?)
	// -> �����ϴ� ����� ������ �ȵ�
	// �ݸ� �����ʹ� �׳� �~ �ּҶ�� �ǹ�
	// -> ����� �������� ���� ���� ���� --> �̷����� �����Ϳ��� �����ϴ� ������� �������� �Ұ�����
	// �����Ϳ��� '����'�� �ǹ̷�? nullptr
	// ���� Ÿ���� �̷� nullptr�� �������� ���� 


	StatInfo* pointer = nullptr; 
	pointer = &info;
	PrintInfoByPtr(&info); // �ּҸ� �ѱ�� ������ �����͸� �ѱ�� ���̶�� ������ �� ����

	StatInfo& reference = info;
	PrintInfoByRef(info); // ������ ������ �� �ִ��� �ƴ��� �����ϱ� �����

	ChangeInfo(OUT info); // �Ϲ��� ref�� ����ϸ鼭 ���� ������ �����Ѱ�� OUT�� ǥ������ (�������� ����)

	// Bonus) �����ͷ� ����ϴ��� ������ �Ѱ��ַ���?
	// PrintInfoByRef(pointer); // error �߻� ref�� ����ϴ� ���� pointer�� �־
	PrintInfoByRef(*pointer); // �տ� *�� �־ ������ ��ȯ���ָ��

	// Bonus) ������ ����ϴ��� �����ͷ� �Ѱ��ַ���?
	// PrintInfoByPtr(reference); // error �߻� �ּҸ� �־���ϴ� ���� refer�� �־
	PrintInfoByPtr(&reference); // �տ� &�� �־ �ּҸ� �Ѱ��ָ��

	return 0;
}

void PrintInfoByRef(const StatInfo& info)
{
	cout << "-------PrintInfoByRef-------" << endl;
	cout << "HP : "<< info.hp << endl;
	cout << "ATT : "<< info.attack << endl;
	cout << "DEF : "<< info.defence << endl;
	cout << "-------------------" << endl;

	// ������ �Դ�
	// info.hp = 10000; // Error�� �߻��ϰԵ� const�� ���Ͽ�
}


void ChangeInfo(OUT StatInfo& info) // OUT�� ������ �������� ����ϴ°�
{
	info.hp = 1000;
}

StatInfo globalInfo;
void PrintInfoByPtr(StatInfo* info)
{
	if (info == nullptr) // if(!info) --> nullptr�� Ȯ���� �� �ִ� ���
		return ;
	cout << "-------PrintInfoByPtr-------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "-------------------" << endl;
	
	// 1) ���Ǽ� ���� �κ���
	// const�� �� �ڿ� ���δٸ�?
	// StatInfo* const info
	// info = &globalInfo; // info ��� �ٱ����� ���빰(�ּ�)�� �ٲܼ� ���� --> �ּҰ��� �����̴�

	// �� ������ ���δٸ�?
	// const StatInfo* info || StatInfo const* info --> ���ڸ� �Ϲ������� ���� �����
	// info->hp = 10000; // info�� '����Ű�� �ִ�' �ٱ����� ���빰�� �ٲܼ� ���� --> '����' �ٱ����� ���빰�� �ٲܼ� ����

	// �� �� �����൵ ��
	// const StatInfo* const info
}

void CreateMonster(StatInfo* info)
{
	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
}