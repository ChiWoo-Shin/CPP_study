#include <iostream>
using namespace std;

// 오늘의 주제 : 초기화 리스트
// 멤버 변수 초기화 ? 다양한 문법이 존재
// 초기화 왜 해야할까?
// - 버그 예방에 중요
// - 포인터 등 주소값이 연루되어 있을 경우

// 초기화 방법
// - 생성자 내에서
// - 초기화 리스트
// - C++11 문법

// 초기화 리스트
// - 일단 상속 관계에서 원하는 부모 생성자 호출할 때 필요하다
// - 생성자 내에서 초기화 vs 초기화 리스트
// -- 일반 변수는 별 차이 없음
// -- 멤버 타입이 클래스인 경우 차이가 난다
// -- 정의함과 동시에 초기화가 필요한 경우 (참조 타입, const 타입)

class Inventory
{
public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int size) { cout << "Inventory(int size)" << endl; _size = size; }

	~Inventory() { cout << "~Inventory()" << endl; }

public:
	int _size = 10;
};

class Player
{
public:
	Player() { }
	Player(int id) { }
};

// Is-A (Knight Is-A Player?) OK --> 상속 관계
// Is-A (Knight Is-A Inventory?) No

// Has-A (Knight Has-A Inventory?) OK --> 포함 관계

class Knight : public Player
{
public:
	Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100) // 초기화 할때는 이부분(초기화 리스트)을 이용해서 하는게 좋다
		/*
		선처리 영역

		Inventory() 의 생성자가 호출됨
		Knight가 소멸될때 ~Inventory() 도 같이 소멸됨

		*/
	{
		_hp = 100;
		//_inventory = Inventory(20); // 여기서 만들면 기존에 만들었던 _inventory에 덮어써지게됨, 이렇게 되면 앞서 만들어진 _inventory를 소멸시키고 자신에게 맞는 생성자를 다시 생성함
		
		// 여기서 선언하면 소용이 없음
		// 이미 선처리가 끝난 상태이기 때문에 값이 변동되지 않음
		// _hpRef = _hp; 
		// _hpConst = 100;
	}
	
public:
	int _hp;
	Inventory _inventory;

	int& _hpRef;
	// int& _hpRef = _hp; --> C++11 문법 (mordern C++)
	const int _hpConst;
	// const int _hpConst = 100; --> C++11 문법 (mordern C++)
};

int main()
{
	Knight k;

	cout << k._hp << endl;

	return 0;
}