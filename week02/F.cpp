#include <iostream>

using namespace std;

long long int fact(long long int n) {
    if (n == 0) {
        return 1;
    }
    return n * fact (n - 1);
}

int main() {
    long long int n = 0;
    cin >> n;
    cout << fact(n);
    return 0;
}