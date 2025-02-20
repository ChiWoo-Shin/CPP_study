#include <iostream>
#include <iomanip>
using namespace std;

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

void SetBoard()
{
	// 1 2 3 4 5
	//         6
	//         7
	//         8
	//         9
	// 위처럼 달팽이 모양으로 돌아가는 수식을 만들기
	int num = 0; // direction
	int y = 0;
	int x = 0;
	int cnt = 1;
	
	while (true)
	{
		switch (num)
		{
		case 0: // 오른쪽
			while (x < N && board[y][x] == 0)
			{
				board[y][x] = cnt;
				x++;
				cnt++;
			}
			y++;
			x--;
			break;
		case 1: // 아래로
			while (y < N && board[y][x] == 0)
			{
				board[y][x] = cnt;
				y++;
				cnt++;
			}
			x--;
			y--;
			break;
		case 2: // 왼쪽
			while (x >= 0 && board[y][x] == 0)
			{
				board[y][x] = cnt;
				x--;
				cnt++;
			}
			y--;
			x++;
			break;
		case 3:
			while (y >= 0 && board[y][x] == 0)
			{
				board[y][x] = cnt;
				y--;
				cnt++;
			}
			x++;
			y++;
			break;
		default:
			break;
		}
		num++;
		num %= 4;

		/*if (x != 0 && y != 0) {
			if (board[y-1][x] != 0 && board[y][x-1] != 0 && board[y+1][x] != 0 && board[y][x+1] != 0) {
				board[y][x] = cnt;
				break;
			}
		}*/
		if (cnt == N * N) {
			board[y][x] = cnt;
			break;
		}
	}

}

int main()
{
	cin >> N;

	SetBoard();
	PrintBoard();

	return 0;
}