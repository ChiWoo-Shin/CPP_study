#include <iostream>
using namespace std;

// 캐스팅 (타입 변환)

class Player
{
public:
	 virtual ~Player() { }
};

class Knight : public Player
{
public:
};

class Archer : public Player
{
public:
};

class Dog
{

};

// 1) static_cast
// 2) dynamic_cast
// 3) const_cast
// 4) reinterpret_cast

void PrintName(char* str)
{
	cout << str << endl;
}

int main()
{
	// static_cast : 타입 원칙에 비춰볼 때 상식적인 캐스팅만 허용
	// 1) int <-> float
	// 2) Player* -> Knight* (다운 캐스팅) << 단, 안정성은 보장 못함

	int hp = 100;
	int maxHp = 200;
//	float ratio = hp/maxHp; // -> 0
//	float ratio = (float)hp / maxHp; // -> 0.5
	float ratio = static_cast<float>(hp) / maxHp;

	// 부모 -> 자식  자식 -> 부모
	Player* p = new Archer();
	Knight* k1 = static_cast<Knight*>(p);
	

	// dynamic_cast : 상속 관계에서의 안전한 형변환 지원
	// RTTI (RunTime Type Information)
	// 다형성을 활용하는 방식
	// - virtual 함수를 하나라도 만들면, 객체의 메모리에 가상 함수 테이블 (vftable) 주소가 기입됨
	// - 만약 잘못된 타입으로 캐스팅을 했으면, nullptr 변환 **************
	// 이를 이용해서 맞는 타입으로 캐스팅을 했는지 확인할때 유용
	// 확인하는 과정이 있기 때문에 static_cast보다 느리게 동작함.
	Knight* k2 = dynamic_cast<Knight*>(p); // virtual 함수 없이 사용하면 "오류 - 'dynamic_cast': 'Player'은(는) 다형 형식이 아닙니다."가 발생

	// const_cast : const를 붙이거나 떼거나 할때 활용
	PrintName("Rookiss");
	// 수업에서는 const char[8] 을 char*로 변환할 수 없다는 에러가 발생함
	// 이를 해결하기 위해서 const_cast<char*> 를 넣어야 하는데
	// PrintName(const_cast<char*>("Rookiss"));
	// 나는 해당 에러가 발생하지 않음

	// reinterpret_cast
	// 가장 위험하고 강력한 형태의 캐스팅
	// 're-interpret' : 다시 간주하다/ 생각하다
	// - 포인터랑 전혀 관계없는 다른 타입 변환 등
	// __int64 address = k2; // 아무 연관성이 없기때문에 에러가 발생
	__int64 address = reinterpret_cast<__int64>(k2);
	// 오류(활성) E0144	"Knight *" 형식의 값을 사용하여 "long long" 형식의 엔터티를 초기화할 수 없습니다.

	Dog* dog1 = reinterpret_cast<Dog*>(k2); // 포인터끼리도 변환 가능
	
	void* p = malloc(1000);
	// 사용할때는 이렇게 void로 받는 것을 Dog 등의 포인터로 변환할때 사용함
	Dog* dog2 = reinterpret_cast<Dog*>(p);

	return 0;
}