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

	printf("���� �ܾ�� ���� �ѱ� �ܾ �Է� (ex. Apple ���) \n");
	printf("0�� �Է��ϸ� �Է� ����. \n");
	while (nQuit != 0)
	{
		printf("���� �ܾ� �Է� (0�� �Է��ϸ� ����):");
		scanf_s("%s", arrEng, sizeof(arrEng));

		//printf("�ѱ� �ܾ� �Է� (0�� �Է��ϸ� ����):");
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
	printf("�Է� ����\n");
	
}
