#include <stdio.h>
#include <Windows.h>
#include <memory.h>


#define DATA_FILE_NAME "c:\\temp\\myAddr.dat"
typedef struct _USERDATA
{
	char strName[32];	  // 이름
	int nAge;			  // 나이
	int nGender;		  // 성별
} USERDATA;

//배열로 처리
#define		MAX_BOOKCOUNT	10
int		g_nCount = 0;
USERDATA	g_AddrBook[MAX_BOOKCOUNT];


int PrintUI()
{
	int nInput = 0;

	system("cls");
	printf("=============================================================\n");
	printf("전화번호부(Array)\n");
	printf("---------------------------------------------------==========\n");
	printf("[1] 추가\t [2] 검색\t [3] 전체보기\t [4] 삭제\t [0] 종료\n");
	printf("==============================================================\n");

	// 사용자가 선택한 메뉴의 값을 반환한다.
	scanf_s("%d", &nInput);
	(void)getchar();//버퍼에 남은 엔터 제거용
	return nInput;
}


void Add();
void Search();
void PrintAll();
void Delete();


FILE* stream = NULL;

int LoadData(char* szFileName) {

	//g_AddrBook <-- szFileName
	//1.스트림개방(rb)
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
	//1.스트림개방(wb)
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

	// 메인 이벤트 반복문
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu) {
		case 1:		  // Add : 이름, 나이, 성별을 입력받아 친구를 추가하는 함수
			Add();
			break;
		case 2:		  // Search : 이름을 입력받아 검색하고, 검색된 결과를 보여주는 함수
			Search();
			break;
		case 3:		 // Print all : 전화부에 들어있는 모든 데이터를 화면에 출력하는 함수
			PrintAll();
			break;
		case 4:		 // Delete : 선택한 데이터를 삭제하는 함수
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
		printf("더이상 추가할 수 없습니다\n");
		getch();
		return;//Err:Full
	}

	char	cmpName[32]; // 비교문자열
	printf("이름을 입력하세요 : ");
	gets_s(cmpName, sizeof(cmpName));

	int test = Compare(cmpName);
	if (test != -1)
	{
		printf("동일한 사람이 이미 있습니다\n");
		getch();
		return;//Err:Same name
	}
	strcpy_s(g_AddrBook[g_nCount].strName, sizeof(g_AddrBook[g_nCount].strName), cmpName);
	printf("나이를 입력하세요 : ");
	scanf_s("%d", &g_AddrBook[g_nCount].nAge);
	printf("성별을 입력하세요(남성:0, 여성:1) : ");
	scanf_s("%d", &g_AddrBook[g_nCount].nGender);

	g_nCount++;
}

void Search() {
	char srcName[32];
	printf("검색할 이름을 입력하세요 : ");
	gets_s(srcName, sizeof(srcName));

	int hit = 0;
	for (int i = 0; i < g_nCount; i++)
	{
		if (strcmp(g_AddrBook[i].strName, srcName) == 0)
		{
			hit = 1;
			printf("[%p] %s\t%d세 %s\n",
				&g_AddrBook[i],
				g_AddrBook[i].strName,
				g_AddrBook[i].nAge,
				g_AddrBook[i].nGender == 0 ? "남성" : "여성");
			break;
		}
	}
	if (hit == 0)
	{
		printf("찾지못했습니다");
	}
	getch();
}

void PrintAll() {
	if (g_nCount == 0)
	{
		printf("정보가 없습니다");
		getch();
		return;
	}
	for (int i = 0; i < g_nCount; i++)
	{
		printf("[%p] %s\t%d세 %s\n",
			&g_AddrBook[i],
			g_AddrBook[i].strName,
			g_AddrBook[i].nAge,
			g_AddrBook[i].nGender == 0 ? "남성" : "여성");
	}
	getch();
}

void Delete() {
	if (g_nCount == 0) {
		printf("삭제할 정보가 없습니다");
		getch();
		return;
	}
	char	cmpName[32]; // 비교문자열
	printf("삭제할 이름을 입력하세요 : ");
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
			return i; //비교해서 동일할경우 1반환
		}
	}
	return -1;
}