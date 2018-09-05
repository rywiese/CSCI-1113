#include <iostream>
#include <cmath>

using namespace std;

void setBoard(char board[100][100], int size);
void printBoard(char board[100][100], int size);
void copyBoard(char board[100][100], char temp[100][100], int size);
void findOpenSpot(char board[100][100], int size, int &row, int &col);
void placeQueen(char board[100][100], int size, int row, int col);
void solveBoard(char board[100][100], int size, int n, bool &done);

int main()
{
    
    int size;
    int n;
    char board[100][100];
    cout << "What size board do you want? " << endl;
    cin >> size;
    cout << "How many queens do you want to place? " << endl;
    cin >> n;
    setBoard(board, size);
    
    bool done=false;
    solveBoard(board, size, n, done);
    if(done==false)
    {
        cout << endl << "Impossible." << endl;
    }
    return 0;
}

void setBoard(char board[100][100], int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            board[i][j]='-';
        }
    }
}

void printBoard(char board[100][100], int size)
{
    cout << endl;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void copyBoard(char board[100][100], char temp[100][100], int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            temp[i][j]=board[i][j];
        }
    }
}

void findOpenSpot(char board[100][100], int size, int &row, int &col)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(board[i][j]=='-')
            {
                row=i;
                col=j;
                return;
            }
        }
    }
}

void placeQueen(char board[100][100], int size, int row, int col)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(i==row || j==col || abs(row-i)==abs(col-j))
            {
                board[i][j]='.';
            }
        }
    }
    board[row][col]='Q';
}

void solveBoard(char board[100][100], int size, int n, bool &done)
{
    char temp[100][100];
    
    if(n==0)
    {
        printBoard(board, size);
        done=true;
        return;
    }
    
    //int row=-1;
    //int col=-1;
    //findOpenSpot(temp, size, row, col);
    //if(row==-1 || col==-1)
    //{
      //  return;
    //}
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(board[i][j]=='-' && done==false)
            {
                copyBoard(board, temp, size);
                placeQueen(temp, size, i, j);
                //printBoard(temp, size);
                //cout << n << endl;
                solveBoard(temp, size, n-1, done);
            }
        }
    }
    
    
    
}