#include <iostream>
using namespace std;

// 오늘의 주제 : 타입 변환

// malloc -> void*을 반환하고, 이를 우리가 (타입 변환)을 통해 사용했었음

class Knight
{
public:
	int _hp = 10;
};

class Dog
{
public:
	Dog()
	{

	}
	// 타입 변환 생성자
	Dog(const Knight& Knight)
	{
		_age = Knight._hp;
	}

	// 타입 변환 연산자
	operator Knight()
	{
		Knight knight;
		knight._hp = _age + _cuteness;
		return knight;
	}
public:
	int _age = 1;
	int _cuteness = 2;
};

class Bulldog : public Dog
{
public:
	bool _french; // 프렌치 불독
};

int main()
{
	cout << "_MSC_VER: " << _MSC_VER << endl;
	cout << "_MSC_FULL_VER: " << _MSC_FULL_VER << endl;
	// ---------------- 타입 변환 유형 (비트열 재구성 여부) -------------------

	// [1] 값 타입 변환
	// 특징) 의미를 유지하기 위해서, 원본 객체와 다른 비트열 재구성
	{
		int a = 123456789; // 2의 보수를 이용하여 값을 저장
		float b = (float)a; // 부동소수점(지수 + 유효숫자) a와 최대한 같은 값 혹은 유사한 값을 부여함
		cout << b << endl;
	}

	// [2] 참조 타입 변환
	// 특징) 비트열을 재구성하지 않고, '관점'만 바꾸는 것
	// 거의 쓸일은 없지만, 포인터 타입 변환도 '참조 타입 변환' 동일한 룰을 따르니까 일석이조로 공부하자!
	{
		int a = 123456789; // 2의 보수를 이용하여 값을 저장
		float b = (float&)a; // 데이터를 그대로 유지한 상태에서 관점만 바꾼 것 그래서 값이 이상하게 출력
		cout << b << endl;
	}

	// --------------- 안전도 분류 -----------------

	// [1] 안전한 변환
	// 특징) 의미가 항상 100% 완전히 일치하는 경우
	// 같은 타입이면서 크기만 더 큰 바구니로 이동
	// 작은 바구니 -> 큰 바구니로 이동 OK (업캐스팅)
	// ex) char -> short -> int -> __int64
	{
		int a = 123456789;
		__int64 b = a;
		cout << b << endl;
	}

	// [2] 불안전한 변환
	// 특징) 의미가 항상 100% 일치한다고 보장하지 못하는 경우
	// 타입이 다르거나
	// 같은 타입이지만 큰 바구니 -> 작은 바구니 이동 (다운캐스팅)
	{
		int a = 123456789;
		float b = a;
		short c = a;
		cout << b << endl;
		cout << c << endl;
	}

	// --------------- 프로그래머 의도에 따라 분류 -----------------
	// [1] 암시적 변환
	// 특징) 이미 알려진 타입 변환 규칙에 따라서 컴파일러 '자동'으로 타입 변환
	{
		int a = 123456789;
		float b = a; // 암시적 변환 - error는 발생하지 않지만 warning이 발생
		cout << b << endl;
	}

	// [2] 명시적 변환
	{
		int a = 123456789;
		// int* b = a; // 이런경우에는 암시적으로 동작하지 않음 - 컴파일러 판단 기준으로 위험하다고 판단되는 부분
		int* b = (int*)a; // 명시적 변환
		cout << b << endl;
	}

	// --------------- 아무런 연관 관계가 없는 클래스 사이의 변환 -----------------

	// [1] 연관 없는 클래스 사이의 '값 타입' 변환
	// 특징) 일반적으로 안됨(예외 : 타입 변환 생성자, 타입 변환 연산자가 있으면 가능)
	{
		Knight knight;
		Dog dog = (Dog)knight; // 타입 변환 생성자 - 없으면 error 발생

		Knight knight2 = dog; // 타입 변환 연산자
	}

	// [2] 연관 없는 클래스 사이의 참조 타입 변환
	// 타입 변환 생성자, 타입 변환 연산자 --> 값 타입 변환에서만 영향을 미치지 ref 타입 변환에는 영향을 미치지 못함
	// 특징) 명시적으로는 OK
	{
		Knight knight;
		// 어셈블리 : 포인터 = 참조

		// [주소] -> [Dog]
		// 주소 자체를 수정한 것이 아닌 주소를 타고 들어가기만 하는 것이라서 명시적 변환때는 통과를 시켜줌
		Dog& dog = (Dog&)knight; // 암시적으로는 안되는데 명시적으로는 된다고 뜸 --> error임 메모리를 초과해서 사용하게 됨
		dog._cuteness = 12;
	}

	// --------------- 상속 관계에 있는 클래스 사이의 변환 -----------------
	// [1] 상속 관계 클래스의 값 타입 변환
	// 특징) 자식 -> 부모 ok / 부모 -> 자식 No
	{
		// Dog dog;
		// Bulldog bulldog = dog; // 암시적, 명시적 둘다 안됨

		Bulldog bulldog;
		Dog dog = bulldog; // 자식이 부모에게 가는 방향은 OK
	}

	// [2] 상속 관계 클래스의 탐조 타입 변환
	// 특징) 자식->부모 OK / 부모 ->자식(암시적 No) 하지만 명시적으로 하면 Ok
	{
		// Dog dog;
		// Bulldog& bulldog = (Bulldog&)dog; // 메모리 구조상으로 dog가 작은데 더 큰 bulldog으로 변경하게 되면 건드려서는 안될 값을 건들게 됨 -> [2] 연관 없는 클래스 사이의 참조 타입 변환

		// [age cuteness french] 를 갖고  있는 bulldog이 dog가 가지고 있는 age, cuteness를 다 가지고 있어서 암시적 변환도 가능
		Bulldog bulldog;
		Dog& dog = bulldog;
	}

	// 결론)
	// [값 타입 변환] : 진짜 비트열도 바꾸고~ 논리적으로 말이 되게 바꾸는 변환
	// - 논리적으로 말이 된다? (ex. Bulldog -> Dog) OK
	// - 논리적으로 말이 안된다. (ex. Dog -> Bulldog, Dog -> Knight) 안됨
	// [참조 타입 변환] : 비트열은 냅두고 우리의 '관점'만 바꾸는 변환
	// - 땡깡 부리면(명시적 요구) 해주긴 하는데, 말 안해도 '그냥' (암시적)으로 해줄지는 안전성 여부와 연관이 있음
	// -- 안전하다? (ex. Bulldog -> Dog&) '그냥' (암시적으로) ok
	// -- 위험하다? (ex. Dog -> Bulldog&)
	// --- 메모리 침범 위험이 있는 경우는 '그냥' (암시적으로) 해주진 않음 (위험하니까)
	// --- 명시적으로 정말 정말 하겠다고 최종 서명을 하면 OK

	return 0;
}