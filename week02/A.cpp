#include <iostream>

using namespace std;

int main() {
    int a = 0;
    cin >> a;
    if (a % 400 == 0 or (a % 4 == 0 and a % 100 != 0)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}