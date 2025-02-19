#include <iostream>
using namespace std;

// 오늘의 주제 : 연습 문제

// 문제1) 문자열 길이를 출력해주는 함수
int StrLen(const char* str)
{
	// str이라는 문자열의 길이를 반환
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

// 영상 속 답안
//int StrLen(const char* str)
//{
//	// str이라는 문자열의 길이를 반환
//	int cnt = 0;
//	
//	while (str[cnt] != '\0')
//		cnt++;
//	return cnt;
//}

// 문제 2) 문자열 복사 함수
char* StrCpy(char* dest, char* src)
{

	// 2-1 배열을 이용하여 문제를 푼다 - 주소시작점은 그대로 두고 idx를 이동하며 값을 복사합
	int cnt = 0;

	while (src[cnt] != '\0')
	{
		dest[cnt] = src[cnt];
		cnt++;
	}
	dest[cnt] = '\0';

	return dest;

	// 2-2 포인터를 이용하여 문제를 품 - 주소시작점을 한칸씩 이동하여 값을 복사함
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


// 문제 3) 문자열 덧붙이는 함수
char* StrCat(char* dest, char* src)
{
	// 3-1 배열로 해결한 방법
	int idx = StrLen(dest);
	int idx2 = 0;

	while (src[idx2]) {
		dest[idx] = src[idx2];
		idx++;
		idx2++;
	}
	dest[idx] = '\0';

	return dest;

	// 3-2 포인터로 해결한 방법
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

// 문제 4) 문자열 비교 함수
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

// 문제 5) 문자열을 뒤집는 함수
void ReverseStr(char* str)
{
	// 내가 만든 답안
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

	// 영상에서 나온 답안
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
	
	// 실제 배열은 100개 이지만 사용하고 있는 공간은 6개
	char a[BUF_SIZE] = "Hello";

	int len = sizeof(a);
	cout << len << endl;; // 100 --> Hello의 크기가 아닌 BUF_SIZE를 표시하게됨

	len = strlen(a); 
	cout << len << endl; // 문자열의 크기인 5를 return --> '\0' 제외

	// 문제 1)
	len = StrLen(a);
	cout << len << endl;

	char b[BUF_SIZE];


	// strcpy(b, a); --> a배열을 b에 복사해 넣음 {strcpy 는 구버전의 함수이기때문에 4996 에러가 발생함 그래서 strcpy_s를 사용하는 것을 추천함}
	// 그게 아니라면 #pragma를 통해서 warning을 disable 시키면됨
	// 문제 2)
	StrCpy(b, a);

	char c[BUF_SIZE] = "World";

	// strcat(a, c);
	// 문제 3)
	// StrCat(a, c);

	char d[BUF_SIZE] = "aa";
	
	if (a == d)
	{
		cout << "같다" << endl;
	}
	else
	{
		cout << "다르다" << endl;
	}
	// 위 if문의 결과는 다르다 --> 배열의 값을 비교하는게 아닌 주소의 시작값을 비교하기 때문에 다르다가 나옴

	int value = strcmp(a, d); // 둘이 같다면 0, 사전순서로 a가 d보다 빠르면 -1, 느리면 1
	cout << value << endl;

	// 문제 4)
	value = StrCmp(a, d);
	cout << value << endl;

	// 문제 5)
	char e[BUF_SIZE] = "Hello World";
	ReverseStr(e);
	cout << e << endl;

	return 0;
}