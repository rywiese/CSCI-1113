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
    
    in.close();
    
    ofstream out;
    out.open("statistics.txt");
    if(out.fail())
    {
        cout << "statistics.txt failed to open." << endl;
        return 0;
    }
    
    out << "A " << a + am << endl;
    out << "B " << bp + b + bm << endl;
    out << "C " << cp + c + cm << endl;
    out << "D " << dp + d << endl;
    out << "F " << f << endl;
    
    out.close();
    
    cout << a << " A" << endl;
    cout << am << " A-" << endl;
    cout << bp << " B+" << endl;
    cout << b << " B" << endl;
    cout << bm << " B-" << endl;
    cout << cp << " C+" << endl;
    cout << c << " C" << endl;
    cout << cm << " C-" << endl;
    cout << dp << " D+" << endl;
    cout << d << " D" << endl;
    cout << f << " F" << endl;
    
    return 0;
}
