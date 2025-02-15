#include <iostream>
using namespace std;

// ������ ���� : ���� ������

void SetNumber(int *a)
{
	*a = 1;
}

void SetMessage(const char* a) // ���� �ٲ��� ����
{
	a = "Bye";
}

void SetMessage2(const char** a) // ���� ������
{
	*a = "Bye";
}

void SetMessage3(const char*& a) // �̷��� ���°͵� msg �� ���� ������ �� ����
{
	a = "Wow";
}

int main()
{
	int a = 0;
	SetNumber(&a);
	cout << a << endl;

	const char* msg = "Hello";
	SetMessage(msg);
	cout << msg << endl; // Hello

	// �ּ�2 [ ] << 1 ����Ʈ
	// �ּ�1[ �ּ�2 ] << 8����Ʈ
	// pp[ �ּ�1 ] << 8����Ʈ
	const char** pp = &msg;
	//*pp = "Bye"; --> msg�� bye�� �����
	SetMessage2(pp); // --> msg�� bye�� �����
	cout << msg << endl;

	// const chart*�� �����ϱ� ���ؼ� ���� �����͸� ��������� 
	// ���� ���� �����ͷ� ���� ���� ���� �ʴ�

	// ���������� :���ı���� �����ϱ� -> �̵��Ҷ����� *�� �ϳ��� ���

	SetMessage3(msg);
	cout << msg << endl;

	return 0;
}