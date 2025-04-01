#include <iostream>
using namespace std;

// 오늘의 주제 : 연산자 오버로딩(operatorOverloading)

// 연산자 vs 함수
// -연산자는 피 연산자의 개수/타입이 고정되어 있음

// 연산자 오버로딩?
// 일단 [연산자 함수]를 정의해야함
// 함수도 멤버함수 vs 전역함수가 존재하는 것 처럼, 연산자 함수도 두가지 방식으로 만들 수 있음

// - 멤버 연산자 함수 version
// -- a op b 형태에서 왼쪽을 기준으로 실행됨 (a가 클래스여야 가능. a를 '기준 피연산자' 라고 함)
// -- 한계) a가 클래스가 아니면 사용을 못함

//  - 전역 연산자 함수 version
// -- a op b 형태라면 a, b 모두를 연산자 함수의 피연산자로 만들어준다

// 그럼 무엇이 더 좋은가?
// 그런거 없음. 심지어 둘 중 하나만 지원하는 경우도 있기 때문.
// - 대표적으로 대입 연산자 ( a = b )는 전역연산자 version으로는 못만든다.


class Position
{
public:

	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;

		return pos;
	}

	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;

		return pos;
	}

	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}

	void operator=(int arg)
	{
		_x = arg;
		_y = arg;
	}

public:
	int _x;
	int _y;
};

Position operator+(int a, const Position& b) // 전역 연산자 함수 a가 클래스가 아니어도 사용가능함
{
	Position ret;
	ret._x = b._x + a;
	ret._y = b._y + a;

	return ret;
}

//void operator=(const Position& a, int arg) // error 발생 - operator는 멤버변수여야합니다.
//{
//	a._x = arg;
//	a._y = arg;
//}

int main()
{
	int a = 1;
	int b = 2;
	int c = a + b;

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos + pos2; // pos3 = pos.operator+(pos2); 동일한 방법
	// 1. error 발생 -> 자동으로 동일한 것을 찾지 않고 지정을 해줘야만함
	// 2. Position 안에 operator+ 를 만든 이후에는 문제가 생기지 않음

	Position pos4 = pos3 + 1; // operator+(int arg) 덕분에 정상동작하게됨
	pos4 = pos3.operator+(1);
	Position pos5 = 1 + pos4; // error 발생 기준 피연산자가 클래스가 아님. -> 전역연산자 함수를 통해서 해결함

	bool isSame = (pos3 == pos4);
	
	Position pos6;
	pos6 = 6;

	return 0;
}