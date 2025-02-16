#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 마무리

// 1) 포인터 vs 배열 2탄
// 2) 주의사항

int& TestRef()
{
	int a = 1;
	return a;
}

int* TestPointer()
{
	int a = 1;
	return &a;
}

void TestWrong(int* ptr)
{
	int a[100] = {};
	a[99] = 0xAAAAAAAA;
	*ptr = 0x12341234;
}

int main()
{
	// 주소를 담는 바구니
	// 진퉁은 저~ 멀리 어딘가에 
	// p는 단지 그곳으로 워프하는 포탈
	int* p;

	// 원조 데이터
	// 닭장처럼 데이터의 묶음 (엄청 많고 거대)
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	// 많은 사람들이 [배열 = 포인터] 라고 착각 하는 경향이 있음

	// - [배열의 이름]은 배열의 시작 주소값을 가리키는 TYPE* 포인터로 변환 가능!

	p = arr;

	// -[Type형 1차원 배열]과 [type*형 포인터]는 완전히 호환이 된다
	cout << p[0] << endl;
	cout << arr[0] << endl;
	cout << p[5] << endl;
	cout << arr[5] << endl;
	cout << *p << endl;
	cout << *arr << endl;
	cout << *(p + 3) << endl;
	cout << *(arr + 3) << endl;

	// [1][2][3][4] - 알아두면 좋을 내용
	int arr2[2][2] = { {1, 2}, { 3, 4} };

	// 주소2[] << 4바이트
	// 주소1[주소2]
	// pp [주소1]
	int** pp = (int**)arr2;

	// type name [개수]

	// [1][2] [3][4]
	// [주소]
	int(*p2)[2] = arr2;

	cout << (*p2)[0] << endl;
	cout << (*p2)[1] << endl;
	cout << (*(p2 + 1))[0] << endl;
	cout << (*(p2 + 1))[1] << endl;
	cout << p2[0][0] << endl;
	cout << p2[0][1] << endl;
	cout << p2[1][0] << endl;
	cout << p2[1][1] << endl;

	
	int* pointer = TestPointer(); // 지역변수의 메모리를 사용하고 있는데 에러가 발생하지 않음

	TestWrong(pointer);

	*pointer = 123; // 심지어 해당 메모리를 건드리고 있어도 문제가 생기지 않음

	return 0;
}