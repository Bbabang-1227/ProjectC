#include <stdio.h>

struct point
{
	int x;
	int y;
};

typedef struct rect
{
	int x;
	int y;
	int w;
	int h;
} MYRECT;

typedef int AGE;
typedef struct point MYPOINT;

#pragma pack(push,1) // 메모리 단편화 해결하기 위함
typedef struct USERDATA
{
	char ch;
	int age;
}USERDATA; // 1+4 = 5B

typedef struct MYRDATA
{
	char ch;
	int age;
	double hight;
}MYDATA; //1+4+8 = 13B
#pragma pack(pop)

typedef struct SCORE
{
	int kor, eng, math, sum;
	long double avg;
}SCORE;

typedef struct STUDENT
{
	int no;
	char name[50];
	SCORE s;
}STUDENT;

typedef struct WORKER
{
	int no;
	char name[20];
	struct WORKRR* pLink;
	struct WORKER* pLinkPrev;
	struct WORKER* pLinkNext;
}WORKER;

typedef union SHAPE
{
	int x, y;
}SHAPE;

typedef union DIFFER
{
	char a;
	int b;
	double c;
}DIFFER;

int smain()
{
	{
		int a2 = 14;
		int b = 6;
		long double c = 25.0;
		long double d = 3.0;


		int itest = 0;
		itest = c / b;
		double dtest = 0;



		printf("=오류= Type 2.1F :정수(14) / 정수(6) : %2.1f\n", a2 / b);
		printf("=오류= Type D    :정수(14) / 실수(3.0) : %d\n", a2 / d);
		printf("=정상= Type 2.1F :정수(14) / 실수(6) : %2.1f\n\n", a2 / d);

		printf("=오류= Type D    :실수(25.0) / 실수(3.0) : %d\n", c / d);
		printf("=정상= Type 2.1F :실수(25.0) / 실수(3.0) : %2.1f\n", c / d);
		printf("=오류= Type D    :실수(25.0) / 정수(6) : %d\n", c / b);
		printf("=정상= Type 2.1F :실수(25.0) / 정수(6) : %2.1f\n\n", c / b);

		printf("test : %d \n", itest);
		printf("test : %f \n", itest);

		printf("정수와 정수끼리 나눌때는 d 타입으로 정상 표현가능\n연산에 실수가 하나라도 포함되있을경우 f 타입으로 받아야 표현가능\n\n ");
		return 0;
	}

	//열거형 ===================================================================================================
	enum season { SPRING, SUMMER, FALL, WINTER }; // 가독성 변수가갖는 값에 의미를 부여
	int mybirth = WINTER;
	printf("my Birth is %d\n", mybirth);
	//공용체 ===================================================================================================
	{
		SHAPE test;
		DIFFER test2;
		test.x = 10;
		printf("union : %d, %d\n", test.x, test.y);
		test.y = 20;
		printf("union : %d, %d\n", test.x, test.y);
		printf("unionsize : %d\n", sizeof(test));
		test2.a = "b"; test2.b = 202;
		printf("union2 : %c, %d\n", test2.a, test2.b);
		printf("unionsize : %d\n", sizeof(test2));

		return 0;
	}

	//구조체의 자기참조 포인터 == LinkedList ===================================================================
	{
		WORKER a = { 1,"방현준" , NULL };
		WORKER b = { 2,"이재호" , NULL };
		WORKER c = { 3,"노지훈" , NULL };
		WORKER d = { 4,"김동혁" , NULL };
		WORKER e = { 5,"김정록" , NULL };

		a.pLink = &b;
		b.pLink = &c;
		c.pLink = &d;
		d.pLink = &e;

		WORKER* pHead = &a; // 초기값

		while (pHead != NULL)
		{
			printf("[%p]%d , %s[%p]\n",
				pHead,
				pHead->no,
				pHead->name,
				pHead->pLink);
			pHead = pHead->pLink;
		}
	}
	return 0;

	//구조체의 포인터-------------------------------------------------------------------------------------------
	{
		STUDENT BANG = { 15051022,"BangHyunJun",{90,95,100,} };
		STUDENT* pStu = NULL;
		pStu = &BANG;

		pStu->s.sum = pStu->s.kor + pStu->s.eng + pStu->s.math;
		pStu->s.avg = pStu->s.sum / 3.0;

		printf("학번 : %d , 이름 : %s , 국어점수 : %d , 영어점수 : %d , 수학점수 : %d , TOTAL : %d , AVG : %2.1f", pStu->no, pStu->name, pStu->s.kor, pStu->s.eng, pStu->s.math
			, pStu->s.sum, pStu->s.avg);
	}

	return 0;

	//중첩구조체------------------------------------------------------------------------------------------------
	STUDENT BANG = { 15051022,"BangHyunJun",{90,95,100,} };
	BANG.s.sum = BANG.s.kor + BANG.s.eng + BANG.s.math;
	BANG.s.avg = BANG.s.sum / 3.0;
	printf("학번 : %d , 이름 : %s , 국어점수 : %d , 영어점수 : %d , 수학점수 : %d , TOTAL : %d , AVG : %2.1f", BANG.no, BANG.name, BANG.s.kor, BANG.s.eng, BANG.s.math
		, BANG.s.sum, BANG.s.avg);

	return 0;

	//구조체의 배열 사용----------------------------------------------------------------------------------------
	SCORE myClass[5] =
	{
		{50,60,70},
		{60,40,50},
		{70,60,50},
		{60,70,80},
		{50,60,30}
	};


	SCORE kim = { 70,80,70, };
	for (int i = 0; i < 5; i++)
	{
		myClass[i].sum = myClass[i].kor + myClass[i].eng + myClass[i].math;
		myClass[i].avg = myClass[i].sum / 3.0;
		printf("%d번 학생의 SCORE = total : %d , AVG : %2.1f\n", i + 1, myClass[i].sum, myClass[i].avg);
	}

	return 0;

	//구조체 사용----------------------------------------------------------------------------------------
	int a;
	a = 10;
	AGE Bang = 27;
	AGE Lee = 26;

	struct point pt1 = { 10,20 };
	struct point pt2;
	pt2.x = 100;
	pt2.y = 200;
	MYPOINT pt3 = { 111,222 };

	printf("pt1 : %d , %d\n", pt1.x, pt1.y);
	printf("pt2 : %d , %d\n", pt2.x, pt2.y);

	struct rect rect1 = { 10,20,30,40 };
	printf("rect1 : %d , %d , %d , %d\n", rect1.x, rect1.y, rect1.w, rect1.h);
	MYRECT rect2;
	printf("size of MYPOINT : %d\n", sizeof(MYPOINT));
	printf("size of MYRECT : %d\n", sizeof(MYRECT));

	printf("size of USERDATA : %d\n", sizeof(USERDATA));
	printf("size of MYDATA : %d\n", sizeof(MYDATA));

	return 0;
}