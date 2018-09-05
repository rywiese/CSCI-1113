#include <cmath>
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool winner(char x, char y);
char rando();
string charToString(char x);

int main() {
    
    int w=0;
    int l=0;
    int n;
    cout << "How many games would you like to play?" << endl;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        char playerMove;
        char computerMove = rando();
        cout << "Rock... Paper... Scissors!" << endl;
        cin >> playerMove;
        if(playerMove!='R' && playerMove!='P' && playerMove!='S')
        {
            cout << "Invalid input" << endl;
            return 0;
        }
        
        if(winner(playerMove, computerMove))
        {
            w++;
            cout << "Your " << charToString(playerMove) << " beats the computer's " << charToString(computerMove) << "!" << endl;
        }
        else if(winner(computerMove, playerMove))
        {
            l++;
            cout << "Your " << charToString(playerMove) << " lost to the computer's " << charToString(computerMove) << "!" << endl;
        }
        else
        {
            cout << "You both tie by playing " << charToString(playerMove) << endl;
        }
        
    }
    
    if(w>l)
        cout << "Congratulations, you beat the computer!" << endl;
    else if(w<l)
        cout << "You lost to the computer, better luck next time." << endl;
    else if (w==l)
        cout << "The game ends in a draw." << endl;
    else
        cout << "Error" << endl;
    
    return 0;
}

bool winner(char x, char y)
{
    if(x=='R' && y=='S')
        return true;
    if(x=='P' && y=='R')
        return true;
    if(x=='S' && y=='P')
        return true;
    else
        return false;
    
}

char rando()
{
    while(0==0)
    {
        srand(time(0));
        double x = rand()%10;
        if(x<3)
            return 'R';
        else if(x<6)
            return 'P';
        else if(x<9)
            return 'S';
    }
}

string charToString(char x)
{
    if(x=='R')
        return "Rock";
    else if(x=='P')
        return "Paper";
    else if(x=='S')
        return "Scissors";
    else
        return "Error";
}

