#include <bits/stdc++.h>
using namespace std;

typedef long long L;
typedef vector<int> VI;

L poly(const VI& v, int n) {
    L result = 0LL;
    for (int i=0; i<(int)v.size(); i++) {
        result += v[i]*(L)pow(n, i);
    }
    return result;
}


int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        int degree, d, k;
        scanf("%d", &degree);
        VI coeff(degree+1, 0);
        for (int i=0; i<=degree; i++) {
            scanf("%d", &coeff[i]);
        }
        scanf("%d\n%d", &d, &k);
        int myn = -1;
        for (int i=1; ; i++) {
            if (k <= d*i*(i+1)/2) {
                break;
            } else {
                myn = i;
            }
        }
        printf("%lld\n", poly(coeff, myn+1));
    }

    return 0;
}

