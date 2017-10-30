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
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

void Update()
{
	const int MAX = 20;

	char *pInput = NULL;
	char arrInput[20] = { 0, };
	char arrEngDB[20][20] = {0,};
	char arrKorDB[20][20] = {0,};
	int awsCheck[20] = { 0, };

	int i = 0, j = 0;
	int nEngCounter = 0; //DB안에 들어가 있는 단어의 갯수. 배열 인덱스용
	int nEngDbCounter = 0; //DB에 들어가 있는 단어의 갯수. 문제 카운터용
	int nKorCounter = 0; //DB안에 들어가 있는 단어의 갯수. 배열 인덱스용
	int nKorDbCounter = 0; //DB에 들어가 있는 단어의 갯수. 문제 카운터용
	int nInputLength = 0; //입력한 단어의 길이
	
	int nAwsCheck = 0;//중복문제 체크
	int nStartQuesNumber = 0;
	int nAwCount = 0; //정답의 갯수 카운트
	int nQuesCount = 0; //문제의 갯수 카운트	
	int nItem = 0; //랜덤한 DB의 인덱스
	float fScore = 0.0f; // 총 점수 

	printf("영어 단어와 뜻인 한글 단어를 입력 (ex. Apple 사과/대소문자 상관 없음) \n");
	printf("단어당 20문자 총 20단어까지 입력 가능.\n");
	printf("0을 입력하면 입력 종료. 게임 시작 \n");
	printf("===========================================================================================\n");
	
	while (1)
	{
	Engback:
		printf("영어 단어 입력 (0을 입력하면 입력 종료. 게임 시작) : ");
		scanf_s("%s", arrInput, sizeof(arrInput));
		
		//입력이 0 이면 단어입력 종료
		if (arrInput[0] == '0') 
		{
			break;
		}

		//입력한 단어의 마지막 \0문자가 오기전까지 배열을 nInputLength에 카운트
		while (1)
		{
			i++;
			nInputLength = i;
			if (arrInput[i] == '\0') 
			{
				int k;
				for (k = i; k < MAX; k++)
				{
					arrInput[k] = '\0';
				}
				for (j = 0; j < MAX; j++)
				{
					if (_stricmp(arrEngDB[j], arrInput) == 0)
					{
						printf("중복된 단어가 있습니다. 다시 입력해 주세요.\n");
						goto Engback;
					}
				}
				
				i = 0;
				break;
			}
		}
		for (j = 0; j< nInputLength; j++)
		{
			if (arrInput[j] != '\0')
			{
				arrEngDB[nEngCounter][j] = arrInput[j];
			}			
		}
		nEngCounter++;
		nEngDbCounter++;

	Korback:
		printf("한글 단어 입력 (0을 입력하면 입력 종료. 게임 시작) :");
		scanf_s("%s", arrInput, sizeof(arrInput));
		
		//입력이 0 이면 단어입력 종료
		if (arrInput[0] == '0')
		{
			break;
		}

		while (1)
		{
			i++;
			nInputLength = i;
			if (arrInput[i] == '\0')
			{
				int k;
				for (k = i; k < MAX; k++)
				{
					arrInput[k] = '\0';
				}
				for (j = 0; j < MAX; j++)
				{
					if (_stricmp(arrKorDB[j], arrInput) == 0)
					{
						printf("중복된 단어가 있습니다. 다시 입력해 주세요.\n\n");
						goto Korback;
					}
				}
				i = 0;
				break;
			}
		}
		for (j = 0; j< nInputLength; j++)
		{
			if (arrInput[j] != '\0')
			{
				arrKorDB[nKorCounter][j] = arrInput[j];
			}
		}
		nKorCounter++;
		nKorDbCounter++;
	}
	for ( i = 0; i<MAX; i++)
	{
		printf("\n\n\n\n");
	}
	
	i = 0;
	j = 0;

	printf("몇 문제를 푸시겠습니까?? \n");
	printf("현재 가능한 문제 최대 갯수 %d문제\n", nEngDbCounter);
	scanf_s("%d",&nStartQuesNumber,sizeof(int));
	printf("%d 문제 갑니다.\n", nStartQuesNumber);
	printf("한글 단어를 물어보면 (ex. 사과?) 영어 단어 입력(ex.apple)\n");

	while (nStartQuesNumber != 0)
	{	
		srand(time(NULL));
		nItem = rand() % (nEngCounter );

		if (awsCheck[nItem] == nAwsCheck)
		{
			awsCheck[nItem] = 1;			
		}
		else if (awsCheck[nItem] != nAwsCheck)
		{
			continue;
		}

		printf("\n%s를 영어로 하면??\n=>", arrKorDB[nItem]);
		++nQuesCount;
		scanf_s("%s",arrInput, sizeof(arrInput));
		
		while (1)
		{
			i++;
			nInputLength = i;
			if (arrInput[i] == '\0')
			{
				int k = 0;
				for (k = i; k < MAX; k++)
				{
					arrInput[k] = '\0';
				}
				i = 0;
				break;
			}
		}		

		if (_stricmp( arrEngDB[nItem], arrInput) == 0)
		{
			printf("\n%s는(은) 영어로 %s! 정답!\n",arrKorDB[nItem] ,arrEngDB[nItem] );
			nAwCount++;
		}
		else
		{
			printf("\n틀렸습니다. 정답은 %s입니다. \n",arrEngDB[nItem]);
		}
		nStartQuesNumber--;
	}
	if (nStartQuesNumber == 0)
	{
		for (i = 0; i < nQuesCount; i++)
		{			
			fScore = fScore + (100.00f / nQuesCount);
		}
		printf("\n\n%d문제중 %d문제를 맞추셨습니다. \n\n 총스코어 %.0f점 입니다.\n", nQuesCount, nAwCount, ceilf(fScore));

	}
	/*for (i = 0; i< MAX; i++)
	{
		printf("영단어 : %s \n", arrEngDB[i]);
		printf("한단어 : %s \n", arrKorDB[i]);

	}*/
	printf("\n\n\n\n\n\n\n\n\n");
	printf("게임 종료 \n\n\n");

}

