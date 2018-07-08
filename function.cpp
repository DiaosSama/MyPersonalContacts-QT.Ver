#include"Function.h"
#include"mainwindow.h"
#include<QtWidgets>
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;

//判断输入是否合法(串大小小于30)
bool Judge(string x)
{
    if (x.size() > 30) { cout << "The length of string is overflow!(looger than 30)" << endl; return false; }
    else return true;
}

//提供重新输入选项
bool ReInput()
{
    char a;
    cout << "Do you want to input again?(Y or N)"; cin >> a;
    if (a == 'Y') return true;
    else return false;
}

//将string类转化为char*
char* Copy(char *p, string a)
{
    int i;
    p = new char[a.size()];
    for (i = 0;i < a.size();i++)
    {
        p[i] = a[i];
    }
    p[i] = '\0';
    return p;
}

//联系人信息输入功能(i为标识符,表明输入为哪一类联系人)
void Input(int i)
{
    if (i == 1)
    {
        char *p = NULL, *q = NULL, *r = NULL, *d = NULL;
        string x, y, z, w;
        int a, b, c;
A:		cout << "Please input your classmate's name: "; cin >> x;
        if (!Judge(x))
        {
            if (ReInput()) goto A;
            else return;
        }
        p = Copy(p, x);
B:		cout<< "Please input your classmate's email: "; cin >> y;
        if (!Judge(y))
        {
            if (ReInput()) goto B;
            else return;
        }
        q = Copy(q, y);
C:		cout << "Please input your classmate's school: "; cin >> z;
        if (!Judge(z))
        {
            if (ReInput()) goto C;
            else return;
        }
        r = Copy(r, z);
        cout << "Please input your classmate's birthyear: "; cin >> a;
        cout << "Please input your classmate's birthmonth: "; cin >> b;
        cout << "Please input your classmate's birthday: "; cin >> c;
M:		cout << "Please input your classmate's phone number: "; cin >> w;
        if (!Judge(w))
        {
            if (ReInput()) goto M;
            else return;
        }
        d = Copy(d, w);
        Classmate a1(p, a, b, c, d, q, r);
        a1.Write();
    }
    if (i == 2)
    {
        char *p = NULL, *q = NULL, *r = NULL, *d = NULL;
        string x, y, z, w;
        int a, b, c;
D:		cout << "Please input your teammate's name: "; cin >> x;
        if (!Judge(x))
        {
            if (ReInput()) goto D;
            else return;
        }
        p = Copy(p, x);
E:		cout << "Please input your teammate's email: "; cin >> y;
        if (!Judge(y))
        {
            if (ReInput()) goto E;
            else return;
        }
        q = Copy(q, y);
F:		cout << "Please input your teammate's company: "; cin >> z;
        if (!Judge(z))
        {
            if (ReInput()) goto F;
            else return;
        }
        r = Copy(r, z);
        cout << "Please input your teammate's birthyear: "; cin >> a;
        cout << "Please input your teammate's birthmonth: "; cin >> b;
        cout << "Please input your teammate's birthday: "; cin >> c;
N:		cout << "Please input your teammate's phone number: "; cin >> w;
        if (!Judge(w))
        {
            if (ReInput()) goto N;
            else return;
        }
        d = Copy(d, w);
        Teammate a1(p, a, b, c, d, q, r);
        a1.Write();
    }
    if (i == 3)
    {
        char *p = NULL, *q = NULL, *r = NULL, *d = NULL;
        string x, y, z, w;
        int a, b, c;
    G:		cout << "Please input your friend's name: "; cin >> x;
        if (!Judge(x))
        {
            if (ReInput()) goto G;
            else return;
        }
        p = Copy(p, x);
    H:		cout << "Please input your friend's email: "; cin >> y;
        if (!Judge(y))
        {
            if (ReInput()) goto H;
            else return;
        }
        q = Copy(q, y);
    I:		cout << "Please input your friend's meeting place: "; cin >> z;
        if (!Judge(z))
        {
            if (ReInput()) goto I;
            else return;
        }
        r = Copy(r, z);
        cout << "Please input your friend's birthyear: "; cin >> a;
        cout << "Please input your friend's birthmonth: "; cin >> b;
        cout << "Please input your friend's birthday: "; cin >> c;
O:		cout << "Please input your friend's phone number: "; cin >> w;
        if (!Judge(w))
        {
            if (ReInput()) goto O;
            else return;
        }
        d = Copy(d, w);
        Friend a1(p, a, b, c, d, q, r);
        a1.Write();
    }
    if (i == 4)
    {
        char *p = NULL, *q = NULL, *r = NULL, *d = NULL;
        string x, y, z, w;
        int a, b, c;
    J:		cout << "Please input your relative's name: "; cin >> x;
        if (!Judge(x))
        {
            if (ReInput()) goto J;
            else return;
        }
        p = Copy(p, x);
    K:		cout << "Please input your relative's email: "; cin >> y;
        if (!Judge(y))
        {
            if (ReInput()) goto K;
            else return;
        }
        q = Copy(q, y);
    L:		cout << "Please input your relative's generation: "; cin >> z;
        if (!Judge(z))
        {
            if (ReInput()) goto L;
            else return;
        }
        r = Copy(r, z);
        cout << "Please input your relative's birthyear: "; cin >> a;
        cout << "Please input your relative's birthmonth: "; cin >> b;
        cout << "Please input your relative's birthday: "; cin >> c;
P:		cout << "Please input your relative's phone number: "; cin >> w;
        if (!Judge(w))
        {
            if (ReInput()) goto P;
            else return;
        }
        d = Copy(d, w);
        Relative a1(p, a, b, c, d, q, r);
        a1.Write();
    }
    if (i == 0) { return; }
}

