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
