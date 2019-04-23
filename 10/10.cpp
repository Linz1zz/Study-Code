#include <iostream>
#include <string>
#include "10_1.h"

using namespace std;

int main()
{
    Bank bb{
        "liu xiao",
         "123445",
         45.2
    };
    Bank cc;
    cc.show();
    bb.show();
    return 0;
}
