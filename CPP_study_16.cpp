#include <iostream>
using namespace std;

// 함수 마무리

// 오버로딩 (중복 정의 : 함수 이름의 재상요)
// - 매개변수 갯구가 다르거나
// - 매개변수 타입이 다르거나 (순서가 다른걸 포함)

int Add(int a, int b)
{
	int result = a + b;
	return result;
}

float AddFloat(float a, float b)
{
	float result = a + b;
	return result;
}

// error가 발생하지 않음
// 함수 이름은 같지만 input이 다르므로 코드가 스스로 선택이 가능함
float Add(float a, float b)
{
	float result = a + b;
	return result;
}

// error가 발생함
// 함수 이름과 input이 동일하여 코드가 오버로딩으로 판단함--> 반환 타입은 중요하지 않음
float Add(int a, int b)
{
	int result = a + b;
	return result;
}

// 기본 인자값
// guildId의 경우 초기 값을 0으로 설정해놓기 때문에 함수를 호출할때 없어도 문제가 되지 않음
// 초기 값을 0으로 설정하기 위해서는 꼭 변수의 마지막에 설정해야함.
// 중간에 있으면 함수를 호출할때 변수가 꼬여서 에러를 발생시킴
// 초기 값이 있더라도 input에서 값을 설정해주면 input 값이 들어가게됨
void SetPlayerInfo(int hp, int mp, int attack, int guildId = 0)
{

}



int main()
{
	int result = Add(1.5f, 2.1f);
	cout << result << endl;

	SetPlayerInfo(100, 40, 10); // hp = 100, mp = 40, attack = 10, guildId = 0
	SetPlayerInfo(100, 40, 10, 1); // hp = 100, mp = 40, attack = 10, guildId = 1


	return 0;
}