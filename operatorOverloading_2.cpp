#include <iostream>
using namespace std;

// ������ ���� : ������ �����ε�(operatorOverloading)

// ������ vs �Լ�
// -�����ڴ� �� �������� ����/Ÿ���� �����Ǿ� ����

// ������ �����ε�?
// �ϴ� [������ �Լ�]�� �����ؾ���
// �Լ��� ����Լ� vs �����Լ��� �����ϴ� �� ó��, ������ �Լ��� �ΰ��� ������� ���� �� ����

// - ��� ������ �Լ� version
// -- a op b ���¿��� ������ �������� ����� (a�� Ŭ�������� ����. a�� '���� �ǿ�����' ��� ��)
// -- �Ѱ�) a�� Ŭ������ �ƴϸ� ����� ����

//  - ���� ������ �Լ� version
// -- a op b ���¶�� a, b ��θ� ������ �Լ��� �ǿ����ڷ� ������ش�

// �׷� ������ �� ������?
// �׷��� ����. ������ �� �� �ϳ��� �����ϴ� ��쵵 �ֱ� ����.
// - ��ǥ������ ���� ������ ( a = b )�� ���������� version���δ� �������.

// ���� ���� ������
// - ���� �����ڰ� ���� �迡 [���� ���� ������]�� ���� �˾ƺ���
// �� �� ��츰�� [���� ������] [���� ������] [���� ���� ������] @_@
// - ���� ���� ������ = ���� ������ ��, �ڱ� �ڽ��� ���� Ÿ���� ���ڷ� �޴� ��

// ��Ÿ
// - ��� �����ڸ� �� �����ε� �Ҽ� �ִ� ���� �ƴ�.(:: . .* �̷��� �ȵ�)
// - ��� �����ڰ� �� 2�� ���� �ִ� ���� �ƴ�. ++ -- �� ��ǥ�� (���� ������)
// - ���� ������ ++ --
// -- ������ (++a) operator++()
// -- ������ (a++) operator++(int a)

class Position
{
public:

	//Position(const Position& arg) // ���� ������
	//{

	//}

	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;

		return pos;
	}

	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;

		return pos;
	}

	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}
	
	Position& operator=(int arg) // void �� return �ص� ������ �Ϲ������� �ڱ� �ڽ��� type�� return ��
	{
		_x = arg;
		_y = arg;

		// Position* this = �� �ڽ��� �ּ�;
		return *this;
	}
	// [���� ������] [���� ���� ������] �� Ư�� ��츦 �޴� ������,
	// �� �״�� ��ü�� '����'�Ǳ� ���ϴ� Ư¡ ����
	// TODO) �����Ҵ� �ð��� �� �ڼ��� �˾ƺ� ��

	Position& operator=(const Position& arg) // const �� �ٿ��� ���� �о���� ���Ҹ� �ϰ� ��������
	{
		_x = arg._x;
		_y = arg._y;

		// Position* this = �� �ڽ��� �ּ�;
		return *this;
	}

	Position& operator++()
	{
		_x++;
		_y++;

		return *this;
	}

	Position operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;
		return ret;
	}

public:
	int _x;
	int _y;
};

Position operator+(int a, const Position& b) // ���� ������ �Լ� a�� Ŭ������ �ƴϾ ��밡����
{
	Position ret;
	ret._x = b._x + a;
	ret._y = b._y + a;

	return ret;
}

//void operator=(const Position& a, int arg) // error �߻� - operator�� ������������մϴ�.
//{
//	a._x = arg;
//	a._y = arg;
//}

int main()
{
	int a = 1;
	int b = 2;
	int c = a + b;
	int d = c++;

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos + pos2; // pos3 = pos.operator+(pos2); ������ ���
	// 1. error �߻� -> �ڵ����� ������ ���� ã�� �ʰ� ������ ����߸���
	// 2. Position �ȿ� operator+ �� ���� ���Ŀ��� ������ ������ ����

	Position pos4 = pos3 + 1; // operator+(int arg) ���п� �������ϰԵ�
	pos4 = pos3.operator+(1);
	Position pos5 = 1 + pos4; // error �߻� ���� �ǿ����ڰ� Ŭ������ �ƴ�. -> ���������� �Լ��� ���ؼ� �ذ���

	bool isSame = (pos3 == pos4);

	Position pos6;
	pos6 = 6;
	pos3 = (pos6 = 6); // return type�� void���� �ڱ� �ڽ�(Position)���� �����߱⶧���� ���� ����

	pos6 = pos3++;
	Position pos7;
	pos7 = ++(pos6++);
	++(++pos7);

	return 0;
}