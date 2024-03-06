#include <iostream>

using namespace std;

void solve(int a, int b, int c, int& x, int& y) {
    x = 0;
    y = 0;
    if (a == 0) {
        if (b == 0) {
            x = 0;
            y = 0;
        }
        else {
            if (c % b == 0) {
                x = 0;
                y = c / b;
            }
            else {
                x = 0;
                y = 0;
            }
        }
    }
    else {
        if (b == 0){
            if (c % a == 0) {
                x = c / a;
                y = 0;
            }
            else {
                x = 0;
                y = 0;
            }
        }
        else {
            int i = 0;
            for (i = 0; i < a; ++i) {
                if ((c - b * i) % a == 0) {
                    x = (c - b * i) / a;
                    y = i;
                    break;
                }
            }
        }
    }
}

int main() {
    int a = 0, b =   0, c = 0, x = 13, y = 128;
    cin >> a >> b >> c;
    solve (a, b, c, x, y);
    cout << x << ' ' << y;
    return 0;

}