#include <iostream>
#include <math.h>

using namespace std;

unsigned long long int arrows (unsigned long long int n, unsigned long long int k, unsigned long long int m) {
    if (k == 1) {
        return n;
    }
    return pow(n, arrows(n, k-1, m));
}

int main() {
    unsigned long long int a = 0, k = 0, m = 0;
    cin >> a >> k >> m;
    cout << arrows (a, k, m) % m << endl;
    return 0;
}