#include <bits/stdc++.h>
using namespace std;

#define INF ((int)1e9)

int gens[100000+2];

int digitSum(int n) {
    int s = 0;
    int nn = n;
    while (nn > 0) {
        s += (nn%10);
        nn /= 10;
    }
    return n + s;
}

int main() {
    int b;
    memset(gens, 1, sizeof gens);
    for (int i=1; i<=99964; i++) {
        b = digitSum(i);
        gens[b] = min(gens[b], i);
    }
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        printf("%d\n", (gens[N] < 100001) ? gens[N] : 0);
    }
    return 0;
}

