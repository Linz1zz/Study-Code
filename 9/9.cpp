#include <iostream>
#include <string>
#include "golf.h"
#include <cstring>
using namespace std;
int main()
{
    int Num = 5;
    golf g[Num];
    string name;
    char mm[Len] = "sss";
    int hc;
    for (size_t i = 0; i < Num; i++)
    {
        cout <<  "Input name: ";
        getline(std::cin, name);
        if (name.length() == 0)
            break;
        cout << "Input handicap: ";
        cin >> hc;
        setgolf(g[i], name.c_str(), hc);
    }
    return 0;
}
