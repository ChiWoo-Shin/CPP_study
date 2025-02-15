#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 vs 배열

void Test(int a)
{
	a++;
}

// 배열을 함수 인자로 넘기면, 컴파일러가 알아서 포인터로 치환 (char[] -> char*)
// 배열의 전체 주소를 넘긴게 아닌, 시작 주소만 넘긴 것임
void Test2(char a[])
{
	a[0] = 'X';
}

int main()
{
	cout << "Hello World" << endl;
	char msg[] = { 'H', 'e', 'l', 'l', 'o' , '\0' }; // \0 -> Null
	cout << msg << endl;

	// [H][e][l][l][o][][W][o][r][l][d][\0] , .rdata 영역에 있고 
	// test1[주소] << 8바이트 주소는 [H]의 주소가 들어가 있음
	const char* test1 = "Hello World"; // 데이터가 아무리 늘어나도 크기는 8바이트로
	// test1[0] = 'R'; // Error 발생


	// [H][e][l][l][o][][W][o][r][l][d][\0]
	// 각각 4바이트씩 해서 각각 복사를 해넣음 --> Hell --> o W --> rld\0 순으로
	// test2 = 주소
	char test2[] = "Hello World"; // 실질적인 크기가 데이터의 크기만큼 늘어나게됨
	test2[0] = 'R';

	cout << test2 << endl; // 실제 test2의 값이 바뀐 것을 확인할 수 있음

	// 포인터는 [주소를 담는 바구니]
	// 배열은 [닭장] 즉, 그 자체로 같은 데이터끼리 붙어있는 '바구니 모음'
	// - 다만 [배열 이름]은 '바구니 모음'의 [시작 주소]

	// 배열을 함수의 인자로 넘기게 되면?
	int a = 0;
	Test(a);
	cout << a << endl;

	// test2가 바뀜
	Test2(test2);
	cout << test2 << endl;

	return 0;
}