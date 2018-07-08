#pragma once
#include "Person.h"
#include"myhead.h"
class Teammate :
	public Person
{
private:
	char company[30];
public:
	Teammate(char *p, int a, int b, int c, char *d, char *q, char *r);
	Teammate();
	~Teammate();
	void Write();
	void Print();
    char* GetName();
    char* GetCompany();
    char* GetBirth();
    char* GetCall();
    char* GetEmail();
	friend void PrintIt(int i);
	friend bool SearchName(char *p);
	friend void Delete(char *p);
    friend void Edit_s(Temp p);
	friend void PrintName(int i);
    friend int* Birthmonth();
	friend void HappyBirth();
    friend Temp SearchName_s(char *p);
    friend int count(int i);
};

