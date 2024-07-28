#include <iostream>
#include <string>
using namespace std;

string result(int x);

int main() {
	// ����, ����, �� ������ ������
	srand(time(0)); // �õ� ����
	
	/*const int sic = 1;
	const int rock = 2;
	const int paper = 3;

	while (true) {
		cout << "����(1) ����(2) ��(3) �� �ϳ��� �Է����ּ���." << endl;
		cout << "0 �� �Է��ϸ� ������ ����˴ϴ�." << endl;
		
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
				cout << "�����ϴ�. "<<"�� : " << input << " Com : " <<comValue << endl;
				break;
			case rock:
				cout << "�����ϴ�." << "�� : " << input << " Com : " << comValue << endl;
				break;
			case paper:
				cout << "�̰���ϴ�." << "�� : " << input << " Com : " << comValue << endl;
			default:
				break;
			}
			break;
		case rock:
			switch (comValue)
			{
			case sic:
				cout << "�̰���ϴ�." << "�� : " << input << " Com : " << comValue << endl;
				break;
			case rock:
				cout << "�����ϴ�." << "�� : " << input << " Com : " << comValue << endl;
				break;
			case paper:
				cout << "�����ϴ�." << "�� : " << input << " Com : " << comValue << endl;
			default:
				break;
			}
			break;
		case paper:
			switch (comValue)
			{
			case sic:
				cout << "�����ϴ�." << "�� : " << input << " Com : " << comValue << endl;
				break;
			case rock:
				cout << "�̰���ϴ�." << "�� : " << input << " Com : " << comValue << endl;
				break;
			case paper:
				cout << "�����ϴ�." << "�� : " << input << " Com : " << comValue << endl;
			default:
				break;
			}
			break;
			
		default:
			break;
		}
		cout << endl;
	}*/

	// 1�� ����������
	const int sic = 1;
	const int rock = 2;
	const int paper = 3;
	// 2�� �·� �߰�
	int win = 0, lose = 0;
	while (true) {
		cout << "����(1) ����(2) ��(3) �� �ϳ��� �Է����ּ���." << endl;
		cout << "1, 2, 3 �̿��� ���� �Է��ϸ� ������ ����˴ϴ�." << endl;

		int input;
		cin >> input;
		
\
		int comValue = 1 + (rand() % 3);

		if (input !=1 && input != 2 && input != 3)
			break;

		if ((input == paper && comValue == sic) || (comValue == paper && input == sic)) {
			if (input == 1) {
				cout << "�̰���ϴ�." << "�� : " << result(input) << " Com : " << result(comValue) << endl;
				win++;
			}
			else {
				cout << "�����ϴ�." << "�� : " << result(input) << " Com : " << result(comValue) << endl;
				lose++;
			}
		}
		else if (input == comValue) {
			cout << "�����ϴ�." << "�� : " << result(input) << " Com : " << result(comValue) << endl;
		}
		else if (input > comValue) {
			cout << "�̰���ϴ�." << "�� : " << result(input) << " Com : " << result(comValue) << endl;
			win++;
		}
		else {
			cout << "�����ϴ�." << "�� : " << result(input) << " Com : " << result(comValue) << endl;
			lose++;
		}
		cout << endl;

		cout << "���� �·� : " << win * 100 / (win + lose) << "%" << "��ü ���� Ƚ��(���ºδ� ����) : "<< win+lose << endl;
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