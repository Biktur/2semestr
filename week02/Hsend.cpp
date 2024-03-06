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