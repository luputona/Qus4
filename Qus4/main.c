/*
영어 단어 맞추기 게임

개요 : 한글로 제시된 단어의 영어 단어를 맞추는 게임.
게임방법
영어 단어와 뜻인 한글 단어를 입력 (ex. Apple 사과)
0을 입력하면 입력 종료
한글 단어를 물어보면 (ex. 사과?)
영어 단어 입력 (ex. Apple)
묻는 단어는 랜덤 (중복 안되게)
모든 단어를 맞히면 100점
*/

#include<stdio.h>

void SaveDB(char *engDB, char *korDB)
{
	
}


void main()
{
	char arrEng[20] = { 0, };
	char arrKor[20] = { 0, };
	char arrInput[] = { 0, };
	char arrEngDB[] = { 0, };
	char arrKorDB[] = { 0, };
	
	int nEngDBLen = 1;
	int nKorDBLen = 1;
	int i;

	char nQuit = 1;
	int nDBCount = 0;

	printf("영어 단어와 뜻인 한글 단어를 입력 (ex. Apple 사과) \n");
	printf("0을 입력하면 입력 종료. \n");
	while (nQuit != 0)
	{
		printf("영어 단어 입력 (0을 입력하면 종료):");
		scanf_s("%s", arrEng, sizeof(arrEng));

		//printf("한글 단어 입력 (0을 입력하면 종료):");
		//scanf_s("%s", arrKor, sizeof(arrKor));

		if (arrEng[0] == 0 || arrEng[0] == 0)
		{
			nQuit = 0;
			break;
		}

		while (arrEng[nEngDBLen] != '\0')
		{
			nEngDBLen++;
		}
		
		for (i = 0; i <= nEngDBLen; i++)
		{
			if (arrEngDB[nEngDBLen] != '\0')
			{
				arrEngDB[i] = arrEng[i];
			}
			else if (arrEngDB[nEngDBLen] != 0)
			{
				arrEngDB[i + nEngDBLen] = arrEng[i];
			}			
		}

		/*while (arrKor[nKorDBLen] != '\0')
		{
			nKorDBLen++;
		}		
		
		for (i = 0; i<= nKorDBLen; i++)
		{
			if (arrKorDB[0] == 0)
			{
				arrKorDB[i] = arrKor[i];
			}
			else if (arrKorDB[0] != 0)
			{
				arrKorDB[i + nKorDBLen] = arrKor[i];
			}
		}		*/
		printf("%s", arrEngDB);
		printf("%s", arrKorDB);
		printf("\n");
	}
	printf("입력 종료\n");
	
}
