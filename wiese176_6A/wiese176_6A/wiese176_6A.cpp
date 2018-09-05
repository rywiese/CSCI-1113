#include <iostream>
#include <cmath>

using namespace std;

double frac(int x, int n, int max);

int main() {
    
    double x;
    int n;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter number of recursions: ";
    cin >> n;
    cout << "Recursive tan(x): " << x/(1.0-frac(x, 1, n)) << endl;
    cout << "Real tan(x): " << tan(x) << endl;
    return 0;
}

double frac(int x, int n, int max)
{
    if(max==0)
    {
        return 0;
    }
    if(n==max)
    {
        return 1.0*x*x/(2.0*n+1.0);
    }
    return 1.0*x*x/(2.0*(n)+1.0-frac(x, n+1, max));
}