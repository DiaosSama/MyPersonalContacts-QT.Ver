#pragma once
#include<cstring>
using namespace std;
class Person
{
protected:
	char name[30];
	int birthyear, birthmonth, birthday;
	char call[30];
	char email[30];
public:
	Person(char *p, int a, int b, int c, char *d, char *q);
	Person();
	virtual ~Person();
	virtual void Write() = 0;
	virtual void Print() = 0;
};

