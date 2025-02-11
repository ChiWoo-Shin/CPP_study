#include <iostream>
using namespace std;

// 오늘의 주제 포인터 실습

struct StatInfo
{
	int hp; // +0
	int attack; // +4
	int defence; // +8
};

void EnterLobby();

StatInfo CreatePlayer(); // 포인터를 사용하지 않는 방법
void CreateMonster(StatInfo* info);  // 포인터를 사용한 방법
// 플레이어 승리시 True, 패배시 False
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
	EnterLobby();


	return 0;
}

void EnterLobby()
{
	cout << "로비에 입장했습니다." << endl;

	StatInfo player;
	player = CreatePlayer(); // 포인터를 사용X
	// 순서는 CreatPlayer에 가서 ret를 다시 생성후 거기의 값을 수정함
	// 이후 return 될때 temp 주소로 복사를 먼저 한후 player에 복사해 넣는 순서로 되어있음
	// 즉 중간 저장소를 사용하는 형태 (내부적으로 지역변수를 만들어 사용)

	StatInfo monster;

	CreateMonster(&monster); // 포인터를 사용
	// Monster 주소에 직접 가서 값을 변경함
	// 즉 중간 과정이 없기 때문에 더 효율이 좋음

	bool victory = StartBattle(&player, &monster);

	if (victory)
		cout << "승리" << endl;
	else
		cout << "패배" << endl;

	// 번외편 1)
	// 구조체끼리 복사할 때 무슨일이 벌어질까?
	// 구조체 내부의 변수를 하나씩 복사하는 과정으로 이뤄짐.
	// 코드가 한 줄일지라도 꼭 빠르다고 할 수 없다는 것을 알려주는 과정.
	player = monster;

}

StatInfo CreatePlayer() 
{
	StatInfo ret;

	cout << "플레이어 생성" << endl;

	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << endl;

	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
		int damage = player->attack - monster->attack;
		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		cout << "몬스터 hp : " << monster->hp << endl;

		if (monster->hp == 0)
			return true;

		damage = monster->attack - player->defence;
		if (damage < 0)
			damage = 0;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		cout << "플레이어 hp : " << player->hp << endl;

		if (player->hp == 0)
			return false;
	}
}