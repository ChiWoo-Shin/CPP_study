#include <iostream>
using namespace std;

// ������ ���� : ������ ������

// 1) ������ vs �迭 2ź
// 2) ���ǻ���

int& TestRef()
{
	int a = 1;
	return a;
}

int* TestPointer()
{
	int a = 1;
	return &a;
}

void TestWrong(int* ptr)
{
	int a[100] = {};
	a[99] = 0xAAAAAAAA;
	*ptr = 0x12341234;
}

int main()
{
	// �ּҸ� ��� �ٱ���
	// ������ ��~ �ָ� ��򰡿� 
	// p�� ���� �װ����� �����ϴ� ��Ż
	int* p;

	// ���� ������
	// ����ó�� �������� ���� (��û ���� �Ŵ�)
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	// ���� ������� [�迭 = ������] ��� ���� �ϴ� ������ ����

	// - [�迭�� �̸�]�� �迭�� ���� �ּҰ��� ����Ű�� TYPE* �����ͷ� ��ȯ ����!

	p = arr;

	// -[Type�� 1���� �迭]�� [type*�� ������]�� ������ ȣȯ�� �ȴ�
	cout << p[0] << endl;
	cout << arr[0] << endl;
	cout << p[5] << endl;
	cout << arr[5] << endl;
	cout << *p << endl;
	cout << *arr << endl;
	cout << *(p + 3) << endl;
	cout << *(arr + 3) << endl;

	// [1][2][3][4] - �˾Ƶθ� ���� ����
	int arr2[2][2] = { {1, 2}, { 3, 4} };

	// �ּ�2[] << 4����Ʈ
	// �ּ�1[�ּ�2]
	// pp [�ּ�1]
	int** pp = (int**)arr2;

	// type name [����]

	// [1][2] [3][4]
	// [�ּ�]
	int(*p2)[2] = arr2;

	cout << (*p2)[0] << endl;
	cout << (*p2)[1] << endl;
	cout << (*(p2 + 1))[0] << endl;
	cout << (*(p2 + 1))[1] << endl;
	cout << p2[0][0] << endl;
	cout << p2[0][1] << endl;
	cout << p2[1][0] << endl;
	cout << p2[1][1] << endl;

	
	int* pointer = TestPointer(); // ���������� �޸𸮸� ����ϰ� �ִµ� ������ �߻����� ����

	TestWrong(pointer);

	*pointer = 123; // ������ �ش� �޸𸮸� �ǵ帮�� �־ ������ ������ ����

	return 0;
}