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
	int nEngCounter = 0; //DB�ȿ� �� �ִ� �ܾ��� ����. �迭 �ε�����
	int nEngDbCounter = 0; //DB�� �� �ִ� �ܾ��� ����. ���� ī���Ϳ�
	int nKorCounter = 0; //DB�ȿ� �� �ִ� �ܾ��� ����. �迭 �ε�����
	int nKorDbCounter = 0; //DB�� �� �ִ� �ܾ��� ����. ���� ī���Ϳ�
	int nInputLength = 0; //�Է��� �ܾ��� ����
	
	int nAwsCheck = 0;//�ߺ����� üũ
	int nStartQuesNumber = 0;
	int nAwCount = 0; //������ ���� ī��Ʈ
	int nQuesCount = 0; //������ ���� ī��Ʈ	
	int nItem = 0; //������ DB�� �ε���
	float fScore = 0.0f; // �� ���� 

	printf("���� �ܾ�� ���� �ѱ� �ܾ �Է� (ex. Apple ���/��ҹ��� ��� ����) \n");
	printf("�ܾ�� 20���� �� 20�ܾ���� �Է� ����.\n");
	printf("0�� �Է��ϸ� �Է� ����. ���� ���� \n");
	printf("===========================================================================================\n");
	
	while (1)
	{
	Engback:
		printf("���� �ܾ� �Է� (0�� �Է��ϸ� �Է� ����. ���� ����) : ");
		scanf_s("%s", arrInput, sizeof(arrInput));
		
		//�Է��� 0 �̸� �ܾ��Է� ����
		if (arrInput[0] == '0') 
		{
			break;
		}

		//�Է��� �ܾ��� ������ \0���ڰ� ���������� �迭�� nInputLength�� ī��Ʈ
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
						printf("�ߺ��� �ܾ �ֽ��ϴ�. �ٽ� �Է��� �ּ���.\n");
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
		printf("�ѱ� �ܾ� �Է� (0�� �Է��ϸ� �Է� ����. ���� ����) :");
		scanf_s("%s", arrInput, sizeof(arrInput));
		
		//�Է��� 0 �̸� �ܾ��Է� ����
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
						printf("�ߺ��� �ܾ �ֽ��ϴ�. �ٽ� �Է��� �ּ���.\n\n");
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

	printf("�� ������ Ǫ�ðڽ��ϱ�?? \n");
	printf("���� ������ ���� �ִ� ���� %d����\n", nEngDbCounter);
	scanf_s("%d",&nStartQuesNumber,sizeof(int));
	printf("%d ���� ���ϴ�.\n", nStartQuesNumber);
	printf("�ѱ� �ܾ ����� (ex. ���?) ���� �ܾ� �Է�(ex.apple)\n");

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

		printf("\n%s�� ����� �ϸ�??\n=>", arrKorDB[nItem]);
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
			printf("\n%s��(��) ����� %s! ����!\n",arrKorDB[nItem] ,arrEngDB[nItem] );
			nAwCount++;
		}
		else
		{
			printf("\nƲ�Ƚ��ϴ�. ������ %s�Դϴ�. \n",arrEngDB[nItem]);
		}
		nStartQuesNumber--;
	}
	if (nStartQuesNumber == 0)
	{
		for (i = 0; i < nQuesCount; i++)
		{			
			fScore = fScore + (100.00f / nQuesCount);
		}
		printf("\n\n%d������ %d������ ���߼̽��ϴ�. \n\n �ѽ��ھ� %.0f�� �Դϴ�.\n", nQuesCount, nAwCount, ceilf(fScore));

	}
	/*for (i = 0; i< MAX; i++)
	{
		printf("���ܾ� : %s \n", arrEngDB[i]);
		printf("�Ѵܾ� : %s \n", arrKorDB[i]);

	}*/
	printf("\n\n\n\n\n\n\n\n\n");
	printf("���� ���� \n\n\n");

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
//	printf("���� �ܾ�� ���� �ѱ� �ܾ �Է� (ex. Apple ���) \n");
//	printf("0�� �Է��ϸ� �Է� ����. \n");
//
//	while (1)
//	{
//		printf("���� �ܾ� �Է� (0�� �Է��ϸ� ����):");
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
//		printf("�ѱ� �ܾ� �Է� (0�� �Է��ϸ� ����):");
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
//	printf("�Է� ���� \n");
//
//	printf("����\n");
//	printf("�ѱ� �ܾ ����� (ex. ���?) ���� �ܾ� �Է�(ex.Apple)\n");
//	while (1)
//	{
//		printf("%s�� ����� �ϸ�??");
//		scanf_s("");
//
//	}
//
//	printf("exit");
//
//}