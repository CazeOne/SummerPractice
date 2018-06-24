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
	if (n == 0)								//Проверка числа на ноль
	{
		printf("Zero");
		return 0;
	}
	if (n < 0)								//Проверка на наличие минуса в числе
	{
		printf("Minus ");
		n = n * (-1);
	}
	for (i = 0;n>0;i++)						
	{
		a = n;
		if (n % 100 < 10 || n % 100 > 19)	//Проверка на наличие в классе значений от 10 до 19
		{
			a = n % 10;
			q = a;
			n /= 10;
			a = n % 10;
			w = a;							//Если такового нет то вычисляем каждую цифру в классе
			n /= 10;
			a = n % 10;
			e = a;
			n /= 10;
			strcpy(str, v[e]);				//Копируем в строку полученное название соответствующей цифры разряда СОТЕН
			strcat(str, c[w]);				//Добавляем к строке полученный разряд ДЕСЯТКОВ
			strcat(str, z[q]);				//Добавляем к строке полученный разряд ЕДИНИЦ
			strcpy(stri[i], str);			//Сохраняем полученную строку в массив

		}
		else
		{
			a = n % 100;
			q = a - 10;
			n /= 100;
			a = n % 10;						//Если да, то вычисляем две последние цифры как одну и так же вычисляем сотни
			w = a;
			n /= 10;
			strcpy(str, v[w]);				//Добавляем к строке полученное название соответствующей цифры разряда СОТЕН
			strcat(str, x[q]);				//Добавляем к строке полученный результат
			strcpy(stri[i], str);			//Сохраняем полученную строку в массив
		}
	}
	if (stri[3][0] == NULL)					//Если соответствующий элемент МИЛЬЯРДОВ пуст то ничего не выводим и идём дальше
	{}
	else
	{
		printf("%sbillion ", stri[3]);		//В противном случае выводим строку из массива и дописываем название класса
	}
	if (stri[2][0] == NULL)					//Если соответствующий элемент МИЛЛИОНОВ пуст то ничего не выводим и идём дальше
	{}
	else
	{
		printf("%smillion ", stri[2]);		//В противном случае выводим строку из массива и дописываем название класса
	}
	if (stri[1][0] == NULL)					//Если соответствующий элемент ТЫСЯЧ пуст то ничего не выводим и идём дальше
	{}
	else
	{
		printf("%sthousand ", stri[1]);		//В противном случае выводим строку из массива и дописываем название класса
	}
	if (stri[0][0] == NULL)					//Если соответствующий элемент (1-999) пуст то ничего не выводим и идём дальше
	{}
	else
	{
		printf("%s", stri[0]);				//В противном случае выводим строку из массива
	}
}
