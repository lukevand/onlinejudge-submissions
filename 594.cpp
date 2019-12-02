#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int m = 0;
        int m1 = n & 0xFF;
        int m2 = (n >> 8) & 0xFF;
        int m3 = (n >> 16) & 0xFF;
        int m4 = (n >> 24) & 0xFF;
        m = (m1 << 24) | (m2 << 16) | (m3 << 8) | m4;
        printf("%d converts to %d\n", n, m);
    }
    return 0;
}

