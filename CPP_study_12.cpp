#include <iostream>
#include <string>
using namespace std;

string result(int x);

int main() {
	// 가위, 바위, 보 게임을 만들어보자
	srand(time(0)); // 시드 설정
	
	/*const int sic = 1;
	const int rock = 2;
	const int paper = 3;

	while (true) {
		cout << "가위(1) 바위(2) 보(3) 중 하나를 입력해주세요." << endl;
		cout << "0 를 입력하면 게임이 종료됩니다." << endl;
		
		int input;
		cin >> input;
		int comValue = 1 + (rand() % 3);

		if (input == 0)
			break;

		switch (input)
		{
		case sic:
			switch (comValue)
			{
			case sic:
				cout << "비겼습니다. "<<"나 : " << input << " Com : " <<comValue << endl;
				break;
			case rock:
				cout << "졌습니다." << "나 : " << input << " Com : " << comValue << endl;
				break;
			case paper:
				cout << "이겼습니다." << "나 : " << input << " Com : " << comValue << endl;
			default:
				break;
			}
			break;
		case rock:
			switch (comValue)
			{
			case sic:
				cout << "이겼습니다." << "나 : " << input << " Com : " << comValue << endl;
				break;
			case rock:
				cout << "비겼습니다." << "나 : " << input << " Com : " << comValue << endl;
				break;
			case paper:
				cout << "졌습니다." << "나 : " << input << " Com : " << comValue << endl;
			default:
				break;
			}
			break;
		case paper:
			switch (comValue)
			{
			case sic:
				cout << "졌습니다." << "나 : " << input << " Com : " << comValue << endl;
				break;
			case rock:
				cout << "이겼습니다." << "나 : " << input << " Com : " << comValue << endl;
				break;
			case paper:
				cout << "비겼습니다." << "나 : " << input << " Com : " << comValue << endl;
			default:
				break;
			}
			break;
			
		default:
			break;
		}
		cout << endl;
	}*/

	// 1번 가위바위보
	const int sic = 1;
	const int rock = 2;
	const int paper = 3;
	// 2번 승률 추가
	int win = 0, lose = 0;
	while (true) {
		cout << "가위(1) 바위(2) 보(3) 중 하나를 입력해주세요." << endl;
		cout << "1, 2, 3 이외의 값을 입력하면 게임이 종료됩니다." << endl;

		int input;
		cin >> input;
		
\
		int comValue = 1 + (rand() % 3);

		if (input !=1 && input != 2 && input != 3)
			break;

		if ((input == paper && comValue == sic) || (comValue == paper && input == sic)) {
			if (input == 1) {
				cout << "이겼습니다." << "나 : " << result(input) << " Com : " << result(comValue) << endl;
				win++;
			}
			else {
				cout << "졌습니다." << "나 : " << result(input) << " Com : " << result(comValue) << endl;
				lose++;
			}
		}
		else if (input == comValue) {
			cout << "비겼습니다." << "나 : " << result(input) << " Com : " << result(comValue) << endl;
		}
		else if (input > comValue) {
			cout << "이겼습니다." << "나 : " << result(input) << " Com : " << result(comValue) << endl;
			win++;
		}
		else {
			cout << "졌습니다." << "나 : " << result(input) << " Com : " << result(comValue) << endl;
			lose++;
		}
		cout << endl;

		cout << "현재 승률 : " << win * 100 / (win + lose) << "%" << "전체 게임 횟수(무승부는 제외) : "<< win+lose << endl;
	}
}

string result(int x) {
	if (x == 1)
		return "Sic";
	else if (x == 2)
		return "Rock";
	else
		return "Paper";
}