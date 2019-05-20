#include <iostream>
#include <string>
#include "10_1.h"

using namespace std;

int main()
{
	string name = "Lee";
	Person man{name, "John"};
	man.Show();
	man.FormalShow();
	return 0;
}