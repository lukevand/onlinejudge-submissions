#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m;
    while (scanf("%d:%d", &h, &m), h || m) {
        int t = (h%12)*60 + m;
        double d = fabs(0.5*t - 6*(t%60));
        printf("%.3f\n", fmin(d, 360-d));
    }

    return 0;
}

