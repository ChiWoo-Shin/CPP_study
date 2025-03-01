#include <iostream>
using namespace std;
// ������ ���� : ���м�

// ��ü���� (OOP Object Oriented Programming)
// - ��Ӽ�
// - ���м�
// - ������

// ���м�(Data hiding) = ĸ��ȭ (Encapsulation)
// ���� �Ǵ� ���� ����ϰ� ����ڴ�!
// ����� ����?
// - 1) ���� �����ϰ� �ǵ帮�� �ȵǴ� ���
// - 2) �ٸ� ��η� �����ϱ� ���ϴ� ���

// ex)
// �ڵ���
// - �ڵ�
// - ���
// - ����
// - ��
// - ���� ���⼺

// �Ϲ� ������ ���忡�� ����ϴ� ��?
// - �ڵ�/���/��
// ���� �� (������ �ǵ帮�� ū�ϳ�)
// - ����, ���� ���⼱

// public (������?) protected (��ȣ�޴�?) private (������?)
// - public : �������׳� ����. 
// - protected : ���� ���� �ڼյ鿡�Ը� ���
// - private : ���� ��� << class Car ���ο�����! ���

// ��� ���� ������ : ���� �������� �θ���� ������ ��� ��������?
// �θ������ �������� ������ �� ���� �ڼյ����׵� �Ȱ��� ������� ���� ����
// - public : ������ ��� -- �θ���� ���� ���� �״�� (public -> public, protected -> protected)
// - protected : ��ȣ�޴� ��� -- �� �ڼյ����׸� �����ٰž� (public -> protected, protected -> protected)
// - private : �������� ��� -- �������� �� ���� �ڼյ����״� �ƿ� �ȹ����� (public -> private, protected -> private)


class Car
{
public: // (���) ���� ������
	void MoveHandle() { }
	void PushPedal() { }
	void OpenDoor() { }
	void TurnKey()
	{
		// ...
		RunEngine();
	}

protected:
	// �����ϸ� �ȵǴ� ����
	void DisassembleCar() { } // ���� ����
	void RunEngine() { } // ���� ����
	void ConnectCircuit() { } // ���⼱ ����

public:
	// �ڵ�
	// ���
	// ����
	// ��
	// ���� ���⼱
};

class SuperCar : protected Car // ��� ���� ������
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
};

class TestSuperCar : public SuperCar // ��� ���� �����ڸ� �������� build�� �� error�� �߻��Ѵ�
{
public:
	void Test()
	{
		DisassembleCar(); // error �߻� supercar������ ��ӵǰ� ���� ��ӹ��� ���� (SuperCar�� Car�� private���� ��ӹ޾ұ� ������)
		// ������ ���ؼ� Car�� protected �Ǵ� public���� ����ؾ���.
	}
};

// 'ĸ��ȭ'
// ������ �����Ϳ� �Լ��� �������� ������� ��
class Berserker
{
public:
	// _hp�� SetBerserkerMode() �� ĸ��ȭ ���Ѽ� ���� �������� ���ϰ� GetHp�� SetHp�� ���ؼ��� ������ �� �ְ� �س���
	int GetHp() { return _hp;  }
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}

private:
	// ��� : ü���� 50���Ϸ� �������� ����Ŀ ��� �ߵ�
	void SetBerserkerMode()
	{
		cout << "�ſ� ������!" << endl;
	}

//public:
private:
	int _hp = 100;
};

int main()
{
	Car car;
	
	// car.DisassembleCar(); --> private or protected �� �����Ǿ��־ Error �߻�
	// car.RunEngine(); --> private or protected �� �����Ǿ��־ Error �߻�

	SuperCar SCar; // SCar.~~ ������ protected�� ����� �Լ����� ��ȸ�� �ȵǴ� ���� Ȯ�� ����

	Berserker b;
	
	b.SetHp(20);

	TestSuperCar TSCar;
	TSCar.PushRemoteController(); // ��������.

	return 0;
}