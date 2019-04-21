#include <iostream>
#include <string>
#include "golf.h"
#include <cstring>
using namespace std;

void setgolf(golf &g, const char *name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf &g)
{
    if (strlen(g.fullname) == 0) return 0;
    else
        return 1;
}

void handicap(golf &g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf &g)
{
    std::cout << g.fullname << "\t\t" << std::endl;
}
