#pragma once
// #pragma once ���� ��� #include "Test1.h" �� ������ �ݺ��ǵ� ���� ���� --> struct ������ ������ �ҷ����� ������ �߻���
// A.h �� �ִ� ������ B.h������ ȣ���� �ϰ� C.h���� B�� A�� ȣ���ϸ� �ߺ� ȣ���� �ǰԵ�

// #pragam once�� �ֽ� �����̰� �� �������� #ifndef�� ����Ҽ�����
// #ifndef, #define, #endif �� ��Ʈ�� ������
// #ifndef, #define, #endif �� ����ϸ� �������� ��Ʈ���� ������
// #ifndef _TEST1_H__
// #define _TEST1_H__

// ���ǻ���
// h��� ������ �ִ��� �����ϰ� �����ϴ� ���� ����

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