#include <iostream>
using namespace std;


// 숫자를 지정 안하면 첫 값은 0부터 시작
// 그 다음 값들은 이전 값 +1
enum ENUM_SRP
{
	ENUM_SCISSORS,
	ENUM_ROCK,
	ENUM_PAPER
};

// #이 붙은 것 --> 전처리 지시문
// 빌드 단계 : 전처리 --> 컴파일 --> 링크
#define DEFINE_SCISSORS 1
#define DEFINE_TEST cout<<"Hello World"<< endl;

int main()
{
 DEFINE_TEST
}