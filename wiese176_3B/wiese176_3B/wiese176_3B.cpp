#include <ctime>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <iostream>

using namespace std;

int rando();

int main() {
    
    
    int n = rando();
    
    for(int i=0; i<3; i++)
    {
        
        int g;
        cout << "What is the random number?" << endl;
        cin >> g;
        if(g==n)
        {
            cout << "Correct" << endl;
            return 0;
        }
        else if(abs(g-n)==1)
            cout << "Close!" << endl;
        else if(g>n)
            cout << "Too high!" << endl;
        else
            cout << "Too low!" << endl;
        
    }
    
    cout << "You lose, the number was " << n << "!" << endl;
    
    return 0;
}

int rando()
{
    int n = 0;
    while(n==0)
    {
        srand(time(0));
        n = rand()%10;
    }
    return n;
}
