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
#pragma region 비교 연산

	// 언제 필요한가?
	// ex) 체력이 0이 되면 사망
	// ex) 체력이 30%이하이면 궁극기를 발동 (100*hp/maxHp)
	// ex) 경험치가 -100이상이면 레벨업

	// a == b : a와 b의 값은 같은가?
	// 같으면 1, 다르면 0
	isSame = (a == b);
	printf("isSame : %d\n", isSame);

	// a!=b : a와 b의 값이 다른가?
	// 다르면 1, 같으면 0;
	isDifferent = (a != b);
	printf("isDifferent : %d\n", isDifferent);


	// a>b : a가 b보다 큰가?
	// a>=b : a가 b보다 크거나 같은가?
	// 1 아니면 0
	isGreater = (a > b);
	printf("isGreater : %d\n", isGreater);

	// a < b : a가 b보다 작은가?
	// a <= b : a가 b보다 작거나 같은가?
	// 1 아니면 0
	isSmaller = (a > b);
	printf("isSmaller : %d\n", isSmaller);

#pragma endregion

#pragma region 논리연산
	// 어넺 필요한가? 조건에 대한 논리적 사고가 필요할때
	// ex) 로그인할 떄 아이디도 같고 AND 비밀번호도 같아야한다
	// ex) 길드 마스터이거나 OR 운영자 계정이면 길드 해산 가능

	// ! not
	// 0이면 1, 그 외 0
	test = !isSame; // 사실상 isDifferent의 의미
	printf("test1 : %d\n", test);
	// && and
	// a && b -> 둘다 1이면 1, 그 외 0
	test = (hp <= 0 && isInvincible == false); // 죽음
	printf("test2 : %d\n", test);
	// || or
	// a || b -> 둘 중 하나라도 1이면 1 (둘다 0이면 0)
	test = (hp > 0 || isInvincible == true); // == 	!(hp > 0 || isInvincible == true);
	printf("test3 : %d\n", test);

#pragma endregion

}