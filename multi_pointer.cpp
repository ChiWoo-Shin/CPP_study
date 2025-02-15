#include <iostream>
using namespace std;

// 오늘의 주제 : 다중 포인터

void SetNumber(int *a)
{
	*a = 1;
}

void SetMessage(const char* a) // 값이 바뀌지 않음
{
	a = "Bye";
}

void SetMessage2(const char** a) // 이중 포인터
{
	*a = "Bye";
}

void SetMessage3(const char*& a) // 이렇게 쓰는것도 msg 의 값에 접근할 수 있음
{
	a = "Wow";
}

int main()
{
	int a = 0;
	SetNumber(&a);
	cout << a << endl;

	const char* msg = "Hello";
	SetMessage(msg);
	cout << msg << endl; // Hello

	// 주소2 [ ] << 1 바이트
	// 주소1[ 주소2 ] << 8바이트
	// pp[ 주소1 ] << 8바이트
	const char** pp = &msg;
	//*pp = "Bye"; --> msg가 bye로 변경됨
	SetMessage2(pp); // --> msg가 bye로 변경됨
	cout << msg << endl;

	// const chart*를 수정하기 위해서 이중 포인터를 사용했지만 
	// 삼중 사중 포인터로 가는 경우는 많지 않다

	// 다중포인터 :양파까기라고 생각하기 -> 이동할때마다 *을 하나씩 깐다

	SetMessage3(msg);
	cout << msg << endl;

	return 0;
}