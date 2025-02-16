#include <iostream>
using namespace std;

// 오늘의 주제 : 다차원 배열

int main()
{
	int a[10] = { 1, 2, 3 };

	// [1] [1] [5] [2] [2] << 1층
	// [4] [2] [3] [4] [1] << 0층

	int first[5] = { 4, 2, 3, 4, 1 };
	int second[5] = { 1, 1, 5, 2, 2 };

	// 1)
	int apartment2D[2][5] = { { 4, 2, 3, 4, 1 }, { 1, 1, 5, 2, 2 } }; // 메로상으로는 1차원 배열이 나열되어 있는 것으로 보임
	for (int floor = 0; floor < 2; floor++) 
	{
		for (int room = 0; room < 5; room++)
		{
			/// apartment2D + (floor * 20)+ 4 * room을 한 주소
			int num = apartment2D[floor][room];
			cout << num << " ";
		}
		cout << endl;
	}

	// 2)
	int apartment1D[10] = { 4, 2, 3, 4, 1 , 1, 1, 5, 2, 2 };
	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			int index = (floor * 5) + room;
			/// apartment1D + (floor * 20)+ 4 * room을 한 주소
			int num = apartment1D[index];
			cout << num << " ";
		}
		cout << endl;
	}

	// 2차 배열은 언제 사용할까? 대표적으로 2D 로그라이크 맵
	int map[5][5] =
	{
		{1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1},
		{0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
	};

	// 지금은 1, 0 으로 보이지만 추후 아트를 씌우면 여기에 타일 모양을 넣을 수 있음
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			int info = map[y][x];
			cout << info;
		}
		cout << endl;
	}

	return 0;
}