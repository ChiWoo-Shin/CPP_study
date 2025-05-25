#include <iostream>
using namespace std;

// 오늘의 주제 : 얕은 복사 vs 깊은 복사

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}
	~Pet()
	{
		cout << "~Pet()" << endl;
	}
	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet& pet)" << endl;
	}
};

class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // 깊은 복사
	}

	Knight& operator=(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // 깊은 복사
		return *this;
	}

	~Knight()
	{
		delete _pet;
	}

public:
	int _hp = 100;
	// Pet _pet; // 이렇게 하면 Knight가 생성되면 Pet도 생성되고, Knight가 소멸하면 Pet도 소멸하게됨
	Pet* _pet;
};

int main()
{
	// Pet* pet = new Pet();

	Knight knight; // 기본 생성자
	knight._hp = 200;
	// knight._pet = pet;
	Knight knight2 = knight; // 복사 생성자
	// 위랑 동일한 방법Knight knight3(knight);
	Knight knight3; // 기본 생성자
	knight3 = knight;  // 복사 대입 연산자

	// [복사 생성자] + [복사 대입 연산자]
	// 둘 다 안 만들어주면 컴파일러가 '암시적으로' 만들어준다.

	// 중간 결론) 컴파일러가 알아서 잘 만들어준다?
	// 수고하세요~ 다음 주제로 넘어갈까요? << NO

	// [얕은 복사 Shallow Copy]
	// 멤버 데이터를 비트열 단위로 '똑같이' 복사 (메모리 영역 값을 그대로 복사)
	// 포인터는 주소값 바구니 -> 주소값을 똑같이 복사 -> 동일한 객체를 가리키는 상태가 됨
	// Stack : Knight [ hp 0x1000 ] -> Heap 0x1000 Pet[    ]
	// Stack : Knight2 [ hp 0x1000 ] -> Heap 0x1000 Pet[    ]
	// 이게 문제가 되는 이유는 똑같은 Pet을 3번을 지우려고 하기 때문에 error가 발생함

	// [ 깊은 복사 Deep Copy ]
	// 멤버 데이터가 참조(주소) 값이라면, 데이터를 새로 만들어준다 (원본 객체가 참조하는 대상까지 새로 만들어서 복사)
	// 포인터는 주소값 바구니 -> 새로운 객체를 생성 -> 상이한 객체를 가리키는 상태가 됨
	// Stack : Knight [ hp 0x1000 ] -> Heap 0x1000 Pet[    ]
	// Stack : Knight2 [ hp 0x2000 ] -> Heap 0x2000 Pet[    ]
	// Stack : Knight3 [ hp 0x3000 ] -> Heap 0x3000 Pet[    ]
		

	return 0;
}