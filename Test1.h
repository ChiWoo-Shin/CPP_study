#pragma once
// #pragma once 없는 경우 #include "Test1.h" 가 여러번 반복되도 막지 않음 --> struct 같은게 여러번 불려오면 문제가 발생함
// A.h 에 있는 내용을 B.h에서도 호출을 하고 C.h에서 B와 A를 호출하면 중복 호출이 되게됨

// #pragam once는 최신 문법이고 구 버전으로 #ifndef를 사용할수있음
// #ifndef, #define, #endif 가 세트로 움직임
// #ifndef, #define, #endif 를 사용하면 구역별로 컨트롤이 가능함
// #ifndef _TEST1_H__
// #define _TEST1_H__

// 주의사항
// h헤더 파일은 최대한 간단하게 유지하는 것이 좋음

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};


void Test_1();
void Test_2();
void Test_3();

// #endif // !_TEST1_H__