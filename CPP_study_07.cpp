#include <iostream>
using namespace std;

bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

bool test;

int hp = 100;
bool isInvincible = true;

int a = 0;
int b = 2;
int main()
{
#pragma region �� ����

	// ���� �ʿ��Ѱ�?
	// ex) ü���� 0�� �Ǹ� ���
	// ex) ü���� 30%�����̸� �ñر⸦ �ߵ� (100*hp/maxHp)
	// ex) ����ġ�� -100�̻��̸� ������

	// a == b : a�� b�� ���� ������?
	// ������ 1, �ٸ��� 0
	isSame = (a == b);
	printf("isSame : %d\n", isSame);

	// a!=b : a�� b�� ���� �ٸ���?
	// �ٸ��� 1, ������ 0;
	isDifferent = (a != b);
	printf("isDifferent : %d\n", isDifferent);


	// a>b : a�� b���� ū��?
	// a>=b : a�� b���� ũ�ų� ������?
	// 1 �ƴϸ� 0
	isGreater = (a > b);
	printf("isGreater : %d\n", isGreater);

	// a < b : a�� b���� ������?
	// a <= b : a�� b���� �۰ų� ������?
	// 1 �ƴϸ� 0
	isSmaller = (a > b);
	printf("isSmaller : %d\n", isSmaller);

#pragma endregion

#pragma region ������
	// � �ʿ��Ѱ�? ���ǿ� ���� ���� ��� �ʿ��Ҷ�
	// ex) �α����� �� ���̵� ���� AND ��й�ȣ�� ���ƾ��Ѵ�
	// ex) ��� �������̰ų� OR ��� �����̸� ��� �ػ� ����

	// ! not
	// 0�̸� 1, �� �� 0
	test = !isSame; // ��ǻ� isDifferent�� �ǹ�
	printf("test1 : %d\n", test);
	// && and
	// a && b -> �Ѵ� 1�̸� 1, �� �� 0
	test = (hp <= 0 && isInvincible == false); // ����
	printf("test2 : %d\n", test);
	// || or
	// a || b -> �� �� �ϳ��� 1�̸� 1 (�Ѵ� 0�̸� 0)
	test = (hp > 0 || isInvincible == true); // == 	!(hp > 0 || isInvincible == true);
	printf("test3 : %d\n", test);

#pragma endregion

}