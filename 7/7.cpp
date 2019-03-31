# include <iostream>
# include <string>
# include <cctype>
# include <fstream>

using namespace std;

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

int input_7_2(float *a, int n)
{
    float golf;
    int  i = 0;
    cout << "input golf score(10) (-1 to quit): ";
    while ((cin >> golf) && (i < n))
    {
        if (golf == -1)
            break;
        a[i] = golf;
        i++;
        cout << "input golf score(10) (-1 to quit): ";
    }

    return i;
}

void output_7_2(float *a, int n)
{

    float golf;
    int  i = 0;
    cout << "score: " << endl;
    while (i < n)
    {
        cout << a[i] << '\t';
    }
    cout << endl;
}

float avg_7_2(float *a, int n)
{

    float sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }

    float avg = sum / n;
    return avg;

}

struct box {
    char maker[30];
    float height;
    float length;
    float width;
    float volume;
};

void strvalue_7_3(struct box bb)
{

    cout << "maker : " << bb.maker << endl;
    cout << "height: " << bb.height << endl;
    cout << "length: " << bb.length << endl;
    cout << "width : " << bb.width << endl;
    cout << "volume: " << bb.volume << endl;
}

void strpoint_7_3(struct box *bb)
{
    bb->volume = bb->height * bb->width * bb-> length;
}


int fun_7_5(int n)
{
    static int z = 0;
    if ((n == 1) || (n == 0))
        z = 1;
    else
        z = n * fun_7_5(n - 1);

    return z;
}

int Fill_array_7_6(double *a, int n)
{
    int num = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (cin >> a[i])
            num++;
        else
            break;

    }
    return num;

}

void Show_array_7_6(double *a, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << '\t';
    }
}

void Reverse_array_7_6(double *a, int n)
{
    double tep;
    for (size_t i = 0, j = n - 1; i < j; i++, j--)
    {
        tep = a[i];
        a[i] = a[j];
        a[j] = tep;
    }
}

# define Num  4
struct expanse{
    double ex[Num];
};

const char *sea[Num] = {
    "spring",
    "summer",
    "fall",
    "winter"
};

const int SLEN = 30;
struct student{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};
int getinfo_7_9(student pa[], int n)
{
    int num = 0;
    for (size_t i = 0; i < n; i++)
    {
        cout << "input name: ";
        cin.getline(pa[i].fullname, SLEN);
        cout <<  "input hobby: ";
        cin.getline(pa[i].hobby, SLEN);
        cout << "ooplevel: ";
        cin >> pa[i].ooplevel;
        while (cin.get() != '\n')
            continue;
        num++;

    }
    return num;
}

int main()
{
    int z;
    student pa[10];
    z = getinfo_7_9(pa, 10);
    cout << z;
    return z;
}









