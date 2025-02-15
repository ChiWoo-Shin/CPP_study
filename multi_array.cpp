#include <iostream>
using namespace std;

// 오늘의 주제 : 다차원 배열

int main()
{
	int a[10] = { 1,2,3 };

	// [1] [1] [5] [2] [2] << 1층
	// [4] [2] [3] [4] [1] << 0층

	int first[5] = { 4, 2, 3, 4, 1 };
	int second[5] = { 1, 1, 5, 2, 2 };


	return 0;
}