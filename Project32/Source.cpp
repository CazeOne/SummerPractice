#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>				

const char * z[] = { "","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine " };
const char * x[] = { "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ","Seventeen ","Eighteen ","Nineteen " };
const char * c[] = { "","","Twenty ","Thirty ","Forty ","Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };
const char * v[] = { "","One hundred ","Two hundred ","Three hundred ","Four hundred ","Five hundred ","Six hundred ","Seven hundred ","Eight hundred ","Nine hundred " };

int Perevod(long long int n)
{
	long long int q = 0, w = 0, e = 0, i = 0, a = 0;
	char  str[100];
	char  stri[100][100];
	char srav[] = { "" };
	stri[0][0] = { NULL };
	stri[1][0] = { NULL };
	stri[2][0] = { NULL };
	stri[3][0] = { NULL };	
	if (n == 0)								//�������� ����� �� ����
	{
		printf("Zero");
		return 0;
	}
	if (n < 0)								//�������� �� ������� ������ � �����
	{
		printf("Minus ");
		n = n * (-1);
	}
	for (i = 0;n>0;i++)						
	{
		a = n;
		if (n % 100 < 10 || n % 100 > 19)	//�������� �� ������� � ������ �������� �� 10 �� 19
		{
			a = n % 10;
			q = a;
			n /= 10;
			a = n % 10;
			w = a;							//���� �������� ��� �� ��������� ������ ����� � ������
			n /= 10;
			a = n % 10;
			e = a;
			n /= 10;
			strcpy(str, v[e]);				//�������� � ������ ���������� �������� ��������������� ����� ������� �����
			strcat(str, c[w]);				//��������� � ������ ���������� ������ ��������
			strcat(str, z[q]);				//��������� � ������ ���������� ������ ������
			strcpy(stri[i], str);			//��������� ���������� ������ � ������

		}
		else
		{
			a = n % 100;
			q = a - 10;
			n /= 100;
			a = n % 10;						//���� ��, �� ��������� ��� ��������� ����� ��� ���� � ��� �� ��������� �����
			w = a;
			n /= 10;
			strcpy(str, v[w]);				//��������� � ������ ���������� �������� ��������������� ����� ������� �����
			strcat(str, x[q]);				//��������� � ������ ���������� ���������
			strcpy(stri[i], str);			//��������� ���������� ������ � ������
		}
	}
	if (stri[3][0] == NULL)					//���� ��������������� ������� ��������� ���� �� ������ �� ������� � ��� ������
	{}
	else
	{
		printf("%sbillion ", stri[3]);		//� ��������� ������ ������� ������ �� ������� � ���������� �������� ������
	}
	if (stri[2][0] == NULL)					//���� ��������������� ������� ��������� ���� �� ������ �� ������� � ��� ������
	{}
	else
	{
		printf("%smillion ", stri[2]);		//� ��������� ������ ������� ������ �� ������� � ���������� �������� ������
	}
	if (stri[1][0] == NULL)					//���� ��������������� ������� ����� ���� �� ������ �� ������� � ��� ������
	{}
	else
	{
		printf("%sthousand ", stri[1]);		//� ��������� ������ ������� ������ �� ������� � ���������� �������� ������
	}
	if (stri[0][0] == NULL)					//���� ��������������� ������� (1-999) ���� �� ������ �� ������� � ��� ������
	{}
	else
	{
		printf("%s", stri[0]);				//� ��������� ������ ������� ������ �� �������
	}
}
