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

// 복사 대입 연산자
// - 대입 연산자가 나온 김에 [복사 대입 연산자]에 대해 알아보자
// 용어가 좀 헷살린다 [복사 생성자] [대임 연산자] [복사 대입 연산자] @_@
// - 복사 대입 연산자 = 대입 연산자 중, 자기 자신의 참조 타입을 인자로 받는 것

// 기타
// - 모든 연산자를 다 오버로딩 할수 있는 것은 아님.(:: . .* 이런건 안됨)
// - 모든 연산자가 다 2개 항이 있는 것은 아님. ++ -- 가 대표적 (단항 연산자)
// - 증감 연산자 ++ --
// -- 전위형 (++a) operator++()
// -- 후위형 (a++) operator++(int a)

class Position
{
public:

	//Position(const Position& arg) // 복사 생성자
	//{

	//}

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
	
	Position& operator=(int arg) // void 을 return 해도 되지만 일반적으로 자기 자신의 type을 return 함
	{
		_x = arg;
		_y = arg;

		// Position* this = 내 자신의 주소;
		return *this;
	}
	// [복사 생성자] [복사 대입 연산자] 등 특별 대우를 받는 이유는,
	// 말 그대로 객체가 '복사'되길 원하는 특징 때문
	// TODO) 동적할당 시간에 더 자세히 알아볼 것

	Position& operator=(const Position& arg) // const 를 붙여서 값을 읽어오는 역할만 하게 지정해줌
	{
		_x = arg._x;
		_y = arg._y;

		// Position* this = 내 자신의 주소;
		return *this;
	}

	Position& operator++()
	{
		_x++;
		_y++;

		return *this;
	}

	Position operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;
		return ret;
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
	int d = c++;

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
	pos3 = (pos6 = 6); // return type을 void에서 자기 자신(Position)으로 수정했기때문에 정상 동작

	pos6 = pos3++;
	Position pos7;
	pos7 = ++(pos6++);
	++(++pos7);

	return 0;
}