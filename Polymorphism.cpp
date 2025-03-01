#include <iostream>
using namespace std;
// 오늘의 주제 : 다형성

// 객체지향 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성 = 캡슐화
// - 다형성

// 다형성 (Polymorphism = Poly + morph) = 겉은 똑같은데, 기능이 다르게 동작
// - 오버로딩(Overloading) = 함수 중복 정의 = 함수 이름의 재사용
// - 오버라이딩(Overriding) = 재정의 = 부모 클래스의 함수를 자식 클래스에서 재정의

// 바인딩(Binding) = 묶는다
// - 정적 바인딩(Static Binding) : 컴파일 시점에 결정
// - 동적 바인딩(Dynamic Binding) : 실행 시점에 결정

// 일반 함수는 정적바인딩을 사용하게 됨
// 동적 바인딩을 원한다면? -> 가상함수(virtual function)

// 그런데 실제 객체가 어떤 타입인지 어떻게 알고 가상함수를 호출해주는걸까?
// - 가상 함수 테이블(vftable)
// .vftable [] 4바이트(32) 8바이트(64)
// [VMove] [VDie]
// 가상함수 테이블은 생성자의 선처리 영역에서 세팅해줌

// 순수 가상 함수 : 구현은 없고 '인터페이스' 만 전달하는 용도로 사용하고 싶을 경우
// 추상 클래스 : 순수 가상 함수가 1개 이상 포함되면 바로 추상 클래스로 간주
// - 직접적으로 객체를 만들수 없게 됨
class Player
{
public:
	Player()
	{
		_hp = 100;
	}
	void Move() { cout << "Move Player !" << endl; }
	void Move(int a) { cout << "Move Player (int) !" << endl; } // 오버로딩
	virtual void VMove() { cout << "VMove Player !" << endl;  }
	virtual void VDie() { cout << "VDie Player !" << endl; }

	// 순수 가상 함수 -- 상속받은 애들이(Knight, Mage) 모두 VAttack()을 만들어서 사용해라 라고 압박
	virtual void VAttack() = 0; 

public:
	int _hp;
};

class Knight : public Player
{
public: 
	Knight()
	{
		_stamina = 100;
	}
	void Move() { cout << "Move Knight !" << endl; } // 오버라이딩

	// 가상함수는 재정의를 하더라도 가상 함수임.
	virtual void VMove() { cout << "VMove Knight !" << endl; } 
	void VDie() { cout << "VDie Knight !" << endl; }// virtual이 없어도 가상함수로 인식
	void VAttack() { cout << "VDie VAttack !" << endl; }
public:
	int _stamina;
};

class Mage : public Player
{
public:
	void VAttack() { cout << "VDie VAttack !" << endl; }
public:
	int _mana;
};

void MovePlayer(Player* player)
{
	// 정적 바인딩
	player->Move();
	
	// 동적 바인딩
	player->VMove(); // 이건 player의 Move함수 호출 --> 아무리 자식클래스를 타고 올라와도 부모클래스의 Move를 호출함
	player->VDie();
}

//void MoveKnight(Knight* knight)
//{
//	knight->Move();
//}

int main()
{
	// Player p; // 순수 가상 함수를 추가한 후에는 추상클래스가 됐기때문에 단독으로 사용할 수 없게 됨.
	// p.Move(); // 첫번째 Move 를 따라감
	// p.Move(100); // 두번째 Move를 따라감
	// MovePlayer(&p); // player가 플레이어? Yes
	// MoveKnight(&p); // error가 발생 --> player가 기사? No --> 부모클래스에서 자식클래스를 탐색하지 않음

	Knight k;
	k.Move();
	//MoveKnight(&k); // 기사는 기사다? Yes
	MovePlayer(&k); // 기사는 플레이어다? Yes error 발생 X --> 자식클래스는 부모클래스가 맞다라고 대답함
	// 위 내용을 이용하면 결국 모든 자식클래스가 가져야하는 것이라면 부모클래스를 이용해서 할 수 있다는 의미.
	// 하지만 가상함수를 사용한다면 자식클래스가 가지고 있는 VMove를 불러서 사용하게됨


	return 0;
}