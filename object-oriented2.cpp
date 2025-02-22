#include <iostream>
using namespace std;

// 오늘의 주제 : 생성자와 소멸자

// 생성자(Consttructor) 와 소멸자(DeConstuctor)
// 클래스에 '소속'된 함수들을 멤버 함수라고 함
// 이 중에서 굉장히 특별한 함수 2종이 있는데, 바로 [시작]과 [끝]을 알리는 함수들
// - 시작(탄생) -> 생성자 (여러개 존재 가능)
// - 끝(소멸) -> 소멸자 (오직 1개만)

// 암시적(implicit) 생성자
// 생성자를 명시적으로 만들지 않으면,
// 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 자동으로 만들어짐.
// -> 그러나 우리가 명시적(Explicit)으로  아무 생성자 하나 만들면,
// 자동으로 만들어지던 [기본 생성자]는 더 이상 만들어지지 않음.

// class는 일종의 설계도
class Knight // knight에 대한 설계도
{
public:
	// [1] 기본 생성자 (인자가 없음) -- 만약 생성자를 명시적으로 만들지 않으면 컴파일러가 자동으로 만들어줌 --> 암시적 생성자
	Knight() // 시작할때 무조건 호출됨
	{
		cout << "Knight() 기본 생성자 호출" << endl;
		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// [2] 복사 생성자 - 자기 자신의 클래스 참조 타입을 인자로 받음
	// (일반적으로 '똑같은' 데이터를 지닌 객체가 생성되길 기대함
	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_attack = knight._attack;
		_posY = knight._posY;
		_posX = knight._posX;
	}

	// [3] 기타 생성자
	Knight(int hp)
	{
		cout << "Knight(int) 생성자 호출" << endl;
		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// 소멸자 -- return 0; 이후에 호출되고있음
	~Knight()
	{
		cout << "~Knight() 소멸자 호출" << endl;
	}

	
	// 멤버 함수
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		//this: // Knight* this 자기 자신을 가리키는 포인터
		_hp = 0;
		this->_hp = 1;
		cout << "Die" << endl;
	}


public:
	// 멤버 변수 --> 많이 쓰는 표현방법 : m_hp, mHp, _hp
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

// Instantiate 객체를 만든다!
int main()
{
	// [1] 기본 생성자
	Knight k1;
	k1._hp = 100;

	// [3] 일반 생성자
	Knight k1(100);

	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	// [2] 복사 생성자
	Knight k2(k1);

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	return 0;
}