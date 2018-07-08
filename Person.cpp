#include "Person.h"
#include<iostream>
#include<cstring>


Person::Person(char *p, int a, int b, int c, char *d, char *q)
{
	int i, j, k;
		for (i = 0;i < strlen(p);i++)
		{
			name[i] = p[i];
		}
		name[i] = '\0';
		for (j = 0;j < strlen(q);j++)
		{
			email[j] = q[j];
		}
		email[j] = '\0';
		for (k = 0;k < strlen(d);k++)
		{
			call[k] = d[k];
		}
		call[k] = '\0';
		birthyear = a; birthmonth = b;birthday = c;
}

Person::Person()
{
}

Person::~Person()
{
}
