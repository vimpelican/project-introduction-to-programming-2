#include <iostream>

class Calc {
private:
protected:
public:
	/*
	추상적인 계산기 클래스
	*/
};

class Calc_basic : public Calc {
private:
protected:
public:
	/*
	기본 기능(폰 계산기 켜면 바로 가능)
	1. 실수 사칙연산
	2. 퍼센트 연산
	3. 괄호 포함한 연산
	4. 현재 출력되고 있는 화면 지우기
	*/
};

class Calc_Eng : public Calc_basic {
private:
protected:
public:
	/*
	기본 공학용 기능(폰 계산기 기능 + 추가적인 기능들)
	1. 삼각함수, 쌍곡선함수, 역삼각함수의 기본 연산
	2. 지수, 로그, 제곱근 계산
	3. 자주 쓰이는 상수(e, pi 등) 바로 계산 식에 포함 가능
	*/
};

class Calc_Eng_Advanced : public Calc_Eng {
private:
protected:
public:
	/*
	고급 공학용 기능(기본 공학용 기능 + 공학용 계산기로만 가능한 기능들)
	*/
};
