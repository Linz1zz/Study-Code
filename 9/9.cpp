#include <iostream>
#include <string>
#include "golf.h"
#include "9_4.h"
#include <cstring>
using namespace std;

struct chaff
{
    char dross[20];
    int slag;
};

int main()
{
    int Num = 5;
    golf g[Num];
    char ch;
    string name;
    int hc;
    // for (size_t i = 0; i < Num; i++)
    // {
    //     cout <<  "Input name: ";
    //     getline(std::cin, name);
    //     if (name == "")
    //     {
    //         cout << "quit" << endl;
    //         break;
    //     }
    //     cout << "Input handicap: ";
    //     cin >> hc;
    //     ch = cin.get();
    //     setgolf(g[i], name.c_str(), hc);
    //     // cout << i;
    // }

    // chaff *p = new chaff [2];
    return 0;
}
