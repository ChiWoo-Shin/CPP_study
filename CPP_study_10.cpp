#include <iostream>
using namespace std;

// 반복문

int main()
{
	//while - 동안에
	// if - else 유용
	// 하지만 특정 조건까지 계속 반복해야하는 상황
	// ex) 게임을 끌때까지 계속 게임을 실행
	// ex) 목적지에 도달할때까지 -- 계속 이동

	int count = 0;

	/*while (count < 5)
	{
		cout << "Hello World" << endl;
		count++;
	}*/

	/*do
	{
		cout << "Hello World" << endl;
		count++;
	} while (false);*/

	// 초기화, 조건식, 제어식
	for (count = 0; count<5; count++)
	{
		cout << "Hello World" << endl;
	}

	// break;

	int round = 1;
	int hp = 100;
	int damage = 30;

	while (true)
	{
		hp -= damage;
		if (hp < 0)
			hp = 0; // 음수를 체력 0으로 보정

		// 시스템 메시지
		cout << "Round" << round << "몬스터 체력 " << hp << endl;

		if (hp == 0) {
			cout << "몬스터 처치!" << endl;
			break;
		}

		if (round == 5) {
			cout << "제한 라운드 종료" << endl;
			break;
		}
		round++;
	}

	// continue;
	// 1-10사이의 홀수만 뽑기
	for (count = 0; count <= 10; count++)
	{
		bool isEven = ((count % 2) == 0);
		if (isEven)
			continue;

		cout << count << endl;
	}
}