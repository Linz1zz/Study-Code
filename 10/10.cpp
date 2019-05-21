#include <iostream>
#include <string>
#include <cstring>
#include "10_1.h"

using namespace std;

int main()
{
	string name = "Lee";
	Person man{name, "John"};
	man.Show();
	man.FormalShow();

    golf sb{
        (char *)name.c_str(),
        12
    };
    sb.showgolf();
	return 0;
}
