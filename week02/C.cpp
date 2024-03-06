#include <iostream>

using namespace std;

int main() {
    long long int a = 0;
    cin >> a;
    int s = 1;
    while (a != 1) {
        if (a % 2 == 1) {
            s = 0;
        }
        a = a / 2;
    }
    s;
    if (s == 1) {
        cout << "YES" << endl;
    }
    if (s == 0) {
        cout << "NO" << endl;
    }
    return 0;
}