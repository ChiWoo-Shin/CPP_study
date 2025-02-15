#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ������ ���� : �ζ� ��ȣ ������

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
};

void Sort(int numbers[], int count)
{
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - 1 - i; j++) {
			if (numbers[j] > numbers[j + 1]) {
				Swap(numbers[j], numbers[j + 1]);
			}
				
		}
	}
};

void ChooseLotto(int numbers[])
{
	srand((unsigned)time(0)); // ���� �õ� ����

	// ToDo : �������� 1~45 ������ ���� 6���� ����ּ���! (��, �ߺ��� �������)
	int temp = 0;

	int number_max_size = 6;
	int number_size = 0;
	while (number_size <= number_max_size) {
		temp = rand() % 45;

		if (number_size == 0 && 0 < temp) {
			numbers[number_size] = temp;
			number_size++;
		}
		else if ( 0 < temp) {
			bool flag = false;
			for (int i = 0; i < number_size; i++) {
				if (temp == numbers[i]) {
					flag = true;
					break;
				}
			}
			if (flag == false) {
				numbers[number_size] = temp;
				number_size++;
			}
		}
	}

	Sort(numbers, 6);
}

int main()
{
	// 1) Swap �Լ� �����
	int a = 1;
	int b = 2;
	Swap(a, b);
	// a = 2, b = 1

	// 2) ���� �Լ� ����� (���� ���ڰ� ���� ������ ����)
	int numbers[6] = { 1, 42, 3, 15, 5, 6 };
	Sort(numbers, sizeof(numbers) / sizeof(int)); // sizeof(nubers)/ sizeof(int) = 6*4 / 6


	// 3) �ζ� ��ȣ ������
	ChooseLotto(numbers);
	for (int i = 0; i < 6; i++) {
		cout << numbers[i] << endl;
	}

	return 0;
}