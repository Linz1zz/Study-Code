#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
using namespace std;

void outputstr_8_1(char *p, int i = 0);

void intial_8_2(struct CandyBar & ca, char *name = "Millwnnium", double weight = 2.85, int hot = 350);

void output_8_2(const struct CandyBar & ca);

void aToA_8_3(string & st);

template <typename T>
T max_8_5(T *a);

template <typename T>
T maxn_8_6(T *b, int i);

template <> char * maxn_8_6(char **b, int i);

struct CandyBar
{
    char *name;
    double weight;
    int hot;
};


int main()
{
    char *p = "fool";
    struct CandyBar Candy;
    int a[5] = {
        1, 2, 3, 4, 5
    };

    double b[5] = {
        1.0, 2.2, 3.1, 4.1, 5.1
    };

    int temp = max_8_5(a);
    double demp = max_8_5(b);
    char *s[] = {
        "cccc", "dddd", "xxxxxxx"
    };

    p = maxn_8_6(s, 3);
    cout << p;
    //cout << temp << endl;
    //cout << demp << endl;

    //outputstr_8_1(p, 2);
    //outputstr_8_1(p, 2);
    // outputstr_8_1(p, 2);
    //intial_8_2(Candy);
    //output_8_2(Candy);

    //string cc;

    //while(true)
    //{
    //    cout << "Input: ";
    //    getline(cin, cc);
    //    if (cc != "q")
    //    {
    //        aToA_8_3(cc);
    //        cout << cc << endl;
    //    }
    //    else
    //    {
    //        cout << "Bye" << endl;
    //        break;
    //    }
    //}


    return 0;
}


void outputstr_8_1(char *p, int i)
{
    static int n = 0;
    n++;

    if (i != 0)
        for (size_t t = 0; t < n; t++)
            cout << p << endl;
    else
        cout << p << endl;

}


void intial_8_2(struct CandyBar &ca, char *name, double weight, int hot)
{
    ca.name = name;
    ca.weight = weight;
    ca.hot = hot;
}

void output_8_2(const struct CandyBar & ca)
{
    cout << ca.name << endl;
    cout << ca.weight << endl;
    cout << ca.hot << endl;
}

void aToA_8_3(string & st)
{
    for (size_t i = 0; i < st.length(); i++)
    {
        st[i] = toupper(st[i]);
    }
}

template <typename T>
T max_8_5(T *a)
{
    T temp = a[0];
    for (size_t i = 0; i < 5; i++)
    {
        if (a[i] > temp)
            temp = a[i];
    }

    return temp;
}

template <typename T>
T maxn_8_6(T *b, int i)
{
    T temp = b[0];
    for (size_t t = 0; t < i; t++)
    {
        if (b[t] > temp)
            temp = b[t];
    }
    return temp;
}

template <> char * maxn_8_6(char **b, int i)
{
    char *p = b[0];
    //cout << p;
    for (size_t t = 0; t < i; t++)
    {

        if (strlen(b[t]) > strlen(p))
            p = b[t];
        //cout << b[t];
    }
    //cout << p;
    return p;

}
