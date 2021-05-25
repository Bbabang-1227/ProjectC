#include <stdio.h>
#include <Windows.h>
#include <memory.h>


#define DATA_FILE_NAME "c:\\temp\\myAddr.dat"
typedef struct _USERDATA
{
	char strName[32];	  // �̸�
	int nAge;			  // ����
	int nGender;		  // ����
} USERDATA;

//�迭�� ó��
#define		MAX_BOOKCOUNT	10
int		g_nCount = 0;
USERDATA	g_AddrBook[MAX_BOOKCOUNT];


int PrintUI()
{
	int nInput = 0;

	system("cls");
	printf("=============================================================\n");
	printf("��ȭ��ȣ��(Array)\n");
	printf("---------------------------------------------------==========\n");
	printf("[1] �߰�\t [2] �˻�\t [3] ��ü����\t [4] ����\t [0] ����\n");
	printf("==============================================================\n");

	// ����ڰ� ������ �޴��� ���� ��ȯ�Ѵ�.
	scanf_s("%d", &nInput);
	(void)getchar();//���ۿ� ���� ���� ���ſ�
	return nInput;
}


void Add();
void Search();
void PrintAll();
void Delete();


FILE* stream = NULL;

int LoadData(char* szFileName) {

	//g_AddrBook <-- szFileName
	//1.��Ʈ������(rb)
	fopen_s(&stream, DATA_FILE_NAME, "rb");
	//2.read at stream
	fread(&g_nCount, sizeof(int), 1, stream);
	for (int i = 0; i < g_nCount; i++)
	{
		fread(g_AddrBook + i, sizeof(USERDATA), 1, stream);
	}
	//3. close stream
	fclose(stream);
	return 0;
}

int SaveData(char* szFileName) {

	//g_AddrBook --> szFileName
	//1.��Ʈ������(wb)
	fopen_s(&stream, DATA_FILE_NAME, "wb");
	//2.save at stream
	fwrite(&g_nCount, sizeof(int), 1, stream);
	for (int i = 0; i < g_nCount; i++)
	{
		fwrite(g_AddrBook + i, sizeof(USERDATA), 1, stream);
	}
	//3. close stream
	fclose(stream);
	return 0;
}

void abmain()
{

	int nMenu = 0;
	LoadData(DATA_FILE_NAME); //read file

	// ���� �̺�Ʈ �ݺ���
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu) {
		case 1:		  // Add : �̸�, ����, ������ �Է¹޾� ģ���� �߰��ϴ� �Լ�
			Add();
			break;
		case 2:		  // Search : �̸��� �Է¹޾� �˻��ϰ�, �˻��� ����� �����ִ� �Լ�
			Search();
			break;
		case 3:		 // Print all : ��ȭ�ο� ����ִ� ��� �����͸� ȭ�鿡 ����ϴ� �Լ�
			PrintAll();
			break;
		case 4:		 // Delete : ������ �����͸� �����ϴ� �Լ�
			Delete();
			break;
		case 0:
			return;
			break;
		}
	}
	SaveData(DATA_FILE_NAME); //save file
}

void Add()
{
	if (g_nCount >= MAX_BOOKCOUNT)
	{
		printf("���̻� �߰��� �� �����ϴ�\n");
		getch();
		return;//Err:Full
	}

	char	cmpName[32]; // �񱳹��ڿ�
	printf("�̸��� �Է��ϼ��� : ");
	gets_s(cmpName, sizeof(cmpName));

	int test = Compare(cmpName);
	if (test != -1)
	{
		printf("������ ����� �̹� �ֽ��ϴ�\n");
		getch();
		return;//Err:Same name
	}
	strcpy_s(g_AddrBook[g_nCount].strName, sizeof(g_AddrBook[g_nCount].strName), cmpName);
	printf("���̸� �Է��ϼ��� : ");
	scanf_s("%d", &g_AddrBook[g_nCount].nAge);
	printf("������ �Է��ϼ���(����:0, ����:1) : ");
	scanf_s("%d", &g_AddrBook[g_nCount].nGender);

	g_nCount++;
}

void Search() {
	char srcName[32];
	printf("�˻��� �̸��� �Է��ϼ��� : ");
	gets_s(srcName, sizeof(srcName));

	int hit = 0;
	for (int i = 0; i < g_nCount; i++)
	{
		if (strcmp(g_AddrBook[i].strName, srcName) == 0)
		{
			hit = 1;
			printf("[%p] %s\t%d�� %s\n",
				&g_AddrBook[i],
				g_AddrBook[i].strName,
				g_AddrBook[i].nAge,
				g_AddrBook[i].nGender == 0 ? "����" : "����");
			break;
		}
	}
	if (hit == 0)
	{
		printf("ã�����߽��ϴ�");
	}
	getch();
}

void PrintAll() {
	if (g_nCount == 0)
	{
		printf("������ �����ϴ�");
		getch();
		return;
	}
	for (int i = 0; i < g_nCount; i++)
	{
		printf("[%p] %s\t%d�� %s\n",
			&g_AddrBook[i],
			g_AddrBook[i].strName,
			g_AddrBook[i].nAge,
			g_AddrBook[i].nGender == 0 ? "����" : "����");
	}
	getch();
}

void Delete() {
	if (g_nCount == 0) {
		printf("������ ������ �����ϴ�");
		getch();
		return;
	}
	char	cmpName[32]; // �񱳹��ڿ�
	printf("������ �̸��� �Է��ϼ��� : ");
	gets_s(cmpName, sizeof(cmpName));

	int n_dinex = 0;

	for (int i = 0; i < g_nCount; i++)
	{
		if (strcmp(g_AddrBook[i].strName, cmpName) == 0)
		{
			n_dinex = i;
			break;
		}
	}
	for (int i = n_dinex; i < MAX_BOOKCOUNT; i++)
	{
		g_AddrBook[i] = g_AddrBook[i + 1];
	}
	g_nCount--;
}

int Compare(char cmp[]) {
	for (int i = 0; i < g_nCount; i++)
	{
		if (strcmp(cmp, g_AddrBook[i].strName) == 0)
		{
			return i; //���ؼ� �����Ұ�� 1��ȯ
		}
	}
	return -1;
}