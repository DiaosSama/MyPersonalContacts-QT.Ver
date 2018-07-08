#ifndef TEMP_H
#define TEMP_H


class Temp
{
    char name[30];
    int birthyear, birthmonth, birthday;
    char call[30];
    char email[30];
    char info[30];
    int flag; //用于search时判断为哪种类型的联系人
public:
    Temp();
    Temp(char *p, int a, int b, int c, char *d, char *q, char *r,int x=0);
    char* GetName();
    char* GetInfo();
    char* GetBirth();
    int GetYear();
    int GetMonth();
    int GetDay();
    char* GetCall();
    char* GetEmail();
    int GetFlag();
};

#endif // TEMP_H
