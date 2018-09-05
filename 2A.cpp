#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int time;
    int timeChange;
    char ap;
    char fb;
    cout << "Enter current time (A for AM, P for PM):" << endl;
    cin >> time >> ap;
    cout << "How many hours forwards or backwards do you want to move the clock (F for forwards, B for backwards):" << endl;
    cin >> fb >> timeChange;
    timeChange = timeChange%24;
    if(time==12)
    {
        time = 0;
    }
    
    if((ap!='A' && ap!='P') || (fb!='F' && fb!='B'))
    {
        cout << "Invalid entry" << endl;
        return 0;
    }
    
    if(ap=='P')
    {
        time += 12;
    }
    
    
    if(fb=='F')
    {
        time = (time + timeChange)%24;
    }
    if(fb=='B')
    {
        time = (time - timeChange)%24;
        if(time<0)
        {
            time += 24;
        }
    }
    
    if(time>11)
    {
        time -= 12;
        if(time==0)
        {
            time = 12;
        }
        cout << "The new time is: " << time << " " << "PM" << endl;
    }
    else
    {
        if(time==0)
        {
            time = 12;
        }
        cout << "The new time is: " << time << " " << "AM" << endl;
    }
    
    return 0;
}
