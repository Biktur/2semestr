#include <iostream>

using namespace std;

unsigned long long int whatever(unsigned long long int a, unsigned long long int k, unsigned long long int m){
    if (k == 0) {
        return 1;
    }
    return (a * whatever (a, k - 1, m)) % m;
}

int main() {
    unsigned long long int a = 0, k = 0, m = 0;
    cin >> a >> k >> m;
    cout << whatever (a % m, k, m) << endl;
    return 0;
}