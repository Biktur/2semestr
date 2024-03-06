#include <iostream>
#include <math.h>

using namespace std;

int gcd(int a, int b) {
    if (a * b == 0) {
        return a + b;
    }
    if (a >= b) {
        return gcd(a % b, b);
    }
    return gcd(a, b % a);
}

int main() {
    int a = 0, b = 0;
    cin >> a >> b;
    int g[3] {}
    cout << gcd (a, b) << endl;
    return 0;
}