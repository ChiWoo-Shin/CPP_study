#include <iostream>
using namespace std;
#include "Game.h"

// ������ ���� : TextRPG #4



int main()
{
	srand((unsigned int)time(nullptr));
	// ����� ���� �ڵ尡 running �ϴ� �κ��̱� ������ include�� �ʿ�
	Game game;
	game.Init();

	while (true)
	{
		game.Update();
	}

	return 0;
}