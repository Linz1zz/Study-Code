# include <iostream>
# include <string>
# include <cctype>
# include <fstream>

void avg_7_1 ()
{
	double x, y, avg;
	cout << "Please enter two numbers: ";
	cin >> x >> y;

	while ((x != 0) && (y != 0))
	{
        avg = 2.0 * x * y / (x + y);
        cout << "The avg of x and y is: " << avg;
        cout << "Please enter two numbers: ";
        cin >> x >> y;
	}
}