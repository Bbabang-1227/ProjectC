#include <stdio.h>
#include "MyHeader.h"

#define MYADD(a,b) (a+b) // ��ũ�� �Լ� = Ÿ���� �������� �ʰ� ����
//#define MYMUL(a,b) (a*b)
#define MYMUL(a,b) ((a)*(b))
#define MYMAKESTR(a) #a // # : ���ڿ��� �������
#define MYMAKEPSTR(a,b) a##b // ## : �ѵ���� �������
//#define AAA
int myadd(int a, int b) { return a + b; } //  �Լ�

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

	printf("%s \n", MYMAKEPSTR("������ʹ�", "������ʹ�"));
	printf("%d \n", MYMAKEPSTR(Da, ta));
	
#endif // !AAA

#ifdef AAA
	printf("��ũ�� �Լ� : %d\n", MYMUL(3, 5)); //15
	printf("��ũ�� �Լ� : %d\n", MYMUL(3 + 2, 5));
	return 0;
#else
	printf("��ũ�� �Լ� : %d\n", MYADD(3, 5));
	printf("��¥ �Լ� : %d\n", myadd(3, 5));

	printf("��ũ�� �Լ� : %f\n", MYADD(3, 5.8));
	printf("��¥ �Լ� : %d\n", myadd(3, 5.8));
	return 0;
#endif // AAA

}