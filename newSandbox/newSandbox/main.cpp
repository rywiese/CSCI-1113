#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int inverse(int a, int m);
int gcd(int a, int b);

int main()
{
    /*
    for(int i = 20; i <= 30; i++)
    {
        cout << "List of Z/" << i << endl;
        for(int j = 1; j < i; j++)
        {
            if(gcd(i,j) == 1)
                cout << j << endl;
        }
        cout << endl << endl << endl;
    }
     */
    int i = 1;
    cout << "Thinking" << endl;
    
    while((2 * i) % 26 != 18)
    {
        i++;
        if((20 * i) % 26 != 18)
        {
            cout << "20 * " << i << " = 18" << endl;
            break;
        }
        else
        {
            cout << i << endl;
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

int gcd(int a, int b) {
    while (b != 0)  {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}