#include <stdio.h>
#include "MyHeader.h"

#define MYADD(a,b) (a+b) // 매크로 함수 = 타입을 결정하지 않고 실행
//#define MYMUL(a,b) (a*b)
#define MYMUL(a,b) ((a)*(b))
#define MYMAKESTR(a) #a // # : 문자열로 만들어줌
#define MYMAKEPSTR(a,b) a##b // ## : 한덩어리로 만들어줌
//#define AAA
int myadd(int a, int b) { return a + b; } //  함수

#ifdef AAA
#define MyMESSAGE	"I am a Boy"
#else 
#define MyMESSAGE	"I am a Girl"
#endif // AAA


int main()
{
#ifndef AAA
	puts("1 : "__FILE__);
	printf("2 : %d\n" , __LINE__);
	puts("3 : "__DATE__);
	puts("4 : "__TIME__);
	puts(MyMESSAGE);
	int Data = 10;
	printf("%d \n", Data);
	printf("%s \n", MYMAKESTR(Data));
	printf("%s \n", MYMAKESTR(11));
	printf("%s \n", MYMAKESTR(3.14));
	printf("%s \n", MYMAKESTR(NULL));

	printf("%s \n", MYMAKEPSTR("집가고싶다", "집가고싶다"));
	printf("%d \n", MYMAKEPSTR(Da, ta));
	
#endif // !AAA

#ifdef AAA
	printf("매크로 함수 : %d\n", MYMUL(3, 5)); //15
	printf("매크로 함수 : %d\n", MYMUL(3 + 2, 5));
	return 0;
#else
	printf("매크로 함수 : %d\n", MYADD(3, 5));
	printf("진짜 함수 : %d\n", myadd(3, 5));

	printf("매크로 함수 : %f\n", MYADD(3, 5.8));
	printf("진짜 함수 : %d\n", myadd(3, 5.8));
	return 0;
#endif // AAA

}