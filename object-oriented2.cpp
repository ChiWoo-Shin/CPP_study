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
	// 이 중에서 인자를 1개만 받는 [기타 생성자]를
	// [타입변환 생성자]라고 부르기도 함

	// 타입변환 용도로 사용하지 않고 명시적으로만 사용하기 위해선 explicit를 앞에 붙이면됨
	explicit Knight(int hp)
	{
		cout << "Knight(int) 생성자 호출" << endl;
		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	Knight(int hp, int attack, int posX, int posY)
	{
		_hp = hp;
		_attack = attack;
		_posY = posY;
		_posX = posX;
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

void HelloKnight(Knight k)
{
	cout << "Hello Knight" << endl;
}

// Instantiate 객체를 만든다!
int main()
{
	// [1] 기본 생성자
	Knight k1;
	k1._hp = 100;

	// [3] 일반 생성자
	// Knight k1(100);
	Knight k5(100, 0, 0, 0);

	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	// [2] 복사 생성자
	Knight k2(k1); // 복사 생성자를 주석처리해도 정상 동작하는 것을 확인할 수 있음 --> 기본적으로 생성될수 있다 라는 것을 알 수 있음
	
	Knight k3 = k1; // 복사 생성자를 사용해서 knight를 생성

	Knight k4; // 기본 생성자를 사용한 후
	k4 = k1; // 복사를 진행함

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	// 암시적 형변환 -> 컴파일러가 알아서 바꿔치기
	int num = 1;
	float f = (float)num; // 명시적 < 우리가 코드로 num을 float 바구니에 넣으라고 주문
	double d = num; // 암시적 << 별말 안했는데 컴파일러가 알아서 처리함

	Knight k6;
	k6 = (Knight)1; // [타입 변환 생성자]로 인해서 가능한 문법이됨 --> Explicit를 추가한 이후 에러가 발생함 --> 명시적으로 변환을 하면 문제가 없어짐

	HelloKnight((Knight)5); // --> Explicit를 추가한 이후 에러가 발생함 --> 명시적으로 변환을 하면 문제가 없어짐

	return 0;
}