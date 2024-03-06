#include <iostream>

using namespace std;

int main() {
    long long int a = 0;
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> a;
        int s = 0;
        while (a != 1) {
            ++s;
            a = a / 2;
        }
        cout << s << endl;
    }
    return 0;
}