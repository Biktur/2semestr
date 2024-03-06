#include <iostream>

using namespace std;

long long int x_to_y (long long int a, long long int b) {
    if (b == 0) {
        return 1;
    }
    return a * x_to_y(a, b-1);
}

int main() {
    long long int N = 0, M = 0;
    cin >> N >> M;
    cout << x_to_y(N, M);
    return 0;
}