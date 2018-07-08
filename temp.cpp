#include "temp.h"
#include "myhead.h"
Temp::Temp()
{
    flag=0;
}

Temp::Temp(char *p, int a, int b, int c, char *d, char *q, char *r,int x)
{
    int i, j, k, l;
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
        for (l = 0;l < strlen(r);l++)
        {
            info[l] = r[l];
        }
        info[l] = '\0';
        birthyear = a; birthmonth = b;birthday = c;
        flag=x;
}

char* Temp::GetName()
{
    return name;
}

char* Temp::GetInfo()
{
    return info;
}

char* Temp::GetBirth()
{
    string y,m,d,s; char *p;
    y=to_string(birthyear);
    m=to_string(birthmonth);
    d=to_string(birthday);
    s=y+'/'+m+'/'+d;
    return Copy(p,s);
}

char* Temp::GetCall()
{
    return call;
}

char* Temp::GetEmail()
{
    return email;
}

int Temp::GetFlag()
{
    return flag;
}

int Temp::GetYear()
{
    return birthyear;
}

int Temp::GetMonth()
{
    return birthmonth;
}

int Temp::GetDay()
{
    return birthday;
}
