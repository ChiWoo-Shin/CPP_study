#include <iostream>
using namespace std;

// ���� : �Լ�(���ν���, �޼ҵ�, ��ƾ)

/*

input ���� ������ �ް�, output���� ������ ������ �����ش�.

��ȯŸ�� �Լ��̸�()
{
	�Լ� ����
	return ~~;
}

*/

// Hello World �� �ֿܼ� ����ϴ� �Լ��� ������!
// input : ���� / output : ����
// Ÿ�� : int float double char �� + void

void PrintHelloWorld()
{
	cout << "Hello World" << endl;

	return;
}

// ������ �Է�(�Լ�) �޾Ƽ�, �ֿܼ� ����ϴ� �Լ��� ������
// input : int // output : ����

void printNumber(int x)
{
	cout << x << endl;
}

// 2�� ���ϰ� ������� ��� �Լ��� ������
// input : int / output : int

int MultiplyBy2(int a)
{
	return a * 2;
}

// �� ���ڸ� ���ؼ� ������� ��� �Լ��� ������
// input : int, int / output : int

int MultiplyBy(int a, int b)
{
	return a * b;
}

int main()
{
	PrintHelloWorld();

	int number;

	cin >> number;
	printNumber(number);

	int number2, number2_result;
	cin >> number2;
	
	number2_result = MultiplyBy2(number2);
	
	printNumber(number2_result);

	int number3, number4, number3_4_result;
	cin >> number3 >> number4;
	number3_4_result = MultiplyBy(number3, number4);
	printNumber(number3_4_result);
}