#pragma once
#include"Person.h"
#include"Classmate.h"
#include"Teammate.h"
#include"Friend.h"
#include"Relative.h"
#include"myhead.h"
#include<string>

void Input(int i);
void Edit_s(Temp p);
bool Judge(string x);
bool ReInput();
char* Copy(char*p , string a);
void PrintIt(int i);
void PrintName(int i);
bool SearchName(char *p);
Temp SearchName_s(char *p);
void Delete(char *p);
int* Birthmonth();
void HappyBirth();
bool IsLeapYear(int y);
int DaysOfMonth(int y, int m);
int DaysOfDate(int y, int m, int d);
bool JudgeFiveDay(int m, int d);
char* CaculateWeekDay(int y, int m, int d);
int count(int i);
void Create();
