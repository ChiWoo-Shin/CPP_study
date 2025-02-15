#include <iostream>
using namespace std;

// 오늘의 주제 : 배열

struct StatInfo
{
	int hp = 0xAAAAAAAA;
	int attack = 0xBBBBBBBB;
	int defence = 0xCCCCCCCC;
};

int main()
{
	// 몬스터가 적을때는 상관없지만 극단적으로 많아지기 시작하면 하나씩 선언하는건 어불성설
	
	// TYPE 이름[개수];

	// 배열의 크기는 상수여야 함 (VC 컴파일러 기준)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	// 여태껏 변수들의 [이름]은 바구니의 이름이었음
	int a = 10;
	int b = a;

	// 그런데 배열은 [이름] 조금 다르게 동작한다
	// StatInfo players[10];
	// players = monsters; // players에 error 가 발생 -> 식이 수정할 수 있는 Ivalue여야 합니다.

	auto WhoAmI = monsters; // WhoAmI에 마우스를 대면 *WhoAmI 인것을 확인할 수 있음 --> 포인터와 같이 사용할수 있다

	// 주소[(100, 10, 1)] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] .....
	// monster_0[주소]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// 주소[(100, 10, 1)] StatInfo[ (200, 20, 2)] StatInfo[ ] StatInfo[ ] StatInfo[ ] .....
	// monster_0[주소]
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// 포인터와 참조는 자유자재로 변환 가능하다
	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// [주의] 이거는 위에서 사용한 포인터, 참조와는 완전 다른 의미 - 이전 강의에서 배움
	StatInfo temp = *(monsters + 2);
	temp.hp = 300;
	temp.attack = 30;
	temp.defence = 3;

	for (int i = 0; i < 10; i++) 
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = 1 * (i + 1);
	}

	// 근데 *(monsters + i) 너무 불편하고 가독성이 떨어짐
	// --> index!
	// 배열은 0번부터 시작. N번째 인덱스에 해당하는 데이터에 접근하려면 배열이름[N]
	// *(monsters + i) = monsters[i]

	monsters[0].hp = 100;
	monsters[0].attack = 10;
	monsters[0].defence = 1;

	for (int i = 0; i < 10; i++)
	{
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defence = 1 * (i + 1);
	}


	// 배열 초기화 문법 몇가지
	int numbers[5]; // 이때는 값이 특별히 정해지지 않은 값으로 되어있음

	// 초기화 방법
	int numbers1[5] = {}; // 모든 값이 0으로 초기화됨
	int numbers2[10] = { 1, 2, 3, 4, 5 }; // 설정한 값은 설정된 값으로 나머지는 0으로
	int numbers3[] = { 1, 2, 3, 4, 5, 6 }; // 데이터 개수 만큼의 크기에 해당하는 배열로 만들어줌

	char helloStr[] = { 'H', 'e', 'l', 'l', 'o', '\0' }; // numbers3번의 방법을 사용한 것
	cout << helloStr << endl;
	
	// 배열 요약:
	// 1) 선언한다
	int arr[10] = {};

	// 2) 인덱스로 접근해서 사용
	arr[1] = 1;
	cout << arr[1] << endl;


	return 0;
}