//联系人信息编辑功能
void Edit_s(Temp p)
{
    fstream instuf, outstuf;
    bool work = false;
    string x, y, z;
    char *x1 = NULL, *y1 = NULL, *z1 = NULL;
    Classmate a; Teammate b; Friend c; Relative d;
    instuf.open("AddressBook1.txt", ios::in);
    outstuf.open("Temp.txt", ios::out);
    if (!instuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    if (!outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (instuf >> a.name >> a.schoolname >> a.birthyear >> a.birthmonth >> a.birthday >> a.call >> a.email)
    {
        if (strcmp(a.name, p.GetName()) != 0)
        {
            outstuf << a.name << ' ' << a.schoolname << ' ' << a.birthyear << ' ' << a.birthmonth << ' ' << a.birthday << ' ' << a.call << ' ' << a.email << '\n';
        }
        else
        {
            outstuf << p.GetName() << ' ' << p.GetInfo() << ' ' << p.GetYear() << ' ' << p.GetMonth() << ' ' << p.GetDay() << ' ' << p.GetCall() << ' ' << p.GetEmail() << '\n';
            work = true;
        }
    }
    //重新写入
    instuf.close(); outstuf.close();
    instuf.open("AddressBook1.txt", ios::out);
    outstuf.open("Temp.txt", ios::in);
    if (!instuf || !outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (outstuf >> a.name >> a.schoolname >> a.birthyear >> a.birthmonth >> a.birthday >> a.call >> a.email)
    {
        instuf << a.name << ' ' << a.schoolname << ' ' << a.birthyear << ' ' << a.birthmonth << ' ' << a.birthday << ' ' << a.call << ' ' << a.email << '\n';
    }
    instuf.close(); outstuf.close();
    if (work) { cout << "The item was already changed." << endl; return; }

    outstuf.open("Temp.txt", ios::out);
    instuf.open("AddressBook2.txt", ios::in);
    if (!instuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    if (!outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (instuf >> b.name >> b.company >> b.birthyear >> b.birthmonth >> b.birthday >> b.call >> b.email)
    {
        if (strcmp(b.name, p.GetName()) != 0)
        {
            outstuf << b.name << ' ' << b.company << ' ' << b.birthyear << ' ' << b.birthmonth << ' ' << b.birthday << ' ' << b.call << ' ' << b.email << '\n';
        }
        else
        {
            outstuf << p.GetName() << ' ' << p.GetInfo() << ' ' << p.GetYear() << ' ' << p.GetMonth() << ' ' << p.GetDay() << ' ' << p.GetCall() << ' ' << p.GetEmail() << '\n';
            work = true;
        }
    }
    instuf.close(); outstuf.close();
    instuf.open("AddressBook2.txt", ios::out);
    outstuf.open("Temp.txt", ios::in);
    if (!instuf || !outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (outstuf >> b.name >> b.company >> b.birthyear >> b.birthmonth >> b.birthday >> b.call >> b.email)
    {
        instuf << b.name << ' ' << b.company << ' ' << b.birthyear << ' ' << b.birthmonth << ' ' << b.birthday << ' ' << b.call << ' ' << b.email << '\n';
    }
    instuf.close(); outstuf.close();
    if (work) { cout << "The item was already changed." << endl; return; }

    outstuf.open("Temp.txt", ios::out);
    instuf.open("AddressBook3.txt", ios::in);
    if (!instuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    if (!outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (instuf >> c.name >> c.place >> c.birthyear >> c.birthmonth >> c.birthday >> c.call >> c.email)
    {
        if (strcmp(c.name, p.GetName()) != 0)
        {
            outstuf << c.name << ' ' << c.place << ' ' << c.birthyear << ' ' << c.birthmonth << ' ' << c.birthday << ' ' << c.call << ' ' << c.email << '\n';
        }
        else
        {
            outstuf << p.GetName() << ' ' << p.GetInfo() << ' ' << p.GetYear() << ' ' << p.GetMonth() << ' ' << p.GetDay() << ' ' << p.GetCall() << ' ' << p.GetEmail() << '\n';
            work = true;
        }
    }
    instuf.close(); outstuf.close();
    instuf.open("AddressBook3.txt", ios::out);
    outstuf.open("Temp.txt", ios::in);
    if (!instuf || !outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (outstuf >> c.name >> c.place >> c.birthyear >> c.birthmonth >> c.birthday >> c.call >> c.email)
    {
        instuf << c.name << ' ' << c.place << ' ' << c.birthyear << ' ' << c.birthmonth << ' ' << c.birthday << ' ' << c.call << ' ' << c.email << '\n';
    }
    instuf.close(); outstuf.close();
    if (work) { cout << "The item was already changed." << endl; return; }

    outstuf.open("Temp.txt", ios::out);
    instuf.open("AddressBook4.txt", ios::in);
    if (!instuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    if (!outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (instuf >> d.name >> d.generation >> d.birthyear >> d.birthmonth >> d.birthday >> d.call >> d.email)
    {
        if (strcmp(d.name, p.GetName()) != 0)
        {
            outstuf << d.name << ' ' << d.generation << ' ' << d.birthyear << ' ' << d.birthmonth << ' ' << d.birthday << ' ' << d.call << ' ' << d.email << '\n';
        }
        else
        {
            outstuf << p.GetName() << ' ' << p.GetInfo() << ' ' << p.GetYear() << ' ' << p.GetMonth() << ' ' << p.GetDay() << ' ' << p.GetCall() << ' ' << p.GetEmail() << '\n';
            work = true;
        }
    }
    instuf.close(); outstuf.close();
    instuf.open("AddressBook4.txt", ios::out);
    outstuf.open("Temp.txt", ios::in);
    if (!instuf || !outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (outstuf >> d.name >> d.generation >> d.birthyear >> d.birthmonth >> d.birthday >> d.call >> d.email)
    {
        instuf << d.name << ' ' << d.generation << ' ' << d.birthyear << ' ' << d.birthmonth << ' ' << d.birthday << ' ' << d.call << ' ' << d.email << '\n';
    }
    instuf.close(); outstuf.close();
    if (work) { cout << "The item was already changed." << endl; return; }
}

//联系人信息输出到屏幕
void PrintIt(int i)
{
    if (i == 1)
    {
        fstream stuf;
        Classmate a; Teammate b; Friend c; Relative d;
        stuf.open("AddressBook1.txt", ios::in);
        stuf.seekg(ios::beg);
        if (!stuf)
        {
            cerr << "File could not be open!" << endl;
            abort();
        }
        while (stuf >> a.name >> a.schoolname >> a.birthyear >> a.birthmonth >> a.birthday >> a.call >> a.email)
        {
           a.Print();
        }
        stuf.close();
        stuf.open("AddressBook2.txt", ios::in);
        stuf.seekg(ios::beg);
        if (!stuf)
        {
            cerr << "File could not be open!" << endl;
            abort();
        }
        while (stuf >> b.name >> b.company >> b.birthyear >> b.birthmonth >> b.birthday >> b.call >> b.email)
        {
            b.Print();
        }
        stuf.close();
        stuf.open("AddressBook3.txt", ios::in);
        stuf.seekg(ios::beg);
        if (!stuf)
        {
            cerr << "File could not be open!" << endl;
            abort();
        }
        while (stuf >> c.name >> c.place >> c.birthyear >> c.birthmonth >> c.birthday >> c.call >> c.email)
        {
            c.Print();
        }
        stuf.close();
        stuf.open("AddressBook4.txt", ios::in);
        stuf.seekg(ios::beg);
        if (!stuf)
        {
            cerr << "File could not be open!" << endl;
            abort();
        }
        while (stuf >> d.name >> d.generation >> d.birthyear >> d.birthmonth >> d.birthday >> d.call >> d.email)
        {
            d.Print();
        }
        stuf.close();
    }
    if (i == 2)
    {
        fstream stuf;
        Classmate a;
        stuf.open("AddressBook1.txt", ios::in);
        stuf.seekg(ios::beg);
        if (!stuf)
        {
            cerr << "File could not be open!" << endl;
            abort();
        }
        while (stuf >> a.name >> a.schoolname >> a.birthyear >> a.birthmonth >> a.birthday >> a.call >> a.email)
        {
            a.Print();
        }
        stuf.close();
    }
    if (i == 3)
    {
        fstream stuf;
        Teammate b;
        stuf.open("AddressBook2.txt", ios::in);
        stuf.seekg(ios::beg);
        if (!stuf)
        {
            cerr << "File could not be open!" << endl;
            abort();
        }
        while (stuf >> b.name >> b.company >> b.birthyear >> b.birthmonth >> b.birthday >> b.call >> b.email)
        {
            b.Print();
        }
        stuf.close();
    }
    if (i == 4)
    {
        fstream stuf;
        Friend c;
        stuf.open("AddressBook3.txt", ios::in);
        stuf.seekg(ios::beg);
        if (!stuf)
        {
            cerr << "File could not be open!" << endl;
            abort();
        }
        while (stuf >> c.name >> c.place >> c.birthyear >> c.birthmonth >> c.birthday >> c.call >> c.email)
        {
            c.Print();
        }
        stuf.close();
    }
    if (i == 5)
    {
        fstream stuf;
        Relative d;
        stuf.open("AddressBook4.txt", ios::in);
        stuf.seekg(ios::beg);
        if (!stuf)
        {
            cerr << "File could not be open!" << endl;
            abort();
        }
        while (stuf >> d.name >> d.generation >> d.birthyear >> d.birthmonth >> d.birthday >> d.call >> d.email)
        {
            d.Print();
        }
        stuf.close();
    }
    if (i == 0) { return; }
}

//按名字顺序输出联系人信息
void PrintName(int i)
{
    if (i == 1)
    {
        int size = 0;
        fstream instuf("AddressBook1.txt", ios::in);
        Classmate a; Teammate b; Friend c; Relative d;
        while (instuf >> a.name >> a.schoolname >> a.birthyear >> a.birthmonth >> a.birthday >> a.call >> a.email) { size++; }
        instuf.close();
        instuf.open("AddressBook2.txt", ios::in);
        while (instuf >> b.name >> b.company >> b.birthyear >> b.birthmonth >> b.birthday >> b.call >> b.email) { size++; }
        instuf.close();
        instuf.open("AddressBook3.txt", ios::in);
        while (instuf >> c.name >> c.place >> c.birthyear >> c.birthmonth >> c.birthday >> c.call >> c.email) { size++; }
        instuf.close();
        instuf.open("AddressBook4.txt", ios::in);
        while (instuf >> d.name >> d.generation >> d.birthyear >> d.birthmonth >> d.birthday >> d.call >> d.email) { size++; }
        instuf.close();
        char **p; int now = 0;
        p = new char *[size];
        for (int j = 0;j < size;j++)
        {
            p[j] = new char[30];
        }
        instuf.open("AddressBook1.txt", ios::in);
        while (instuf >> a.name >> a.schoolname >> a.birthyear >> a.birthmonth >> a.birthday >> a.call >> a.email)
        {
            strcpy_s(p[now], strlen(a.name) + 1, a.name);
            now++;
        }
        instuf.close();
        instuf.open("AddressBook2.txt", ios::in);
        while (instuf >> b.name >> b.company >> b.birthyear >> b.birthmonth >> b.birthday >> b.call >> b.email)
        {
            strcpy_s(p[now], strlen(b.name) + 1, b.name);
            now++;
        }
        instuf.close();
        instuf.open("AddressBook3.txt", ios::in);
        while (instuf >> c.name >> c.place >> c.birthyear >> c.birthmonth >> c.birthday >> c.call >> c.email)
        {
            strcpy_s(p[now], strlen(c.name) + 1, c.name);
            now++;
        }
        instuf.close();
        instuf.open("AddressBook4.txt", ios::in);
        while (instuf >> d.name >> d.generation >> d.birthyear >> d.birthmonth >> d.birthday >> d.call >> d.email)
        {
            strcpy_s(p[now], strlen(d.name) + 1, d.name);
            now++;
        }
        instuf.close();
        char *temp = new char[30]; int work;
        for (int j = 1;j < size;j++)
        {
            work = 1;
            for (int k = 0;k < size-j;k++)
            {
                if (strcmp(p[k], p[k + 1]) > 0)
                {
                    strcpy_s(temp, strlen(p[k]) + 1, p[k]);
                    strcpy_s(p[k], strlen(p[k + 1])+1, p[k + 1]);
                    strcpy_s(p[k + 1], strlen(temp)+1, temp);
                    work = 0;
                }
            }
            if (work) break;
        }
        for (int j = 0;j < size;j++)
        {
            SearchName(p[j]);
        }
    }
}

//按名字搜索联系人(Qt版本)
Temp SearchName_s(char *p)
{
    fstream stuf;char an[30],as[30],ac[30],ae[30]; int y,m,d;
    Temp y1;
    stuf.open("AddressBook1.txt", ios::in);
    stuf.seekg(ios::beg);
    if (!stuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        if (strcmp(an, p) == 0)
        {
            Temp x(an,y,m,d,ac,ae,as,1);
            return x;
        }
    }
    stuf.close();
    stuf.open("AddressBook2.txt", ios::in);
    stuf.seekg(ios::beg);
    if (!stuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        if (strcmp(an, p) == 0)
        {
            Temp x(an,y,m,d,ac,ae,as,2);
            return x;
        }
    }
    stuf.close();
    stuf.open("AddressBook3.txt", ios::in);
    stuf.seekg(ios::beg);
    if (!stuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        if (strcmp(an, p) == 0)
        {
            Temp x(an,y,m,d,ac,ae,as,3);
            return x;
        }
    }
    stuf.close();
    stuf.open("AddressBook4.txt", ios::in);
    stuf.seekg(ios::beg);
    if (!stuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        if (strcmp(an, p) == 0)
        {
            Temp x(an,y,m,d,ac,ae,as,4);
            return x;
        }
    }
    stuf.close();
    cout << "Cannot find this person !" << endl;
    return y1;
}

//按名字搜索联系人(控制台版本)
bool SearchName(char *p)
{
        fstream stuf;
        Classmate a; Teammate b; Friend c; Relative d;
        stuf.open("AddressBook1.txt", ios::in);
        stuf.seekg(ios::beg);
        if (!stuf)
        {
                cerr << "File could not be open!" << endl;
                abort();
        }
        while (stuf >> a.name >> a.schoolname >> a.birthyear >> a.birthmonth >> a.birthday >> a.call >> a.email)
        {
                if (strcmp(a.name, p) == 0)
                {
                        a.Print();
                        return true;
                }
        }
        stuf.close();
        stuf.open("AddressBook2.txt", ios::in);
        stuf.seekg(ios::beg);
        if (!stuf)
        {
                cerr << "File could not be open!" << endl;
                abort();
        }
        while (stuf >> b.name >> b.company >> b.birthyear >> b.birthmonth >> b.birthday >> b.call >> b.email)
        {
                if (strcmp(b.name, p) == 0)
                {
                        b.Print();
                        return true;
                }
        }
        stuf.close();
        stuf.open("AddressBook3.txt", ios::in);
        stuf.seekg(ios::beg);
        if (!stuf)
        {
                cerr << "File could not be open!" << endl;
                abort();
        }
        while (stuf >> c.name >> c.place >> c.birthyear >> c.birthmonth >> c.birthday >> c.call >> c.email)
        {
                if (strcmp(c.name, p) == 0)
                {
                        c.Print();
                        return true;
                }
        }
        stuf.close();
        stuf.open("AddressBook4.txt", ios::in);
        stuf.seekg(ios::beg);
        if (!stuf)
        {
                cerr << "File could not be open!" << endl;
                abort();
        }
        while (stuf >> d.name >> d.generation >> d.birthyear >> d.birthmonth >> d.birthday >> d.call >> d.email)
        {
                if (strcmp(d.name, p) == 0)
                {
                        d.Print();
                        return true;
                }
        }
        stuf.close();
        cout << "Cannot find this person !" << endl;
        return false;
}

//删除联系人(参数为要删除的联系人名字)
void Delete(char *p)
{
    fstream instuf, outstuf;
    bool work = false;
    Classmate a; Teammate b; Friend c; Relative d;
    outstuf.open("Temp.txt", ios::out);
    instuf.open("AddressBook1.txt", ios::in);
    if (!instuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    if (!outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (instuf >> a.name >> a.schoolname >> a.birthyear >> a.birthmonth >> a.birthday >> a.call >> a.email)
    {
        if (strcmp(a.name, p) != 0)
        {
            outstuf << a.name << ' ' << a.schoolname << ' ' << a.birthyear << ' ' << a.birthmonth << ' ' << a.birthday << ' ' << a.call << ' ' << a.email << '\n';
        }
        else { work = true; continue; }
    }
    instuf.close(); outstuf.close();
    instuf.open("AddressBook1.txt", ios::out);
    outstuf.open("Temp.txt", ios::in);
    if (!instuf || !outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (outstuf >> a.name >> a.schoolname >> a.birthyear >> a.birthmonth >> a.birthday >> a.call >> a.email)
    {
        instuf << a.name << ' ' << a.schoolname << ' ' << a.birthyear << ' ' << a.birthmonth << ' ' << a.birthday << ' ' << a.call << ' ' << a.email << '\n';
    }
    instuf.close(); outstuf.close();
    if (work) { cout << "The item was already deleted." << endl; return; }

    outstuf.open("Temp.txt", ios::out);
    instuf.open("AddressBook2.txt", ios::in);
    if (!instuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    if (!outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (instuf >> b.name >> b.company >> b.birthyear >> b.birthmonth >> b.birthday >> b.call >> b.email)
    {
        if (strcmp(b.name, p) != 0)
        {
            outstuf << b.name << ' ' << b.company << ' ' << b.birthyear << ' ' << b.birthmonth << ' ' << b.birthday << ' ' << b.call << ' ' << b.email << '\n';
        }
        else { work = true; continue; }
    }
    instuf.close(); outstuf.close();
    instuf.open("AddressBook2.txt", ios::out);
    outstuf.open("Temp.txt", ios::in);
    if (!instuf || !outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (outstuf >> b.name >> b.company >> b.birthyear >> b.birthmonth >> b.birthday >> b.call >> b.email)
    {
        instuf << b.name << ' ' << b.company << ' ' << b.birthyear << ' ' << b.birthmonth << ' ' << b.birthday << ' ' << b.call << ' ' << b.email << '\n';
    }
    instuf.close(); outstuf.close();
    if (work) { cout << "The item was already deleted." << endl; return; }

    outstuf.open("Temp.txt", ios::out);
    instuf.open("AddressBook3.txt", ios::in);
    if (!instuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    if (!outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (instuf >> c.name >> c.place >> c.birthyear >> c.birthmonth >> c.birthday >> c.call >> c.email)
    {
        if (strcmp(b.name, p) != 0)
        {
            outstuf << c.name << ' ' << c.place << ' ' << c.birthyear << ' ' << c.birthmonth << ' ' << c.birthday << ' ' << c.call << ' ' << c.email << '\n';
        }
        else { work = true; continue; }
    }
    instuf.close(); outstuf.close();
    instuf.open("AddressBook3.txt", ios::out);
    outstuf.open("Temp.txt", ios::in);
    if (!instuf || !outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (outstuf >> c.name >> c.place >> c.birthyear >> c.birthmonth >> c.birthday >> c.call >> c.email)
    {
        instuf << c.name << ' ' << c.place << ' ' << c.birthyear << ' ' << c.birthmonth << ' ' << c.birthday << ' ' << c.call << ' ' << c.email << '\n';
    }
    instuf.close(); outstuf.close();
    if (work) { cout << "The item was already deleted." << endl; return; }

    outstuf.open("Temp.txt", ios::out);
    instuf.open("AddressBook4.txt", ios::in);
    if (!instuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    if (!outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (instuf >> d.name >> d.generation >> d.birthyear >> d.birthmonth >> d.birthday >> d.call >> d.email)
    {
        if (strcmp(b.name, p) != 0)
        {
            outstuf << d.name << ' ' << d.generation << ' ' << d.birthyear << ' ' << d.birthmonth << ' ' << d.birthday << ' ' << d.call << ' ' << d.email << '\n';
        }
        else { work = true; continue; }
    }
    instuf.close(); outstuf.close();
    instuf.open("AddressBook4.txt", ios::out);
    outstuf.open("Temp.txt", ios::in);
    if (!instuf || !outstuf)
    {
        cerr << "Sorry. The application crushed!" << endl;
        abort();
    }
    while (outstuf >> d.name >> d.generation >> d.birthyear >> d.birthmonth >> d.birthday >> d.call >> d.email)
    {
        instuf << d.name << ' ' << d.generation << ' ' << d.birthyear << ' ' << d.birthmonth << ' ' << d.birthday << ' ' << d.call << ' ' << d.email << '\n';
    }
    instuf.close(); outstuf.close();
    if (work) { cout << "The item was already deleted." << endl; return; }
}

//统计各月份生日人数
int* Birthmonth()
{
    int *month=new int[13];
    for (int i = 1;i < 13;i++)
    {
        month[i] = 0;
    }
    fstream instuf("AddressBook1.txt", ios::in);
    Classmate a; Teammate b; Friend c; Relative d;
    while (instuf >> a.name >> a.schoolname >> a.birthyear >> a.birthmonth >> a.birthday >> a.call >> a.email)
    {
        month[a.birthmonth]++;
    }
    instuf.close();
    instuf.open("AddressBook2.txt", ios::in);
    while (instuf >> b.name >> b.company >> b.birthyear >> b.birthmonth >> b.birthday >> b.call >> b.email)
    {
        month[b.birthmonth]++;
    }
    instuf.close();
    instuf.open("AddressBook3.txt", ios::in);
    while (instuf >> c.name >> c.place >> c.birthyear >> c.birthmonth >> c.birthday >> c.call >> c.email)
    {
        month[c.birthmonth]++;
    }
    instuf.close();
    instuf.open("AddressBook4.txt", ios::in);
    while (instuf >> d.name >> d.generation >> d.birthyear >> d.birthmonth >> d.birthday >> d.call >> d.email)
    {
        month[d.birthmonth]++;
    }
    instuf.close();
    return month;
}

//打印将来五天内生日的联系人信息
void HappyBirth()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    Classmate a; Teammate b; Friend c; Relative d;
    fstream stuf; int work = 0;
    stuf.open("AddressBook1.txt", ios::in);
    if (!stuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    while (stuf >> a.name >> a.schoolname >> a.birthyear >> a.birthmonth >> a.birthday >> a.call >> a.email)
    {
        if (JudgeFiveDay(a.birthmonth, a.birthday))
        {
            a.Print(); work = 1;
        }
    }
    stuf.close();
    stuf.open("AddressBook2.txt", ios::in);
    if (!stuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    while (stuf >> b.name >> b.company >> b.birthyear >> b.birthmonth >> b.birthday >> b.call >> b.email)
    {
        if (JudgeFiveDay(b.birthmonth, b.birthday))
        {
            b.Print(); work = 1;
        }
    }
    stuf.close();
    stuf.open("AddressBook3.txt", ios::in);
    if (!stuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    while (stuf >> c.name >> c.place >> c.birthyear >> c.birthmonth >> c.birthday >> c.call >> c.email)
    {
        if (JudgeFiveDay(c.birthmonth, c.birthday))
        {
            c.Print(); work = 1;
        }
    }
    stuf.close();
    stuf.open("AddressBook4.txt", ios::in);
    if (!stuf)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    while (stuf >> d.name >> d.generation >> d.birthyear >> d.birthmonth >> d.birthday >> d.call >> d.email)
    {
        if (JudgeFiveDay(d.birthmonth, d.birthday))
        {
            d.Print(); work = 1;
        }
    }
    stuf.close();
    if (!work) { cout << "没有人在将来的五天内生日！" << endl; }
}

//判断是否为闰年
bool IsLeapYear(int y)
{
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

//返还某年某月的天数
int DaysOfMonth(int y, int m)
{
    int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (m != 2)
        return day[m - 1];
    else
        return 28 + IsLeapYear(y);
}

//返回从公元一年至现在的天数
int DaysOfDate(int y,int m,int d)
{
    int days = d;
    for (int j = 1;j<y;j++)
        days += 365 + IsLeapYear(j);
    for (int k = 1;k<m;k++)
        days += DaysOfMonth(y, k);
    return days;
}

//判断某月某日距现在的天数是否在五天之内
bool JudgeFiveDay(int m, int d)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int dday, work = 0;
    if (m >= 1 + ltm->tm_mon)
    {
        dday = DaysOfDate(1900 + ltm->tm_year, m, d) - DaysOfDate(1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
        if (dday <= 5 && dday >= 0)
        {
            work = 1; CaculateWeekDay(1900 + ltm->tm_year, m, d);
        }
    }
    else
    {
        dday = DaysOfDate(1901 + ltm->tm_year, m, d) - DaysOfDate(1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
        if (dday <= 5 && dday >= 0)
        {
            work = 1; CaculateWeekDay(1901 + ltm->tm_year, m, d);
        }
    }
    if (work) return true;
    else return false;
}

//判断某年某月某日为星期几
char* CaculateWeekDay(int y, int m, int d)
{
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    int iWeek = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    switch (iWeek)
    {
    case 0: return "Monday"; break;
    case 1: return "Tuesday"; break;
    case 2: return "Wednesday"; break;
    case 3: return "Thursday"; break;
    case 4: return "Friday"; break;
    case 5: return "Saturday"; break;
    case 6: return "Sunday"; break;
    }
}

int count(int i)
{
    if(i==0)
    {
        int size = 0;
        fstream instuf("AddressBook1.txt", ios::in);
        Classmate a; Teammate b; Friend c; Relative d;
        while (instuf >> a.name >> a.schoolname >> a.birthyear >> a.birthmonth >> a.birthday >> a.call >> a.email) { size++; }
        instuf.close();
        instuf.open("AddressBook2.txt", ios::in);
        while (instuf >> b.name >> b.company >> b.birthyear >> b.birthmonth >> b.birthday >> b.call >> b.email) { size++; }
        instuf.close();
        instuf.open("AddressBook3.txt", ios::in);
        while (instuf >> c.name >> c.place >> c.birthyear >> c.birthmonth >> c.birthday >> c.call >> c.email) { size++; }
        instuf.close();
        instuf.open("AddressBook4.txt", ios::in);
        while (instuf >> d.name >> d.generation >> d.birthyear >> d.birthmonth >> d.birthday >> d.call >> d.email) { size++; }
        instuf.close();
        return size;
    }
    if(i==1)
    {
        int size = 0;
        fstream instuf("AddressBook1.txt", ios::in);
        Classmate a;
        while (instuf >> a.name >> a.schoolname >> a.birthyear >> a.birthmonth >> a.birthday >> a.call >> a.email) { size++; }
        instuf.close();
        return size;
    }
    if(i==2)
    {
        int size=0;
        fstream instuf;
        Teammate b;
        instuf.open("AddressBook2.txt", ios::in);
        while (instuf >> b.name >> b.company >> b.birthyear >> b.birthmonth >> b.birthday >> b.call >> b.email) { size++; }
        instuf.close();
        return size;
    }
    if(i==3)
    {
        int size=0;
        fstream instuf;
        Friend c;
        instuf.open("AddressBook3.txt", ios::in);
        while (instuf >> c.name >> c.place >> c.birthyear >> c.birthmonth >> c.birthday >> c.call >> c.email) { size++; }
        instuf.close();
        return size;
    }
    if(i==4)
    {
        int size=0;
        fstream instuf;
        Relative d;
        instuf.open("AddressBook4.txt", ios::in);
        while (instuf >> d.name >> d.generation >> d.birthyear >> d.birthmonth >> d.birthday >> d.call >> d.email) { size++; }
        instuf.close();
        return size;
    }
}

void Create()
{
    fstream stuf;
    stuf.open("AddressBook1.txt",ios::out);
    stuf.close();
    stuf.open("AddressBook2.txt",ios::out);
    stuf.close();
    stuf.open("AddressBook3.txt",ios::out);
    stuf.close();
    stuf.open("AddressBook4.txt",ios::out);
    stuf.close();
    stuf.open("Temp.txt",ios::out);
    stuf.close();
}
