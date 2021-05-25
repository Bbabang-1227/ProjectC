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

#pragma pack(push,1) // �޸� ����ȭ �ذ��ϱ� ����
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



		printf("=����= Type 2.1F :����(14) / ����(6) : %2.1f\n", a2 / b);
		printf("=����= Type D    :����(14) / �Ǽ�(3.0) : %d\n", a2 / d);
		printf("=����= Type 2.1F :����(14) / �Ǽ�(6) : %2.1f\n\n", a2 / d);

		printf("=����= Type D    :�Ǽ�(25.0) / �Ǽ�(3.0) : %d\n", c / d);
		printf("=����= Type 2.1F :�Ǽ�(25.0) / �Ǽ�(3.0) : %2.1f\n", c / d);
		printf("=����= Type D    :�Ǽ�(25.0) / ����(6) : %d\n", c / b);
		printf("=����= Type 2.1F :�Ǽ�(25.0) / ����(6) : %2.1f\n\n", c / b);

		printf("test : %d \n", itest);
		printf("test : %f \n", itest);

		printf("������ �������� �������� d Ÿ������ ���� ǥ������\n���꿡 �Ǽ��� �ϳ��� ���Ե�������� f Ÿ������ �޾ƾ� ǥ������\n\n ");
		return 0;
	}

	//������ ===================================================================================================
	enum season { SPRING, SUMMER, FALL, WINTER }; // ������ ���������� ���� �ǹ̸� �ο�
	int mybirth = WINTER;
	printf("my Birth is %d\n", mybirth);
	//����ü ===================================================================================================
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

	//����ü�� �ڱ����� ������ == LinkedList ===================================================================
	{
		WORKER a = { 1,"������" , NULL };
		WORKER b = { 2,"����ȣ" , NULL };
		WORKER c = { 3,"������" , NULL };
		WORKER d = { 4,"�赿��" , NULL };
		WORKER e = { 5,"������" , NULL };

		a.pLink = &b;
		b.pLink = &c;
		c.pLink = &d;
		d.pLink = &e;

		WORKER* pHead = &a; // �ʱⰪ

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

	//����ü�� ������-------------------------------------------------------------------------------------------
	{
		STUDENT BANG = { 15051022,"BangHyunJun",{90,95,100,} };
		STUDENT* pStu = NULL;
		pStu = &BANG;

		pStu->s.sum = pStu->s.kor + pStu->s.eng + pStu->s.math;
		pStu->s.avg = pStu->s.sum / 3.0;

		printf("�й� : %d , �̸� : %s , �������� : %d , �������� : %d , �������� : %d , TOTAL : %d , AVG : %2.1f", pStu->no, pStu->name, pStu->s.kor, pStu->s.eng, pStu->s.math
			, pStu->s.sum, pStu->s.avg);
	}

	return 0;

	//��ø����ü------------------------------------------------------------------------------------------------
	STUDENT BANG = { 15051022,"BangHyunJun",{90,95,100,} };
	BANG.s.sum = BANG.s.kor + BANG.s.eng + BANG.s.math;
	BANG.s.avg = BANG.s.sum / 3.0;
	printf("�й� : %d , �̸� : %s , �������� : %d , �������� : %d , �������� : %d , TOTAL : %d , AVG : %2.1f", BANG.no, BANG.name, BANG.s.kor, BANG.s.eng, BANG.s.math
		, BANG.s.sum, BANG.s.avg);

	return 0;

	//����ü�� �迭 ���----------------------------------------------------------------------------------------
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
		printf("%d�� �л��� SCORE = total : %d , AVG : %2.1f\n", i + 1, myClass[i].sum, myClass[i].avg);
	}

	return 0;

	//����ü ���----------------------------------------------------------------------------------------
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