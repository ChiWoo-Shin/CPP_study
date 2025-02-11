#include <iostream>
using namespace std;

// ������ ���� : ������ ����

// 1) �ּ� ������ (&)
// 2) ��� ������ (+, -)
// 3) ���� ������ (*)
// 4) ���� ��� ������ (->)

struct Player {
	int hp;
	int damage;
};

int main()
{
	int number = 1;

	// 1) �ּ� ������(&)
	// - �ش� ������ �ּҸ� �˷��ּ���
	// - �� ��Ȯ�� ���ϸ� �ش� ���� Ÿ��(TYPE)�� ���� TYPE* ��ȯ
	int* pointer = &number;

	// 2) ��� ������ (+, -)

	number += 1; // 1 ����

	// int*
	// - * : ������ Ÿ�� (4����Ʈ - 32��Ʈ or 8����Ʈ - 64��Ʈ)
	// - int : �ּҸ� ���󰡸� int (4����Ʈ ������ �ٱ���) �� �ִٰ� ����

	// [!] �����Ϳ��� +�� -�� ��� �������� 1�� ���ϰų� ����,
	// �ѹ��� TYPE�� ũ�⸸ŭ�� �̵��Ѵٴ� �ǹ�

	pointer += 1; // 4 ���� --> �ּҰ� int(4����Ʈ) ��ŭ �����ϰԵ�.

	// 3) ���� ������ (*)
	*pointer = 3;
	number = 3;

	// 4) ���� ��� ������ (->)

	Player player;
	player.hp = 100;
	player.damage = 10;

	// ����ü�� pointer�� ����
	Player* playerPtr = &player;
	// 4-1�� 4-2�� ������ ����̴�.
	// 4-2�� ����� ��õ�� (������ class������ ->�� ���� �Ǵµ� �װ� �׶�����)
	//4-1
	(*playerPtr).hp = 200;
	(*playerPtr).damage = 200;
	//4-2
	playerPtr->hp = 300;
	playerPtr->damage = 300;

	return 0;
}