#include <iostream>

using namespace std;

int log (unsigned long long int a, int b) {
    int s = 0;
    while (a >= b) {
        ++s;
        a = a / b;
    }
    return s;
}

long long int x_to_y (long long int a, long long int b) {
    if (b == 0) {
        return 1;
    }
    return a * x_to_y(a, b-1);
}


void base(unsigned long long int a, int b) {
    for (int i = log (a, b); i>=0; --i) {
        cout << a / x_to_y(b, i);
        a %= x_to_y(b, i);
    }
}

int main() {
    unsigned long long int n = 0;
    int b = 0;
    cin >> n >> b;
    base (n, b);
    return 0;
}