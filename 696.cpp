#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, N;
    while (scanf("%d %d", &M, &N), M | N) {
        int re = 0;
        if (M == 0 || N == 0) {
            ;
        } else if (M == 1 || N == 1) {
            re = max(M,N);
        } else if (M == 2 || N == 2) {
            int n = max(M, N);
            if (n % 4 == 1) {
                re = 2;
            } else if (n % 4 > 1) {
                re = 4;
            }
            re += (n/4) * 4;
        } else {
            re = (M*N + 1)/2;
        }
        printf("%d knights may be placed on a %d row %d column board.\n", re, M, N);
    }
    return 0;
}

