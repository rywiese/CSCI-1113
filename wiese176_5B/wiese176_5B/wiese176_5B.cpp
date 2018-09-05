#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int SIZE = 10;
void move(char line[SIZE][SIZE], char a);
void find(char line[SIZE][SIZE], char c, int &row, int &col);
void print(char line[SIZE][SIZE]);



int main()
{
    ifstream file;
    file.open("grid.txt");
    char line[SIZE][SIZE];
    if(file.fail())
    {
        cout << "File failed. Using default grid." << endl;
        for(int i=0; i < SIZE; i++)
        {
            for(int j=0; j < SIZE; j++)
            {
                line[i][j] = '-';
                if(j==SIZE-1 || (j==4 && i!=0) || (j==5 && i==1) || i==SIZE-1)
                {
                    line[i][j] = 'W';
                }
            }
        }
        
        line[SIZE/2][SIZE/2] = 'X';
        line[0][0] = 'O';
    }
    
    else
    {
        while(!file.eof())
        {
            for(int i=0; i < SIZE; i++)
            {
                for(int j=0; j < SIZE; j++)
                {
                    file >> line[i][j];
                }
            }
        }
    }
    
    print(line);
    
    char action;
    while(true)
    {
        cout << "Do you want to move left, right, up or down? (l / r / u / d) ";
        cin >> action;
        
        move(line, action);
        print(line);
        
        int row, col;
        find(line, 'O', row, col);
        if(row == -1 && col == -1)
        {
            cout << "You win!\n";
            return 0;
        }
        
    }
}

void print(char line[SIZE][SIZE])
{
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    for(int i=0; i < SIZE; i++)
    {
        for(int j=0; j < SIZE; j++)
        {
            cout << line[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void move(char line[SIZE][SIZE], char a)
{
    int row, col;
    find(line, 'X', row, col);
    if(a == 'l' && col > 0 && line[row][col-1]!='W')
    {
        line[row][col] = '-';
        line[row][col-1] = 'X';
    }
    else if (a == 'r' && col < SIZE-1 && line[row][col+1]!='W')
    {
        line[row][col] = '-';
        line[row][col+1] = 'X';
    }
    else if (a == 'u' && row > 0 && line[row-1][col]!='W')
    {
        line[row][col] = '-';
        line[row-1][col] = 'X';
    }
    else if (a == 'd' && row < SIZE-1 && line[row+1][col]!='W')
    {
        line[row][col] = '-';
        line[row+1][col] = 'X';
    }
}

void find(char line[SIZE][SIZE], char c, int& row, int& col)
{
    for(int i=0; i < SIZE; i++)
    {
        for(int j=0; j < SIZE; j++)
        {
            if(line[i][j] == c)
            {
                row = i;
                col = j;
                return;
            }
        }
    }
    
    row=-1;
    col=-1;
    
}












/*
 
 const char BLANK = '-';
 const char ROBOT = 'X';
 const char GOAL = 'O';
 const int length = 10;
 
 bool hasChar(char pos[][length],int length, char findMe);
 void clearScreen();
 void showGrid(char pos[][length],int length);
 void updateGrid(char pos[][length],int length,int & xPos,int &yPos, char action);
 
 
 int main()
 {
	char pos[length][length];
	for(int i=0; i < length; i++)
	{
 for(int j=0; j < length; j++)
 {
 pos[i][j] = BLANK;
 }
	}
	pos[0][0] = GOAL;
	pos[length/2][length/2] = ROBOT;
	
	int xPos = length/2;
	int yPos = length/2;
	
	while(hasChar(pos, length, GOAL))
	{
 char action;
 clearScreen();
 showGrid(pos, length);
 cout << "Where would you like to go? (l or r) " << endl;
 cin >> action;
 
 updateGrid(pos, length, xPos, yPos, action);
	}
	
	clearScreen();
	showGrid(pos, length);
	cout << "You won!  Have a cookie.\n";
	
	return 0;
 }
 
 bool hasChar(char pos[][length],int length, char findMe)
 {
	for(int i=0; i < length; i++)
	{
 for(int j=0; j < length; j++)
 {
 if(pos[i][j] == findMe)
 {
 return true;
 }
 }
	}
	
	return false;
 }
 
 void clearScreen()
 {
	cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
 }
 
 void showGrid(char pos[][length],int length)
 {
	for(int i=0; i < length; i++)
	{
 for(int j=0; j < length; j++)
 {
 cout << pos[i][j];
 }
 cout << endl;
 
	}
 }
 
 void updateGrid(char pos[][length],int length,int & xPos, int & yPos,char action)
 {
	pos[yPos][xPos] = BLANK;
 
	if(tolower(action) == 'l' && xPos > 0)
	{
 xPos--;
	}	
	else if(tolower(action) == 'r' && xPos < length - 1)
	{
 xPos++;
	}
	else if(tolower(action) == 'u' && yPos > 0)
	{
 yPos--;
	}	
	else if(tolower(action) == 'd' && yPos < length - 1)
	{
 yPos++;
	}
	
	
	pos[yPos][xPos] = ROBOT;
 
 }
 */