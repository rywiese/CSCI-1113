#include <iostream>
#include <ctime>

using namespace std;

int diceRoll();

int main()
{
    srand(0);
    int results[1000000];
    int count[50];
    for(int i=0; i<50; i++)
    {
        count[i] = 0;
    }
    int max = 0;
    
    for(int i=0; i<1000000; i++)
    {
        results[i] = diceRoll();
        if(results[i]>max)
        {
            max = results[i];
        }
        count[results[i]]++;
    }
    
    for(int i=2; i<=max; i++)
    {
        cout << i << " " << ((1.0*count[i])/(1000000.0))*100.0 << endl;
    }
    
    
    return 0;
}

int diceRoll()
{
    int x = rand()%6+1;
    int y = rand()%6+1;
    if(x+y < 12)
    {
        return x+y;
    }
    else
    {
        return 1 + diceRoll();
    }
}