#include <iostream>

using namespace std;

int main() {
    long int a = 1;
    int s = 0;
    while (a != 0) {
        cin >> a;
        if (a % 2 == 0) {
            ++s;
        }
    }
    cout << s - 1 << endl;
    return 0;
}