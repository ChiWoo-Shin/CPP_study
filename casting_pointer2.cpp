#include <iostream>
using namespace std;

// ������ ���� : Ÿ�� ��ȯ (������)

class Knight 
{
public:
	int _hp = 0;
};

class Item
{
public:
	Item()
	{
		cout << "Item" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "Item(int itemType)" << endl;
	}

	Item(const Item& item)
	{
		cout << "Item(const Item&)" << endl;
	}
	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}


public:
	int _itemType = 0;
	int _itemDbID = 0;

	char _dummy[4096] = {}; // �̷����� ������� ������� ������� �����ֱ����� �κ�
};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2,
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
		_damage = rand() % 100;
	}

	~Weapon()
	{
		cout << "~Weapon()" << endl;
	}

public:
	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
	}

	~Armor()
	{
		cout << "~Armor()" << endl;
	}

public:
	int _defence = 0;
};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{

}

int main()
{
	// �������� ���� Ŭ���� ������ ������ ��ȯ �׽�Ʈ
	{
		// Stack [ �ּ� ] -> Heap [ _hp(4) ]
		Knight* knight = new Knight();

		// �Ͻ������δ� No
		// ��������δ� Ok

		// Stack [ �ּ� ]
		// Item* item = (Item*)knight;
		// item->_itemType = 2;
		// item->_itemDbID = 1;

		delete knight; // type ��ȯ�� �߸��Ʊ� ������ ������ �߻���
	}

	// �θ� -> �ڽ� ��ȯ �׽�Ʈ
	{
		Item* item = new Item();

		// [  [Item]  ]
		// [  _damage  ]
		// Weapon* weapon = (Weapon*)item; // item == ���� ? ���������� ������ �ȵǸ� �ȵȴٰ� �����ϸ��
		// ���� �����ϰ� ��������δ� ���������� �������̶� �� �� ����
		// weapon->_damage = 10;
		delete item;
	}

	// �ڽ� -> �θ� ��ȯ �׽�Ʈ
	{
		// [  [Item]  ]
		// [  _damage  ]
		Weapon* weapon = new Weapon();
		
		Item* item = weapon; // ��ȭ�� ���� �Ͻ������ε� ��ȯ�� ������.

		delete weapon;
	}

	// ��������� Ÿ�� ��ȯ�� ���� �׻� �����ؾ� �Ѵ�!
	// �Ͻ������� �� ���� �����ϴ�?
	// -> ��� ��������� Ÿ�� ��ȯ(ĳ����)�� ���ϸ� �Ǵ°� �ƴѰ�?

	Item* inventory[20] = {};
	srand((unsigned int)time(nullptr));
	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2; // 0~1
		switch (randValue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;

		case 1:
			inventory[i] = new Armor();
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item; // �ڽİ� �θ�� ���� �Դٰ��� �Ҷ��� ����� ��ȯ�� �ʿ��ϰԵ�
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
	}

	// ************************************* �ſ� �߿� *****************************************
	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;
		// 1. weapon�� armor�� ���� ����
		/*if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			delete weapon;
		}
		else
		{
			Armor* armor = (Armor*)item;
			delete armor;
		}*/
		
		// delete item;
		// delete item�� ���� �Ǹ� item�� �Ҹ������ ��ӵ� wepon�� armor�� �Ҹ���� ���� -> �̺κ��� �տ��� ����� virtual �Լ��� ������ ����

		// 2. after virtual
		delete item;

		
	}

	// [���]
	// - ������ vs �Ϲ� Ÿ�� : ���̸� ��������
	// - ������ ������ Ÿ�� ��ȯ(ĳ����)�� �Ҷ��� �ſ� �����ؾ��Ѵ�
	// - �θ�-�ڽ� ���迡�� �θ� Ŭ������ �Ҹ��ڿ��� ����� ���� virtual�� ������!! (Ư�� �ֻ��� �θ𿡰Դ� ���� �ٿ����Ѵ�)

	return 0;
}