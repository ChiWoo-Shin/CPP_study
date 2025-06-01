#pragma once


// 전방 선언
class Player;
class Field;

// is - a
// has - a


class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:

	// Player _player; // 이렇게 하면 Player가 있어야만 게임이 성립하는 것 - 멤버 변수 형태로 지니고 있을때,
	// 위처럼 들고 있으면 Knight 등이 더 큰 크기를 가지고 있기 때문에 데이터가 짤려나갈 확률이 높음

	// [ 4~8 ] --->>> [       ]
	Player* _player;
	// 이렇게 선언하면 player를 include 하지 않아도 문제가 생기지 않음
	// 전방선언을 통해 추후에 player가 등장하게 될 것이라는 것만 지정해주면 됨.
	Field* _field;
};