void main()
{

	Update();

}







//void Update1()
//{
//	char arrInput[15] = { 0, };
//	char arrEngDB[20] = { 0, };
//	char arrKorDB[20] = { 0, };
//
//	int i, j;
//	int nDbLength = 0;
//	int nQuit = 1;
//
//	printf("영어 단어와 뜻인 한글 단어를 입력 (ex. Apple 사과) \n");
//	printf("0을 입력하면 입력 종료. \n");
//
//	while (1)
//	{
//		printf("영어 단어 입력 (0을 입력하면 종료):");
//		scanf_s("%s", arrInput, sizeof(arrInput));
//
//		if (arrInput[0] == '0')
//		{
//			break;
//		}
//		for (i = 0; i < sizeof(arrInput); i++)
//		{
//			if (arrInput[i] == '\0')
//			{
//				nDbLength = i;
//			}
//		}
//
//		if (arrEngDB[0] == '\0')
//		{
//			for (i = 0; i < nDbLength; i++)
//			{
//				arrEngDB[i] = arrInput[i];
//			}
//		}
//		else
//		{
//			int temp = 0;
//			int tempj = 1;
//			for (j = 0; j < sizeof(arrEngDB); j++)
//			{
//				if (arrEngDB[j] == '\0')
//				{
//					arrEngDB[tempj + j] = arrInput[temp];
//					temp++;
//					tempj = 0;
//					if (arrInput[temp] == '\0')
//					{
//						break;
//					}
//				}
//			}
//		}
//
//		printf("한글 단어 입력 (0을 입력하면 종료):");
//		scanf_s("%s", arrInput, sizeof(arrInput));
//
//		if (arrInput[0] == '0')
//		{
//			break;
//		}
//		for (i = 0; i < sizeof(arrInput); i++)
//		{
//			if (arrInput[i] == '\0')
//			{
//				nDbLength = i;
//			}
//		}
//
//		if (arrKorDB[0] == '\0')
//		{
//			for (i = 0; i < nDbLength; i++)
//			{
//				arrKorDB[i] = arrInput[i];
//			}
//		}
//		else
//		{
//			int temp = 0;
//			for (j = 0; j < sizeof(arrKorDB); j++)
//			{
//				if (arrKorDB[j] == '\0')
//				{
//					arrKorDB[j] = arrInput[temp];
//					temp++;
//					if (arrInput[temp] == '\0')
//					{
//						break;
//					}
//				}
//			}
//		}
//		printf("%s \n", arrEngDB);
//		printf("%s \n", arrKorDB);
//	}
//	printf("입력 종료 \n");
//
//	printf("문제\n");
//	printf("한글 단어를 물어보면 (ex. 사과?) 영어 단어 입력(ex.Apple)\n");
//	while (1)
//	{
//		printf("%s를 영어로 하면??");
//		scanf_s("");
//
//	}
//
//	printf("exit");
//
//}