/*
���� �ܾ� ���߱� ����

���� : �ѱ۷� ���õ� �ܾ��� ���� �ܾ ���ߴ� ����.
���ӹ��
���� �ܾ�� ���� �ѱ� �ܾ �Է� (ex. Apple ���)
0�� �Է��ϸ� �Է� ����
�ѱ� �ܾ ����� (ex. ���?)
���� �ܾ� �Է� (ex. Apple)
���� �ܾ�� ���� (�ߺ� �ȵǰ�)
��� �ܾ ������ 100��
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void Update1()
{
	char arrInput[15] = { 0, };
	char arrEngDB[20] = { 0, };
	char arrKorDB[20] = { 0, };

	int i, j;
	int nDbLength = 0;
	int nQuit = 1;

	printf("���� �ܾ�� ���� �ѱ� �ܾ �Է� (ex. Apple ���) \n");
	printf("0�� �Է��ϸ� �Է� ����. \n");
	
	while (1)
	{
		printf("���� �ܾ� �Է� (0�� �Է��ϸ� ����):");
		scanf_s("%s", arrInput, sizeof(arrInput));
				
		if (arrInput[0] == '0')
		{
			break;
		}		
		for ( i = 0; i < sizeof(arrInput);i++)
		{
			if (arrInput[i] == '\0')
			{
				nDbLength = i;
			}
		}

		if (arrEngDB[0] == '\0')
		{
			for (i = 0; i < nDbLength; i++)
			{
				arrEngDB[i] = arrInput[i];
			}
		}
		else
		{			
			int temp = 0;
			int tempj = 1;
			for (j = 0; j < sizeof(arrEngDB); j++)
			{
				if (arrEngDB[j] == '\0' )
				{					
					arrEngDB[tempj+j] = arrInput[temp];
					temp++;	
					tempj = 0;
					if (arrInput[temp] == '\0')
					{
						break;
					}
				}
			}								
		}

		printf("�ѱ� �ܾ� �Է� (0�� �Է��ϸ� ����):");
		scanf_s("%s", arrInput, sizeof(arrInput));

		if (arrInput[0] == '0')
		{
			break;
		}
		for (i = 0; i < sizeof(arrInput); i++)
		{
			if (arrInput[i] == '\0')
			{
				nDbLength = i;
			}
		}

		if (arrKorDB[0] == '\0')
		{
			for (i = 0; i < nDbLength; i++)
			{
				arrKorDB[i] = arrInput[i];
			}
		}
		else
		{
			int temp = 0;
			for (j = 0; j < sizeof(arrKorDB); j++)
			{
				if (arrKorDB[j] == '\0')
				{
					arrKorDB[j] = arrInput[temp];
					temp++;
					if (arrInput[temp] == '\0')
					{
						break;
					}
				}
			}
		}
		printf("%s \n", arrEngDB);
		printf("%s \n", arrKorDB);
	}
	printf("�Է� ���� \n");
	
	printf("����\n");
	printf("�ѱ� �ܾ ����� (ex. ���?) ���� �ܾ� �Է�(ex.Apple)\n");
	while (1)
	{
		printf("%s�� ����� �ϸ�??");
		scanf_s("");
			
	}

	printf("exit");

}

void Update()
{
	const int MAX = 20;

	char *pInput = NULL;
	char arrInput[20] = { 0, };
	char arrEngDB[20][20] = {0,};
	char arrKorDB[20][20] = {0,};

	int i = 0, j = 0;
	int nEngCounter = 0;
	int nEngDbCounter = 0;
	int nKorCounter = 0;
	int nKorDbCounter = 0;
	int nInputLength = 0;
	int nRandomQ = 0;

	int nDBCount = 0;
	int nAwCount = 0;
	int nQuesCount = 0;
	int nScore = 0;

	printf("���� �ܾ�� ���� �ѱ� �ܾ �Է� (ex. Apple ���) \n");
	printf("0�� �Է��ϸ� �Է� ����. ���� ���� \n");
		
	//pEngDB[0] = "apple";

	while (1)
	{
		printf("���� �ܾ� �Է� (0�� �Է��ϸ� �Է� ����. ���� ����) : ");
		scanf_s("%s", arrInput, sizeof(arrInput));
		
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

		printf("�ѱ� �ܾ� �Է� (0�� �Է��ϸ� �Է� ����. ���� ����) :");
		scanf_s("%s", arrInput, sizeof(arrInput));
		
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
		printf("\n\n");
	}
	
	i = 0;
	j = 0;

	printf("���� ���ϴ�.\n");
	printf("�ѱ� �ܾ ����� (ex. ���?) ���� �ܾ� �Է�(ex.apple)\n");
	while (1)
	{
		srand(time(NULL));
		int nTemp = rand() % (nEngCounter );
		printf("%s�� ����� �ϸ�??\n=>", arrKorDB[nTemp]);
		++nQuesCount;
		scanf_s("%s",arrInput, sizeof(arrInput));
		
		while (1)
		{
			i++;
			nInputLength = i;
			pInput = arrInput;
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

		if (_stricmp( arrEngDB[nTemp], arrInput) == 0)
		{
			printf("%s��(��) ����� %s! ����!\n",arrKorDB[nTemp] ,arrEngDB[nTemp] );
			nAwCount++;
		}
		else
		{
			printf("Ʋ�Ƚ��ϴ�. ������ %s�Դϴ�. \n",arrEngDB[nTemp]);
		}
		
		if (nQuesCount > nEngDbCounter)
		{
			for ( i = 0; i < nQuesCount; i++)
			{
				nScore += (100 / nQuesCount);
			}
			printf("%d������ %d������ ���߼̽��ϴ�. \n �ѽ��ھ� %d�� �Դϴ�.\n",nQuesCount,nAwCount,nScore);
			break;
		}
	}

	/*for (i = 0; i< MAX; i++)
	{
		printf("���ܾ� : %s \n", arrEngDB[i]);
		printf("�Ѵܾ� : %s \n", arrKorDB[i]);

	}*/
	printf("���� ���� \n");

}

void main()
{

	Update();

}
