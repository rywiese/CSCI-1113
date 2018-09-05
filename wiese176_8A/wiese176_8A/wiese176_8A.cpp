#include <iostream>
#include <cmath>

using namespace std;

void displayPoly(int p[], int n);
void multiplyPoly(int p1[], int n1, int p2[], int n2);

int main()
{
    int n1, n2;
    
    cout << "How many coefficients are in the first polynomial? ";
    cin >> n1;
    int *p1 = new int[n1];
    cout << "What are the coefficients? ";
    for(int i=0; i<n1; i++)
    {
        cin >> p1[i];
    }
    
    cout << "How many coefficients are in the second polynomial? ";
    cin >> n2;
    int *p2 = new int[n2];
    cout << "What are the coefficients? ";
    for(int i=0; i<n2; i++)
    {
        cin >> p2[i];
    }
    displayPoly(p1, n1);
    cout << "times" << endl;
    displayPoly(p2, n2);
    cout << "-----" << endl;
    multiplyPoly(p1, n1, p2, n2);
    
    delete []p1;
    delete []p2;
    return 0;
}

void displayPoly(int p[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            cout << '(' << p[i] << ')' << ' ';
        }
        else
        {
            cout << "+ (" << p[i] << ')' << "x^" << i << ' ';
        }
    }
    cout << endl;
}

void multiplyPoly(int p1[], int n1, int p2[], int n2)
{
    int n3 = n1 + n2 - 1;
    int *p3 = new int[n3];
    for(int i=0; i<n3; i++)
    {
        p3[i] = 0;
    }
    for(int i=0; i<n3; i++)
    {
        for(int j=0; j<=n1; j++)
        {
            for(int k=0; k<=n2; k++)
            {
                if(j+k==i)
                {
                    p3[i] += p1[j] * p2[k];
                }
            }
        }
    }
    
    displayPoly(p3, n3);
    delete []p3;
    
}