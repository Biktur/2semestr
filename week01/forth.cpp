#include <iostream>
#include <math.h>

using namespace std; 
int main() 
{
    int a = 0;
    cin >> a;
    if (a < 0)
    {
        a = -a;
    }
    int i = 0;
    while (a>=pow(10, i+1))
    {
        i = i + 1;
    }
    int b = 0;
    int z = a;
    int j = i;
    int h = 0;
    int e = 0;
    while (j!=-1)
    {
        h = pow (10, j);
        e = pow (10, i-j);
        b = b + (a / h) * e;
        a = a % h;
        j = j - 1;
    }
    bool ans = (b == z);
    cout << ans << '\n';
    return 0;   
}