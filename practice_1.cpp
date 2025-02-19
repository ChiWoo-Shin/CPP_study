#include <iostream>
using namespace std;

// ������ ���� : ���� ����

// ����1) ���ڿ� ���̸� ������ִ� �Լ�
int StrLen(const char* str)
{
	// str�̶�� ���ڿ��� ���̸� ��ȯ
	int cnt = 0;
	int idx = 0;

	while (true)
	{
		if (str[idx] == '\0') {
			return cnt;
		}
		cnt++;
		idx++;
	}
}

// ���� �� ���
//int StrLen(const char* str)
//{
//	// str�̶�� ���ڿ��� ���̸� ��ȯ
//	int cnt = 0;
//	
//	while (str[cnt] != '\0')
//		cnt++;
//	return cnt;
//}

// ���� 2) ���ڿ� ���� �Լ�
char* StrCpy(char* dest, char* src)
{

	// 2-1 �迭�� �̿��Ͽ� ������ Ǭ�� - �ּҽ������� �״�� �ΰ� idx�� �̵��ϸ� ���� ������
	int cnt = 0;

	while (src[cnt] != '\0')
	{
		dest[cnt] = src[cnt];
		cnt++;
	}
	dest[cnt] = '\0';

	return dest;

	// 2-2 �����͸� �̿��Ͽ� ������ ǰ - �ּҽ������� ��ĭ�� �̵��Ͽ� ���� ������
	char* ret = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return ret;
}


// ���� 3) ���ڿ� �����̴� �Լ�
char* StrCat(char* dest, char* src)
{
	// 3-1 �迭�� �ذ��� ���
	int idx = StrLen(dest);
	int idx2 = 0;

	while (src[idx2]) {
		dest[idx] = src[idx2];
		idx++;
		idx2++;
	}
	dest[idx] = '\0';

	return dest;

	// 3-2 �����ͷ� �ذ��� ���
	char* ret = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return ret;
}

// ���� 4) ���ڿ� �� �Լ�
int StrCmp(char* a, char* b)
{
	int idx = 0;
	
	while (a[idx] != '\0' || b[idx] != '\0')
	{
		if (int(a[idx]) > int(b[idx]))
			return 1;
		else if (int(a[idx]) < int(b[idx]))
			return -1;
		idx++;
	}
	return 0;
}

// ���� 5) ���ڿ��� ������ �Լ�
void ReverseStr(char* str)
{
	// ���� ���� ���
	int idx = 0;
	char temp[100];

	while (str[idx])
	{
		temp[idx] = str[idx];
		idx++;
	}

	temp[idx] = '\0';
	
	int idx2 = 0;
	
	for (int i = idx - 1; i >= 0; i--)
	{
		str[idx2] = temp[i];
		idx2++;
	}
	str[idx2] = '\0';

	// ���󿡼� ���� ���
	int len = StrLen(str);

	for (int i = 0; i < len / 2; i++)
	{
		int temp2 = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp2;
	}
}
#pragma warning(disable:4996)

int main()
{
	const int BUF_SIZE = 100;
	
	// ���� �迭�� 100�� ������ ����ϰ� �ִ� ������ 6��
	char a[BUF_SIZE] = "Hello";

	int len = sizeof(a);
	cout << len << endl;; // 100 --> Hello�� ũ�Ⱑ �ƴ� BUF_SIZE�� ǥ���ϰԵ�

	len = strlen(a); 
	cout << len << endl; // ���ڿ��� ũ���� 5�� return --> '\0' ����

	// ���� 1)
	len = StrLen(a);
	cout << len << endl;

	char b[BUF_SIZE];


	// strcpy(b, a); --> a�迭�� b�� ������ ���� {strcpy �� �������� �Լ��̱⶧���� 4996 ������ �߻��� �׷��� strcpy_s�� ����ϴ� ���� ��õ��}
	// �װ� �ƴ϶�� #pragma�� ���ؼ� warning�� disable ��Ű���
	// ���� 2)
	StrCpy(b, a);

	char c[BUF_SIZE] = "World";

	// strcat(a, c);
	// ���� 3)
	// StrCat(a, c);

	char d[BUF_SIZE] = "aa";
	
	if (a == d)
	{
		cout << "����" << endl;
	}
	else
	{
		cout << "�ٸ���" << endl;
	}
	// �� if���� ����� �ٸ��� --> �迭�� ���� ���ϴ°� �ƴ� �ּ��� ���۰��� ���ϱ� ������ �ٸ��ٰ� ����

	int value = strcmp(a, d); // ���� ���ٸ� 0, ���������� a�� d���� ������ -1, ������ 1
	cout << value << endl;

	// ���� 4)
	value = StrCmp(a, d);
	cout << value << endl;

	// ���� 5)
	char e[BUF_SIZE] = "Hello World";
	ReverseStr(e);
	cout << e << endl;

	return 0;
}