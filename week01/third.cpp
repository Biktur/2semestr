#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a = 0;
    int b = 0;
    cin >> a >> b;
    int f = a*b;
    while (a*b!=0)
    {
        if (a>b)
        {
            a=a%b;
        }
        else
        {
            b=b%a;
        }
    }
    cout << f/(a+b);
    return 0;
}