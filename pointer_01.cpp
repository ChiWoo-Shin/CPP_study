#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 연산

// 1) 주소 연산자 (&)
// 2) 산술 연산자 (+, -)
// 3) 간접 연산자 (*)
// 4) 간접 멤버 연산자 (->)

struct Player {
	int hp;
	int damage;
};

int main()
{
	int number = 1;

	// 1) 주소 연산자(&)
	// - 해당 변수의 주소를 알려주세요
	// - 더 정확히 말하면 해당 변수 타입(TYPE)에 따라서 TYPE* 변환
	int* pointer = &number;

	// 2) 산술 연산자 (+, -)

	number += 1; // 1 증가

	// int*
	// - * : 포인터 타입 (4바이트 - 32비트 or 8바이트 - 64비트)
	// - int : 주소를 따라가면 int (4바이트 정수형 바구니) 가 있다고 가정

	// [!] 포인터에서 +나 -등 산술 연산으로 1을 더하거나 빼면,
	// 한번에 TYPE의 크기만큼을 이동한다는 의미

	pointer += 1; // 4 증가 --> 주소가 int(4바이트) 만큼 증가하게됨.

	// 3) 간접 연산자 (*)
	*pointer = 3;
	number = 3;

	// 4) 간접 멤버 연산자 (->)

	Player player;
	player.hp = 100;
	player.damage = 10;

	// 구조체도 pointer가 가능
	Player* playerPtr = &player;
	// 4-1과 4-2는 동일한 방법이다.
	// 4-2의 방법을 추천함 (앞으로 class에서도 ->를 쓰게 되는데 그건 그때가서)
	//4-1
	(*playerPtr).hp = 200;
	(*playerPtr).damage = 200;
	//4-2
	playerPtr->hp = 300;
	playerPtr->damage = 300;

	return 0;
}