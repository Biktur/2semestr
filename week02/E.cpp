#include <iostream>

using namespace std;

long long int Fib(int a) {
    if (a == 0 or a == 1) {
        return 1;
    }
    return Fib(a - 1) + Fib(a - 2);
}

int main() {
    int n = 0;
    cin >> n;
    cout << Fib(n) << endl;
    return 0;
}