#include <iostream>
using namespace std;

// 오늘의 주제 : 타입 변환 (포인터)

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

	char _dummy[4096] = {}; // 이런저런 정보들로 비대해진 정보라고 보여주기위한 부분
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
	// 연관성이 없는 클래스 사이의 포인터 변환 테스트
	{
		// Stack [ 주소 ] -> Heap [ _hp(4) ]
		Knight* knight = new Knight();

		// 암시적으로는 No
		// 명시적으로는 Ok

		// Stack [ 주소 ]
		// Item* item = (Item*)knight;
		// item->_itemType = 2;
		// item->_itemDbID = 1;

		delete knight; // type 변환이 잘못됐기 때문에 문제가 발생함
	}

	// 부모 -> 자식 변환 테스트
	{
		Item* item = new Item();

		// [  [Item]  ]
		// [  _damage  ]
		// Weapon* weapon = (Weapon*)item; // item == 무기 ? 생각했을때 포함이 안되면 안된다고 생각하면됨
		// 위와 동일하게 명시적으로는 동작하지만 정상동작이라 볼 수 없음
		// weapon->_damage = 10;
		delete item;
	}

	// 자식 -> 부모 변환 테스트
	{
		// [  [Item]  ]
		// [  _damage  ]
		Weapon* weapon = new Weapon();
		
		Item* item = weapon; // 위화감 없이 암시적으로도 변환이 가능함.

		delete weapon;
	}

	// 명시적으로 타입 변환할 때는 항상 조심해야 한다!
	// 암시적으로 될 때는 안전하다?
	// -> 평생 명시적으로 타입 변환(캐스팅)은 안하면 되는거 아닌가?

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
			Weapon* weapon = (Weapon*)item; // 자식과 부모로 자주 왔다갔다 할때는 명시적 변환이 필요하게됨
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
	}

	// ************************************* 매우 중요 *****************************************
	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;
		// 1. weapon과 armor를 직접 삭제
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
		// delete item만 쓰게 되면 item은 소멸되지만 상속된 wepon과 armor가 소멸되지 않음 -> 이부분은 앞에서 배웠던 virtual 함수와 관련이 있음

		// 2. after virtual
		delete item;

		
	}

	// [결론]
	// - 포인터 vs 일반 타입 : 차이를 이해하자
	// - 포인터 사이의 타입 변환(캐스팅)을 할때는 매우 조심해야한다
	// - 부모-자식 관계에서 부모 클래스의 소멸자에는 까먹지 말고 virtual을 붙이자!! (특히 최상위 부모에게는 꼬옥 붙여야한다)

	return 0;
}