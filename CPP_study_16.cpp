#include <iostream>
using namespace std;

// �Լ� ������

// �����ε� (�ߺ� ���� : �Լ� �̸��� ����)
// - �Ű����� ������ �ٸ��ų�
// - �Ű����� Ÿ���� �ٸ��ų� (������ �ٸ��� ����)

int Add(int a, int b)
{
	int result = a + b;
	return result;
}

float AddFloat(float a, float b)
{
	float result = a + b;
	return result;
}

// error�� �߻����� ����
// �Լ� �̸��� ������ input�� �ٸ��Ƿ� �ڵ尡 ������ ������ ������
float Add(float a, float b)
{
	float result = a + b;
	return result;
}

// error�� �߻���
// �Լ� �̸��� input�� �����Ͽ� �ڵ尡 �����ε����� �Ǵ���--> ��ȯ Ÿ���� �߿����� ����
float Add(int a, int b)
{
	int result = a + b;
	return result;
}

// �⺻ ���ڰ�
// guildId�� ��� �ʱ� ���� 0���� �����س��� ������ �Լ��� ȣ���Ҷ� ��� ������ ���� ����
// �ʱ� ���� 0���� �����ϱ� ���ؼ��� �� ������ �������� �����ؾ���.
// �߰��� ������ �Լ��� ȣ���Ҷ� ������ ������ ������ �߻���Ŵ
// �ʱ� ���� �ִ��� input���� ���� �������ָ� input ���� ���Ե�
void SetPlayerInfo(int hp, int mp, int attack, int guildId = 0)
{

}



int main()
{
	int result = Add(1.5f, 2.1f);
	cout << result << endl;

	SetPlayerInfo(100, 40, 10); // hp = 100, mp = 40, attack = 10, guildId = 0
	SetPlayerInfo(100, 40, 10, 1); // hp = 100, mp = 40, attack = 10, guildId = 1


	return 0;
}