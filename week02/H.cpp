#include <iostream>

using namespace std;

int nod (int a, int b, int& x, int& y, int& z, int& t) {
    if (a * b == 0){
        return a + b;
    }
    if (a >= b) {
        int r = x, l = y;
        x = z - x * (a / b);
        y = t - y * (a / b);
        z = r;
        t = l;
        return nod(a % b, b, x, y, z, t);
    }
    int r = x, l = y;
    x = z - x * (b / a);
    y = t - y * (b / a);
    z = r;
    t = l;
    return nod(a, b % a, x, y, z, t);
}

void solve(int a, int b, int c, int& x, int& y) {
    int k = 0, l = 1, m = 1, n = 0, f = 0;
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
            f = nod (a, b, k, l, m, n);
            if (c % f == 0) {
                if (a * k + b * l == f) {
                    x = k * (c / f);
                    y = l * (c / f);
                }
                if (a * l + b * l == f) {
                    x = l * (c / f);
                    y = k * (c / f);
                }
                if (a * m + b * n == f) {
                    x = m * (c / f);
                    y = n * (c / f);
                }
                if (a * n + b * m == f) {
                    x = n * (c / f);
                    y = m * (c / f);
                }
            }
            else {
                x = 0;
                y = 0;
            }
        }
    }
}

int main() {
    int a = 0, b = 0, c = 0, x = 13, y = 128;
    cin >> a >> b >> c;
    solve (a, b, c, x, y);
    cout << x << ' ' << y;
    return 0;

}