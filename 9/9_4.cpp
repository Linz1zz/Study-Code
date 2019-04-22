#include <iostream>
#include <string>
#include "9_4.h"

using namespace std;

namespace SALES
{
    void setSales(Sale &s, const double ar[], int n)
    {
        double total = 0;
        s.max = ar[0];
        s.min = ar[0];
        for (size_t i = 0; i < n; i++)
        {
            total += ar[i];
            s.sales[i] = ar[i];
            if (ar[i] > s.max) s.max = ar[i];
            if (ar[i] < s.min) s.min = ar[i];

        }

        for (size_t i = n; i < QUARTERS; i++)
            s.sales[i] = 0.0;
        s.average = total / n;


    }

    void setSales(Sales &s)
    {
        double totoal = 0;
        s.max = 0;
        s.min = 0;
        cout << "Input" <<  QUARTERS << "double: ";
        for (size_t i = 0; i < QUARTERS; i++)
        {
            cin >> ar[i];
            total += ar[i];
            if (ar[i] > s.max) s.max = ar[i];
            if (ar[i] < s.min) s.min = ar[i];
        }

        s.average = total / QUARTERS;
        
    }

    void showSales(const Sales &s)
    {
        cout << s.average;
    }
}
