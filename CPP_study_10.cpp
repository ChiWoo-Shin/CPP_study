#include <iostream>
using namespace std;

// �ݺ���

int main()
{
	//while - ���ȿ�
	// if - else ����
	// ������ Ư�� ���Ǳ��� ��� �ݺ��ؾ��ϴ� ��Ȳ
	// ex) ������ �������� ��� ������ ����
	// ex) �������� �����Ҷ����� -- ��� �̵�

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

	// �ʱ�ȭ, ���ǽ�, �����
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
			hp = 0; // ������ ü�� 0���� ����

		// �ý��� �޽���
		cout << "Round" << round << "���� ü�� " << hp << endl;

		if (hp == 0) {
			cout << "���� óġ!" << endl;
			break;
		}

		if (round == 5) {
			cout << "���� ���� ����" << endl;
			break;
		}
		round++;
	}

	// continue;
	// 1-10������ Ȧ���� �̱�
	for (count = 0; count <= 10; count++)
	{
		bool isEven = ((count % 2) == 0);
		if (isEven)
			continue;

		cout << count << endl;
	}
}