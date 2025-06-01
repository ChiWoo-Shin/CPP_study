#include <iostream>
using namespace std;
#include "Game.h"

// 오늘의 주제 : TextRPG #4



int main()
{
	srand((unsigned int)time(nullptr));
	// 여기는 실제 코드가 running 하는 부분이기 때문에 include가 필요
	Game game;
	game.Init();

	while (true)
	{
		game.Update();
	}

	return 0;
}