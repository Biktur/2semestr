#include <iostream>
#include <math.h>

using namespace std;

int main() {
    long long int n = 0;
    int s = 1;
    cin >> n;
    for (int i = pow(n, 0.5); i > 1; --i) {
        if (n % i == 0) {
            s = 0;
        }
    }
    if (s == 1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}