#include <iostream>
using namespace std;

// 오늘의 주제 : 객체지향 마무리

// 1) struct vs class

// C++ 에서는 struct나 class나 종이 한장 차이이다.
// struct는 기본 접근 지정자가 public이고 class는 private이다.
// 왜 이렇게 했을까? C++은 C언어에서 파생되어 발전했기 때문에, 호환성을 지키기 위함.
// -> struct는 그냥 구조체 (데이터 묶음)을 표현하는 용도
// -> class는 객체 지향 프로그래밍의 특징을 나타내는 용도

struct TestStruct
{
public: // struct안에 아무것도 없으면 default는 public
	int _a;
	int _b;
};

class TestClass
{
private: // class 안에 아무것도 없으면 default 는 private
	int _a;
	int _b;
};


// 2) static 변수, static 함수 (static = 정적 = 고정된)

class Marine
{
public:
	// 특정 마린 객체에 종속적
	int _hp;

	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	static void setAttack() // 객체와 연관성이 있는 애들을 호출하면 error가 발생
	{
		s_attack = 100; // 하지만 static으로 되어있는건 호출해도 문제가 안됨
	}

	// 특정 마린 객체와 무관
	// 마린이라는 '클래스' 자체와 연관
	static int s_attack; // 설계도상으로만 존재
};

// static 변수는 어떤 메모리?
// 초기화 하면 .data
// 안하면 .bss

int Marine::s_attack = 0;

class Player
{
public:
	int _id;

};

// 정적 전역 객체
static int s_global = 1;

int GenerateId()
{
	// 생명주기 : 프로그램 시작/ 종료 (메모리에 항상 올라가 있음)
	// 가시범위 : 
	// 1 2 3 4 5 6 을 순서대로 뱉어주는 함수를 원함
	// 정적 지역 객체
	static int s_id = 1;
	
	return s_id++;
}

int main()
{
	TestStruct ts;
	ts._a = 1;

	TestClass tc;
	// tc._a = 1; // error 발생 -- class를 생성할때 public으로 지정해주지 않으면 private으로 동작하기 때문에

	Marine m1;
	m1._hp = 40;
	m1.TakeDamage(10);
	// m1.s_attack = 6;
	Marine::s_attack = 6;

	Marine m2;
	m2._hp = 40;
	// m2.s_attack = 6;
	m2.TakeDamage(5);

	// 마린 공격력 업그레이드 완료! (Academy에서 업그레이드 끝)
	Marine::s_attack = 7;
	Marine::setAttack();

	// 스택이 아닌 .data 영역
	static int id = 10;
	int a = id;

	cout << GenerateId() << endl; // 1
	cout << GenerateId() << endl; // 2
	cout << GenerateId() << endl; // 3
	cout << GenerateId() << endl; // 4
	cout << GenerateId() << endl; // 5

	return 0;
}