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
	//�����޸� + �ڱ����� ����ü : LinkedList
	{
		WORKER* pHead = NULL;
		WORKER* pNewUser = NULL;

		int answer = 1;
		int count = 1;

		while (answer ==1)
		{
			//1. ���ο� �珸 1���� ���� ���� �޸� �Ҵ�
			pNewUser = (WORKER*)malloc(sizeof(WORKER));

			//2. ��� �����Է�
			printf("����� �̸� �Է� : ");
			scanf_s("%s", pNewUser->name, 20);
			pNewUser->no = count;

			//3. ��ũ����
			pNewUser->pNext = pHead;
			pHead = pNewUser;
			count++;

			printf("���? (0:�ƴ�/1:��)");
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
	
	//�����޸��Ҵ�printf("======== ���� ���� ========\n");
	
	int nKind = 0; //���� ����
	printf("������ ������ �� � �ΰ���? : ");
	scanf_s("%d%*c", &nKind);
	//%*c == getch

	int nMaxLen = 0; //�����̸��� �ִ����
	printf("�����̸��� ���̴� �� ����� �ΰ���? : ");
	scanf_s("%d%*c", &nMaxLen);
	
	char** pDrink = NULL;
	
	//pDrink = (char*)malloc(nKind);
	pDrink = (char**)malloc(sizeof(char*) * nKind);

	printf("pDrink�� ������ = %d , �޸� = %d\n", sizeof(pDrink), _msize(pDrink));
	
	
	char temp[100];
	for (int i = 0; i < nKind; i++)
	{
		printf("%d ��° ������ �̸��� �����ּ��� : ", i + 1);
		scanf_s("%s", temp, 100);
		
		int len = strlen(temp);
		pDrink[i] = (char*)malloc(sizeof(char) * (len+1));
		//strcpy(pDrink[i], temp); //���ڿ��Լ�
		memcpy(pDrink[i], temp, len + 1);
	}

	for (int i = 0; i < nKind; i++)
	{
		printf("%d ��° ���� : %s(%d)\n", i + 1, pDrink[i] , _msize(pDrink[i]));
		free(pDrink[i]);
	}

	//�����迭
	{
		char pDrink[3][12] = { 0, };
		char temp[100];
		for (int i = 0; i < 3; i++)
		{
			printf("%d ��° ������ �̸��� �����ּ��� : ", i + 1);
			scanf_s("%s", temp, 100);

			strcpy(pDrink[i], temp);
			//pDrink[i] = (char*)malloc(sizeof(char) * (nMaxLen + 1));
			//strcpy(pDrink[i], temp); //���ڿ��Լ�
			//int len = strlen(temp);
			//memcpy(pDrink[i], temp, len + 1);
		}

		for (int i = 0; i < 3; i++)
		{
			printf("%d ��° ���� : %s\n", i + 1, pDrink[i]);
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

	//������ �޾� �������� �Ҵ簡��
	//calloc = ����ؼ� �Ҵ�
	//realloc = ���Ҵ�

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