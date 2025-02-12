#include <iostream>
using namespace std;

// 참조 전달

#define OUT

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void PrintInfoByRef(StatInfo& info);
void ChangeInfo(OUT StatInfo& info);
void PrintInfoByPtr(StatInfo* info);
void CreateMonster(StatInfo* info);

int main()
{
	StatInfo info;

	// 포인터 vs 참조 세기의 대결
	// 성능 : 똑같음 !
	// 편의성 : 참조 승!

	// 1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점만은 아니다.
	// 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있음
	// 참조는 자연스럽게 모르고 지나칠 수 있음!
	// ex) 마음대로 고친다면?
	// const를 사용해서 이런 마음대로 고치는 부분을 개선 가능

	// 참고로 포인터도 const를 사용 가능
	// *를 기준으로 앞에 붙이느냐 뒤에 붙이느냐에 따라 의미가 바뀌게됨

	// 2) 초기화 여부
	// 참조 타입은 바구니의 2번째 이름(별칭?)
	// -> 참조하는 대상이 없으면 안됨
	// 반면 포인터는 그냥 어떤~ 주소라는 의미
	// -> 대상이 실존하지 않을 수도 있음 --> 이로인해 포인터에서 가능하던 산술연산 같은것이 불가능함
	// 포인터에서 '없다'는 의미로? nullptr
	// 참조 타입은 이런 nullptr이 존재하지 않음 


	StatInfo* pointer = nullptr; 
	pointer = &info;
	PrintInfoByPtr(&info); // 주소를 넘기기 때문에 포인터를 넘기는 것이라고 유추할 수 있음

	StatInfo& reference = info;
	PrintInfoByRef(info); // 원본을 변경할 수 있는지 아닌지 유추하기 어려움

	ChangeInfo(OUT info); // 일반적 ref를 사용하면서 값이 변경이 가능한경우 OUT을 표기해줌 (가독성을 위해)

	// Bonus) 포인터로 사용하던걸 참조로 넘겨주려면?
	// PrintInfoByRef(pointer); // error 발생 ref를 사용하는 곳에 pointer를 넣어서
	PrintInfoByRef(*pointer); // 앞에 *를 넣어서 값으로 변환해주면됨

	// Bonus) 참조로 사용하던걸 포인터로 넘겨주려면?
	// PrintInfoByPtr(reference); // error 발생 주소를 넣어야하는 곳에 refer를 넣어서
	PrintInfoByPtr(&reference); // 앞에 &를 넣어서 주소를 넘겨주면됨

	return 0;
}

void PrintInfoByRef(const StatInfo& info)
{
	cout << "-------PrintInfoByRef-------" << endl;
	cout << "HP : "<< info.hp << endl;
	cout << "ATT : "<< info.attack << endl;
	cout << "DEF : "<< info.defence << endl;
	cout << "-------------------" << endl;

	// 신입이 왔다
	// info.hp = 10000; // Error가 발생하게됨 const로 인하여
}


void ChangeInfo(OUT StatInfo& info) // OUT은 가독성 차원에서 사용하는것
{
	info.hp = 1000;
}

StatInfo globalInfo;
void PrintInfoByPtr(StatInfo* info)
{
	if (info == nullptr) // if(!info) --> nullptr를 확인할 수 있는 방법
		return ;
	cout << "-------PrintInfoByPtr-------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "-------------------" << endl;
	
	// 1) 편의성 관련 부분임
	// const를 별 뒤에 붙인다면?
	// StatInfo* const info
	// info = &globalInfo; // info 라는 바구니의 내용물(주소)를 바꿀수 없음 --> 주소값이 고정이다

	// 별 이전에 붙인다면?
	// const StatInfo* info || StatInfo const* info --> 전자를 일반적으로 많이 사용함
	// info->hp = 10000; // info가 '가리키고 있는' 바구니의 내용물을 바꿀수 없음 --> '원격' 바구니의 내용물을 바꿀수 없음

	// 둘 다 막아줘도 됨
	// const StatInfo* const info
}

void CreateMonster(StatInfo* info)
{
	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
}