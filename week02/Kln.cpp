#include <iostream>
#include <math.h>

using namespace std;

unsigned long long int whatever(unsigned long long int a, unsigned long long int k, unsigned long long int m){
    if (k == 0) {
        return 1;
    }
    if (k == 1) {
        return a;
    }
    int s = whatever(a, k / 2, m);
    return ((m - (s * (m - s) % m)) * whatever (a, k % 2 , m)) % m;
}

int main() {
    unsigned long long int a = 0, k = 0, m = 0;
    cin >> a >> k >> m;
    cout << whatever (a % m, k, m) << endl;
    return 0;
}