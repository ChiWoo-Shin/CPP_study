#include <iostream>
using namespace std;

int main()
{
	//  별찍기 1)
	// 유저들이 어떤 정수를 입력하면
	// N*N개의 별을 찍었으면 좋겠어요.

	int starNum;
	cin >> starNum;

	for (int i = 0; i < starNum; i++) {
		for (int j = 0; j < starNum; j++) {
			cout << "*";
		}
		cout << endl;
		
	}
	cout << endl;
	//  별찍기 2)
	// 1개부터 시작해서 순차적으로 줄마다 증가하게 해주세요.
	for (int i = 0; i < starNum; i++) {
		for (int j = 0; j < i+1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
	//  별찍기 3)
	// N개 부터 시작해서 줄마다 1개씩 줄어드는 형태로 해주세요
	for (int i = 0; i < starNum; i++) {
		for (int j = starNum; i < j; j--) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	// 구구단
	// 2단부터 9단까지 출력해주세요
	for (int i = 2; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cout << i << "*" << j << "=" << i * j << endl;
		}
		cout << endl;
	}
}