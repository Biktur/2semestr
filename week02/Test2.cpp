#include <iostream>
#include <math.h>

using namespace std;

void reverse_array(int input_array[], unsigned size) {
    const int a = size;
    int ans[a];
    for (unsigned int i = 0; i < size; ++i) {
        ans[i] = input_array[size - i];
    }
    input_array = ans;
}

int main() {
    
    cin >> a >> b;
    cout << reverse_array(a, b) << endl;
    return 0;
}