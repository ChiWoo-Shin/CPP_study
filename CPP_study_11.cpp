#include <iostream>
using namespace std;

int main()
{
	//  ����� 1)
	// �������� � ������ �Է��ϸ�
	// N*N���� ���� ������� ���ھ��.

	int starNum;
	cin >> starNum;

	for (int i = 0; i < starNum; i++) {
		for (int j = 0; j < starNum; j++) {
			cout << "*";
		}
		cout << endl;
		
	}
	cout << endl;
	//  ����� 2)
	// 1������ �����ؼ� ���������� �ٸ��� �����ϰ� ���ּ���.
	for (int i = 0; i < starNum; i++) {
		for (int j = 0; j < i+1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
	//  ����� 3)
	// N�� ���� �����ؼ� �ٸ��� 1���� �پ��� ���·� ���ּ���
	for (int i = 0; i < starNum; i++) {
		for (int j = starNum; i < j; j--) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	// ������
	// 2�ܺ��� 9�ܱ��� ������ּ���
	for (int i = 2; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cout << i << "*" << j << "=" << i * j << endl;
		}
		cout << endl;
	}
}