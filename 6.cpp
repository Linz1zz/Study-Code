# include <iostream>
# include <cctype>
# include <string>
# include <array>
# include <iomanip>

using namespace std;

void keyboard_6_1()
{
    char ch = 0;
    while ((ch = cin.get()) != '@')
    {
        if (isdigit(ch)) continue;
        else if (islower(ch))
            ch = toupper(ch);
        else if (isupper(ch))
            ch = tolower(ch);

        cout << ch;
    }

    cout << endl << "Done!" << endl;

}

void donation_6_2 ()
{
    double donation[10];
    int num = 0;
    double sum = 0;

    while ( (num < 10) && (cin >> donation[num]))
    {
        sum += donation[num];
        num++;
    }

    double avg = sum / num;
    int lager = 0;
    for (int i = 0; i <= num; i++)
    {
        if (donation[i] > avg)
            lager++;
    }
    cout << "The avg is:" << avg << endl;
    cout << "The number of lager than avg :"<< lager << endl; 


}

void menu_6_3()
{

    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore\t" << "p) pianist" << endl;
    cout << "t) tree\t\t" << "g) game" << endl;

    char ch;
    bool exit = false;
    while ((cin >> ch) && !exit)
    {
        switch (ch)
        {
            case 'c' :
               cout << "carnivore" << endl;
               exit = true;
              break;
            case 'p':
              cout << "pianist" << endl;
              exit = true;
              break;
            case 't':
              cout << "tree" << endl;
              exit = true;
              break;
            case 'g':
              cout << "game" << endl;
              exit = true;
              break;
            default : cout << "Please enter a c, p, t, or g: ";

        }
        if (exit) break;
    }
}


void tax_6_5()
{
   float tax, money;
   cout << "Please input your income: ";
   while ((cin >> money) && (money >= 0)) 
   {

       if (money <= 5000)
           tax = 0;
       else if (money > 35000)
           tax = (money - 35000) * 0.2 + 4000;
       else if (money > 15000)
           tax = (money - 15000) * 0.15 + 1000;
       else
           tax = (money - 5000) * 0.1;
       
       cout << "Your tax is: " << tax << endl;
       cout << "Please input your imcome: ";

   }
}

struct pat_info {
    char name[50];
    double money;
};

void donate()
{
    int num, tmp = 0;
    cout << "Please input the number of people: " << endl;
    cin >> num;

    struct pat_info * info = new pat_info [num];
    for (size_t i = 0; i < num; i++)
    {
        cout << "Please input the name: ";
        cin >> info[i].name;
        cout << "Please input the amout: ";
        cin >> info[i].money;
        if (info[i].money > 10000) tmp++;
    }
    
    cout << "Grand Patrons:" << endl;
    if (tmp == 0)
    {
            cout << "None";
           
    }
    else
    {
        for (size_t i = 0; ((i <num) && (tmp > 0)); i++)
        {
            if (info[i].money > 10000)
                cout << info[i].name << setw(20) << fixed<<info[i].money << endl;
        }
    }

    delete [] info;
     

}




int main()
{

    //keyboard_6_1();

    //donation_6_2();

    //menu_6_3();

    //tax_6_5();
    donate();
    return 0;
}
