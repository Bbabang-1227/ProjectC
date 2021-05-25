#include <stdio.h>
#define DEBUG
typedef struct WORKER
{
	int no;
	char name[20];
	struct WORKER* pNext;
}WORKER;

#ifdef DEBUG
int dymain()
{
	//동적메모리 + 자기참조 구조체 : LinkedList
	{
		WORKER* pHead = NULL;
		WORKER* pNewUser = NULL;

		int answer = 1;
		int count = 1;

		while (answer ==1)
		{
			//1. 새로운 사뤈 1명을 위한 동적 메모리 할당
			pNewUser = (WORKER*)malloc(sizeof(WORKER));

			//2. 사원 정보입력
			printf("사원의 이름 입력 : ");
			scanf_s("%s", pNewUser->name, 20);
			pNewUser->no = count;

			//3. 링크조정
			pNewUser->pNext = pHead;
			pHead = pNewUser;
			count++;

			printf("계속? (0:아니/1:응)");
			scanf_s("%d%*c" , &answer);
		}

		WORKER* temp = pNewUser;
		while (temp)
		{
			printf("[%p] %d. %s[%p]\n", temp, temp->no, temp->name, temp->pNext);
			temp = temp->pNext;
		}

		return 0;
	}
	
	//동적메모리할당printf("======== 음료 관리 ========\n");
	
	int nKind = 0; //종류 갯수
	printf("음료의 종류는 총 몇개 인가요? : ");
	scanf_s("%d%*c", &nKind);
	//%*c == getch

	int nMaxLen = 0; //음료이름의 최대길이
	printf("음료이름의 길이는 총 몇글자 인가요? : ");
	scanf_s("%d%*c", &nMaxLen);
	
	char** pDrink = NULL;
	
	//pDrink = (char*)malloc(nKind);
	pDrink = (char**)malloc(sizeof(char*) * nKind);

	printf("pDrink의 사이즈 = %d , 메모리 = %d\n", sizeof(pDrink), _msize(pDrink));
	
	
	char temp[100];
	for (int i = 0; i < nKind; i++)
	{
		printf("%d 번째 음료의 이름을 적어주세요 : ", i + 1);
		scanf_s("%s", temp, 100);
		
		int len = strlen(temp);
		pDrink[i] = (char*)malloc(sizeof(char) * (len+1));
		//strcpy(pDrink[i], temp); //문자열함수
		memcpy(pDrink[i], temp, len + 1);
	}

	for (int i = 0; i < nKind; i++)
	{
		printf("%d 번째 음료 : %s(%d)\n", i + 1, pDrink[i] , _msize(pDrink[i]));
		free(pDrink[i]);
	}

	//정적배열
	{
		char pDrink[3][12] = { 0, };
		char temp[100];
		for (int i = 0; i < 3; i++)
		{
			printf("%d 번째 음료의 이름을 적어주세요 : ", i + 1);
			scanf_s("%s", temp, 100);

			strcpy(pDrink[i], temp);
			//pDrink[i] = (char*)malloc(sizeof(char) * (nMaxLen + 1));
			//strcpy(pDrink[i], temp); //문자열함수
			//int len = strlen(temp);
			//memcpy(pDrink[i], temp, len + 1);
		}

		for (int i = 0; i < 3; i++)
		{
			printf("%d 번째 음료 : %s\n", i + 1, pDrink[i]);
		}
	}

	return 0;

	char* p1 = (char*)malloc(2);
	p1[0] = 'a';
	p1[1] = 'b';
	printf("%c , %c\n", p1[0], p1[1]);
	printf("size : %d\n", sizeof(p1));
	printf("heapsize : %d\n\n", _msize(p1));
	free(p1);

	//변수를 받아 동적으로 할당가능
	//calloc = 계산해서 할당
	//realloc = 재할당

	int b = 8;
	int* p2 = (int*)malloc(b);
	p2[0] = 10;
	p2[1] = 20;
	printf("%d , %d\n", p2[0], p2[1]);
	printf("size : %d\n", sizeof(p2));
	printf("heapsize : %d\n", _msize(p2));
	free(p2);

	return 0;
}
#endif // DEBUG