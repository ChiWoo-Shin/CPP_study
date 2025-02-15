#include <iostream>
using namespace std;

// ������ ���� : ������ vs �迭

void Test(int a)
{
	a++;
}

// �迭�� �Լ� ���ڷ� �ѱ��, �����Ϸ��� �˾Ƽ� �����ͷ� ġȯ (char[] -> char*)
// �迭�� ��ü �ּҸ� �ѱ�� �ƴ�, ���� �ּҸ� �ѱ� ����
void Test2(char a[])
{
	a[0] = 'X';
}

int main()
{
	cout << "Hello World" << endl;
	char msg[] = { 'H', 'e', 'l', 'l', 'o' , '\0' }; // \0 -> Null
	cout << msg << endl;

	// [H][e][l][l][o][][W][o][r][l][d][\0] , .rdata ������ �ְ� 
	// test1[�ּ�] << 8����Ʈ �ּҴ� [H]�� �ּҰ� �� ����
	const char* test1 = "Hello World"; // �����Ͱ� �ƹ��� �þ�� ũ��� 8����Ʈ��
	// test1[0] = 'R'; // Error �߻�


	// [H][e][l][l][o][][W][o][r][l][d][\0]
	// ���� 4����Ʈ�� �ؼ� ���� ���縦 �س��� --> Hell --> o W --> rld\0 ������
	// test2 = �ּ�
	char test2[] = "Hello World"; // �������� ũ�Ⱑ �������� ũ�⸸ŭ �þ�Ե�
	test2[0] = 'R';

	cout << test2 << endl; // ���� test2�� ���� �ٲ� ���� Ȯ���� �� ����

	// �����ʹ� [�ּҸ� ��� �ٱ���]
	// �迭�� [����] ��, �� ��ü�� ���� �����ͳ��� �پ��ִ� '�ٱ��� ����'
	// - �ٸ� [�迭 �̸�]�� '�ٱ��� ����'�� [���� �ּ�]

	// �迭�� �Լ��� ���ڷ� �ѱ�� �Ǹ�?
	int a = 0;
	Test(a);
	cout << a << endl;

	// test2�� �ٲ�
	Test2(test2);
	cout << test2 << endl;

	return 0;
}