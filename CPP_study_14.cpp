#include <iostream>
using namespace std;

// 주제 : 함수(프로시저, 메소드, 루틴)

/*

input 으로 무엇을 받고, output으로 무엇을 뱉을지 정해준다.

반환타입 함수이름()
{
	함수 내용
	return ~~;
}

*/

// Hello World 를 콘솔에 출력하는 함수를 만들어보자!
// input : 없음 / output : 없음
// 타입 : int float double char 등 + void

void PrintHelloWorld()
{
	cout << "Hello World" << endl;

	return;
}

// 정수를 입력(함수) 받아서, 콘솔에 출력하는 함수를 만들어보자
// input : int // output : 없음

void printNumber(int x)
{
	cout << x << endl;
}

// 2를 곱하고 결과물을 뱉는 함수를 만들어보자
// input : int / output : int

int MultiplyBy2(int a)
{
	return a * 2;
}

// 두 숫자를 곱해서 결과물을 뱉는 함수를 만들어보자
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