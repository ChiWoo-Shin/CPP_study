#include <iostream>
using namespace std;
#include <iomanip>

// 오늘의 주제 : 연습 문제

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

int main()
{
	cin >> N;

	PrintBoard();

	return 0;
}