#include <iostream>
#include <math.h>

using namespace std;

long long int phi(long long int n) {
    long long int s = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0){
            while (n % i == 0) {
                n /= i;
            }
            s -= s / i;
        }
    }
    if (n != 1) {
        return s - s / n;
    }
    return s;
}

int f(int n) {
    int s = n;
    int k = 0, m = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0){
            k = 0;
            while (n % i == 0) {
                k += 1;
                n /= i;
            }
            s -= s / i;
            if (k > m) {
                m = k;
            }
        }
    }
    if (n != 1) {
        return ((m / s) + 1) * (s - s / n);
    }
    return ((m / s) + 1) * s;
}

long long int logtwo(long long int n) {
    int s = 0;
    while (n != 1) {
        ++s;
        n = n / 2;
    }
    return s;
}

unsigned long long int whatever(unsigned long long int a, unsigned long long int k, unsigned long long int m){
    if (k == 0) {
        return 1;
    }
    if (k == 1) {
        return a;
    }
    unsigned long long int s = whatever(a, k / 2, m);
    return ((m - (s * (m - s) % m)) * whatever (a, k % 2 , m)) % m;
}

unsigned long long int arrows (unsigned long long int n, unsigned long long int k, unsigned long long int m) {
    if (k == 1) {
        return n;
    }
    return whatever(n % m, arrows (n, k-1, phi(m)), m) + m * phi(m);
}

int main() {
    unsigned long long int a = 0, k = 0, m = 0;
    cin >> a >> k >> m;
    cout << arrows (a, k, m) - m * phi(m) << endl;
    return 0;
}
