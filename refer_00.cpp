#include <iostream>
using namespace std;

// 참조 전달


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

	// 로우레벨(어셈블리) 실제 작동 방식은 int*와 똑같음
	// 실행해보면 포인터와 100% 동일
	int& reference = number;

	// C++ 관점에서는 number라는 바구니에 또다른 이름을 부여한 것.
	// number라는 바구니에 reference 라는 다른 이름을 지어줌
	// 앞으로 reference 바구니에다가 뭘 꺼내거나 넣으면,
	// 실제 number 바구니 그 값(진짜 값) 을 꺼내거나 넣게됨

	reference = 3;

	// 그런데 귀찮게 또 다른 이름을 짓는 이유는?
	// 참조 전달 때문!
	// 포인터의 '->' 사용을 없애고 '.' 을 찍어서 그대로 쓸 수 있게 해줌 포인터와 일반 선언의 중간단계 정도로 이해

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