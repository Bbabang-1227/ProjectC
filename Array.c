#include <stdio.h>

int armain()
{
	int aList[4][5] = {
		{10,20,30,40},
		{50,60,70,80},
		{90,100,110,120}
	};

	int test = sizeof(*(aList)) / sizeof(int);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++) {
			if (i == 3)
			{
				aList[i][j] = aList[0][j] + aList[1][j] + aList[2][j];
			}
			if (j == 4)
			{
				aList[i][j] = aList[i][0] + aList[i][1] + aList[i][2] + aList[i][3];
			}
			printf("%d\t", aList[i][j]);
		}
		printf("\n");
	}

	////////////////////////////////////////////////////////
	int arrGrade[2][3] = { 1,2,3,4,5,6 };
	printf("\n林家0 : %p\n", arrGrade);
	printf("林家1 : %p\n", arrGrade[0]);

	printf("林家2 : %d\n", arrGrade[0][1]);
	printf("林家2 : %d\n", *(*(arrGrade + 0) + 1));

	printf("林家3 : %p\n", arrGrade[1]);

	printf("林家4 : %d\n", arrGrade[1][1]);
	printf("林家2 : %d\n\n", *(*(arrGrade + 1) + 1));

	int arrNumbers[] = { 1,2,3,4,5,10,44,25,235,-5 };
	int max = arrNumbers[0];
	int min = *(arrNumbers + 0);

	for (int i = 1; i < sizeof(arrNumbers) / sizeof(int); i++)
	{
		if (max < arrNumbers[i])
		{
			max = arrNumbers[i];
		}
	}
	printf("max : %d\n\n", max);

	for (int i = 1; i < sizeof(arrNumbers) / sizeof(int); i++)
	{
		if (min > *(arrNumbers + i))
		{
			min = *(arrNumbers + i);
		}
	}
	printf("min : %d\n\n", min);

	int arr[3] = { 1,2,3, };
	char latter[3] = { 'A','B','C' };
	char arp[] = "笼俊啊绊酵促";

	printf("蔼 : %d,%d,%d\n", arr[0], arr[1], arr[2]);
	printf("蔼1 : %d,%d,%d\n", *arr, *arr + 1, *arr + 2);
	printf("林家 : %p,%p,%p\n", &arr[0], &arr[1], &arr[2]);
	printf("林家1 : %p,%p,%p\n\n", arr, arr + 1, arr + 2);

	printf("蔼 : %c,%c,%c\n", latter[0], latter[1], latter[2]);
	printf("林家 : %p,%p,%p\n", &latter[0], &latter[1], &latter[2]);
	printf("林家1 : %p,%p,%p", latter, latter + 1, latter + 2);

	return 0;
}