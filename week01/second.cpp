#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n = 0;
    int a = 1;
    int f = 1;
    cin >> n;
    while (a<=n)
    {
        f=f*a;
        a=a+1;
    }
    cout << f;
    return 0;
}