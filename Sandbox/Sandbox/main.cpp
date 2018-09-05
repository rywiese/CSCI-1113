#include <iostream>
#include <cstdlib>

using namespace std;

int inverse(int a, int m);

int main()
{
    while(true)
    {
        int a;
        int m;
    
        cout << "Enter a:" << endl;
        cin >> a;
        cout << "Enter m:" << endl;
        cin >> m;
    
        cout << "a^-1 = " << inverse(a, m) << endl << "Would you like to continue? (y/n)" << endl;
        string cont;
        cin >> cont;
    
        if(cont=="n")
        {
            break;
        }
    }
    return 0;
}

int inverse(int a, int m)
{
    int ai = 0;
    
    while((ai * a) % m != 1)
    {
        ai++;
    }
    
    return ai;
}