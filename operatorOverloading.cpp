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


class Position
{
public:

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

	void operator=(int arg)
	{
		_x = arg;
		_y = arg;
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

	return 0;
}