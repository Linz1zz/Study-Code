#include <iostream>
#include <string>
using namespace std;

class Bank
{
    string name;
    string account;
    float money;

    public:

    Bank(string nm = "", string acc = "", float mon = 0.0);
    void input(float mon);
    bool output(float mon);
    void show() const;

};

namespace SALES
{
    class Sales
    {
        static const int Q = 4;
        double sales[Q];
        double max;
        double min;

        public:
        Sales(const double ar[], int n);

    };
}

class Person
{
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];

    public:
    Person() {
        lname = ""; fname[0] = '\0';
    }
    Person(const string &ln, const char *fn = "Heyyou");
    void Show() const;
    void FormalShow() const;
};

class golf
{
    static const int Len = 40;
    char fullname[Len];
    int handicap;

    public:
    golf(char *name = "", int hc = 0);
    golf(golf &g);
    void handcap(int hc);
    void showgolf() const;

};

typedef Item customer;

class  Stack
{
    static const int MAX = 10;
    Item a[MAX];
    int top;

    public:


}
































