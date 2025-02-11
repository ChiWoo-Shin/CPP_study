#include <iostream>
using namespace std;

// ������ ���� ������ �ǽ�

struct StatInfo
{
	int hp; // +0
	int attack; // +4
	int defence; // +8
};

void EnterLobby();

StatInfo CreatePlayer(); // �����͸� ������� �ʴ� ���
void CreateMonster(StatInfo* info);  // �����͸� ����� ���
// �÷��̾� �¸��� True, �й�� False
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
	EnterLobby();


	return 0;
}

void EnterLobby()
{
	cout << "�κ� �����߽��ϴ�." << endl;

	StatInfo player;
	player = CreatePlayer(); // �����͸� ���X
	// ������ CreatPlayer�� ���� ret�� �ٽ� ������ �ű��� ���� ������
	// ���� return �ɶ� temp �ּҷ� ���縦 ���� ���� player�� ������ �ִ� ������ �Ǿ�����
	// �� �߰� ����Ҹ� ����ϴ� ���� (���������� ���������� ����� ���)

	StatInfo monster;

	CreateMonster(&monster); // �����͸� ���
	// Monster �ּҿ� ���� ���� ���� ������
	// �� �߰� ������ ���� ������ �� ȿ���� ����

	bool victory = StartBattle(&player, &monster);

	if (victory)
		cout << "�¸�" << endl;
	else
		cout << "�й�" << endl;

	// ������ 1)
	// ����ü���� ������ �� �������� ��������?
	// ����ü ������ ������ �ϳ��� �����ϴ� �������� �̷���.
	// �ڵ尡 �� �������� �� �����ٰ� �� �� ���ٴ� ���� �˷��ִ� ����.
	player = monster;

}

StatInfo CreatePlayer() 
{
	StatInfo ret;

	cout << "�÷��̾� ����" << endl;

	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "���� ����" << endl;

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

		cout << "���� hp : " << monster->hp << endl;

		if (monster->hp == 0)
			return true;

		damage = monster->attack - player->defence;
		if (damage < 0)
			damage = 0;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		cout << "�÷��̾� hp : " << player->hp << endl;

		if (player->hp == 0)
			return false;
	}
}