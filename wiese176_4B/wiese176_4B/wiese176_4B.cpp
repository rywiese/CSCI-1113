#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    string dump;
    int a, am, bp, b, bm, cp, c, cm, dp, d, f;
    
    ifstream in;
    in.open("grades.txt");
    if(in.fail())
    {
        cout << "grades.txt failed to open." << endl;
        return 0;
    }
    
    while(!in.eof())
    {
        double grade;
        in >> dump >> dump >> grade;
        if(in.eof())
        {
            break;
        }
        if(grade>=93)
        {
            a++;
        }
        else if(grade>=90)
        {
            am++;
        }
        else if(grade>=87)
        {
            bp++;
        }
        else if(grade>=83)
        {
            b++;
        }
        else if(grade>=80)
        {
            bm++;
        }
        else if(grade>=77)
        {
            cp++;
        }
        else if(grade>=73)
        {
            c++;
        }
        else if(grade>=70)
        {
            cm++;
        }
        else if(grade>=67)
        {
            dp++;
        }
        else if(grade>=60)
        {
            d++;
        }
        else
        {
            f++;
        }
        
        
    }
    
    a += am;
    b += bp + bm;
    c += cp + cm;
    d += dp;
    
    int n = a;
    if(b>a)
    {
        n = b;
    }
    if(c>a)
    {
        n = c;
    }
    if(d>a)
    {
        n = d;
    }
    if(f>a)
    {
        n = f;
    }
    
    in.close();
    
    ofstream out;
    out.open("histogram.txt");
    if(out.fail())
    {
        cout << "histogram.txt failed to open." << endl;
        return 0;
    }
    
    for(int i=n; i>0; i--)
    {
        out << i;
        if(a>=i)
        {
            out << 'X';
        }
        else
        {
            out << " ";
        }
        if(b>=i)
        {
            out << 'X';
        }
        else
        {
            out << " ";
        }
        if(c>=i)
        {
            out << 'X';
        }
        else
        {
            out << " ";
        }
        if(d>=i)
        {
            out << 'X';
        }
        else
        {
            out << " ";
        }
        if(f>=i)
        {
            out << 'X';
        }
        else
        {
            out << " ";
        }
        
        out << endl;
    }
    
    out << " -----" << endl;
    out << " ABCDF" << endl;
    
    out.close();
    
    return 0;
}
