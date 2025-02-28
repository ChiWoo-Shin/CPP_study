#include <iostream>
using namespace std;

// 오늘의 주제 : 상속성

// 객체지향 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// 상속(Interitance) ? 부모 -> 자식에게 유산을 물려준다

// 생성자(N개 생성가능)/소멸자(1개만 생성 가능)
// - Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 둘 다 호출된다.
// 생성자와 소멸자는 상속하는 개념이 아니라 자신도 가지고 있음
// 보여지는 순서는 {부모 생성자 -> 자식 생성자 -> 자식 소멸자 -> 부모 소멸자}
// 하지만 실제로는 어셈블리를 열어보면 자식 생성자 호출을 타고 선처리 영역에서 부모 생성자를 호출하게됨

class Player
{
public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player() 기본 생성자 호출" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player() 생성자 호출" << endl;
	}

	~Player()
	{
		cout << "~Player() 소멸자 호출" << endl;
	}

	void Move() { cout << " Player Move 호출 " << endl; }
	void Attack() { cout << " Player Attack 호출 " << endl; }
	void Die() { cout << " Player Die 호출 " << endl; }

public:
	int _hp;
	int _attack;
	int _defence;

	// StatInfo _statInfo; 도 가능
};

// class는 일종의 설계도
class Knight : public Player // 상속을 받는 방법 ": public"
{
public:
	Knight()
	/*
	선(먼저)처리 영역
	- 여기서 Player() 생성자를 호출
	*/
	{
		_stamina = 100;
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	Knight(int stamina) : Player(100)
	/*
	선(먼저)처리 영역
	- 여기서 Player() 기본 생성자를 호출

	하지만 상속으로 특정 생성자를 위와 같이 선택하게 되면
	해당 생성자 - Player(int hp) 가 호출되게 됨

	*/
	{
		_stamina = stamina;
		cout << "Knight(int hp) 타입변환 생성자 호출" << endl;
	}
	~Knight()
	{
		cout << "~Knight() 소멸자 호출" << endl;
	}
	/*
	후처리 영역
	- 여기서 ~Player() 소멸자를 호출
	*/

	// 재정의 : 부모님이 물려주신 유산을 거부하고 새로운 이름으로 만들기 가능
	void Move() { cout << " Knight Move 호출 " << endl; }

public:
	int _stamina; // 해당 클래스에 필요한것만 따로 선언도 가능함
};

class Mage : public Player
{
public:

public:
	int _mana;
};

int main()
{
	Knight k;

	k._hp = 100;
	k._attack = 10;
	k._defence = 5;
	k._stamina = 50;

	k.Move(); // 재정의한 함수를 가져다 사용하게됨
	k.Player::Move(); // 재정의한 함수가 아닌 부모에게 상속받은 함수를 사용

	k.Attack();
	k.Die();

	Knight k2(100);

	return 0;
}