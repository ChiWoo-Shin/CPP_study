#include <iostream>
using namespace std;
// 오늘의 주제 : 은닉성

// 객체지향 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

// 은닉성(Data hiding) = 캡슐화 (Encapsulation)
// 몰라도 되는 것은 깔끔하게 숨기겠다!
// 숨기는 이유?
// - 1) 정말 위험하고 건드리면 안되는 경우
// - 2) 다른 경로로 접근하길 원하는 경우

// ex)
// 자동차
// - 핸들
// - 페달
// - 엔진
// - 문
// - 각종 전기성

// 일반 구매자 입장에서 사용하는 것?
// - 핸들/페달/문
// 몰라도 됨 (오히려 건드리면 큰일남)
// - 엔진, 각종 전기선

// public (공개적?) protected (보호받는?) private (개인의?)
// - public : 누구한테나 공개. 
// - protected : 나와 나의 자손들에게만 허락
// - private : 나만 사용 << class Car 내부에서만! 사용

// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려줄지?
// 부모님한테 물려받은 유산을 꼭 나의 자손들한테도 똑같이 물려줘야 하진 않음
// - public : 공개적 상속 -- 부모님의 유산 설계 그대로 (public -> public, protected -> protected)
// - protected : 보호받는 상속 -- 내 자손들한테만 물려줄거야 (public -> protected, protected -> protected)
// - private : 개인적인 상속 -- 나까지만 잘 쓰고 자손들한테는 아예 안물려줌 (public -> private, protected -> private)


class Car
{
public: // (멤버) 접근 지정자
	void MoveHandle() { }
	void PushPedal() { }
	void OpenDoor() { }
	void TurnKey()
	{
		// ...
		RunEngine();
	}

protected:
	// 접근하면 안되는 영역
	void DisassembleCar() { } // 차를 분해
	void RunEngine() { } // 엔진 구동
	void ConnectCircuit() { } // 전기선 연결

public:
	// 핸들
	// 페달
	// 엔진
	// 문
	// 각종 전기선
};

class SuperCar : protected Car // 상속 접근 지정자
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
};

class TestSuperCar : public SuperCar // 상속 접근 지정자를 빼먹으면 build할 때 error가 발생한다
{
public:
	void Test()
	{
		DisassembleCar(); // error 발생 supercar까지만 상속되고 나는 상속받지 못함 (SuperCar가 Car를 private으로 상속받았기 때문에)
		// 수정을 위해서 Car를 protected 또는 public으로 상속해야함.
	}
};

// '캡슐화'
// 연관된 데이터와 함수를 논리적으로 묶어놓은 것
class Berserker
{
public:
	// _hp와 SetBerserkerMode() 를 캡슐화 시켜서 직접 접근하지 못하고 GetHp와 SetHp를 통해서만 접근할 수 있게 해놓음
	int GetHp() { return _hp;  }
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}

private:
	// 사양 : 체력이 50이하로 떨어지면 버서커 모드 발동
	void SetBerserkerMode()
	{
		cout << "매우 강해짐!" << endl;
	}

//public:
private:
	int _hp = 100;
};

int main()
{
	Car car;
	
	// car.DisassembleCar(); --> private or protected 에 설정되어있어서 Error 발생
	// car.RunEngine(); --> private or protected 에 설정되어있어서 Error 발생

	SuperCar SCar; // SCar.~~ 에서도 protected로 선언된 함수들은 조회가 안되는 것을 확인 가능

	Berserker b;
	
	b.SetHp(20);

	TestSuperCar TSCar;
	TSCar.PushRemoteController(); // 정상동작함.

	return 0;
}