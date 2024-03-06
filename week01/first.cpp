#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double a = 0;
    double b = 0;
    double c = 0;
    cin >> a >> b >> c;
    if (a!=0)
    {
        if (b*b-4*a*c>=0)
        {
            double x1 = (-b-pow(b*b-4*a*c, .5))/2/a;
            double x2 = (-b+pow(b*b-4*a*c, .5))/2/a;
            if (x1 == x2)
            {
                cout << x1 << '\n';
            }
            else
            {
                if (x1 > x2)
                {
                    cout << x2 << ' ' << x1 << '\n'; 
                }
                else
                {
                    cout << x1 << ' ' << x2 << '\n';
                }
            }
        }
        else
        {
            cout << '\n';
        }
    }
    else
    {
        if (b!=0)
        {
            double x = -c/b;
            cout << x << '\n';
        }
        else
        {
            cout << '\n';
        }
    }
    return 0;
}