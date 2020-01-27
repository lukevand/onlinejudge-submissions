#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;
typedef long long L;

VI A;
int N;

L memo[201][21][201][21];

L mod(L x, L y) {
    return (x%y + y)%y;
}

L dp(int idx, L sum, int remaining, int &D) {
    /* print(idx << " " << sum << " " << remaining); */
    if (remaining == 0) {
        if (sum == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    if (idx == N) {
        return 0;
    }
    L &ans = memo[idx][sum][remaining][D];
    if (ans != -1) return ans;

    return ans = dp(idx+1, sum, remaining, D) + dp(idx+1, mod(sum+A[idx],D), remaining-1, D);
}



int main() {
    int Q;
    int TC=0;
    while (scanf("%d %d", &N, &Q), N || Q) {
        memset(memo, -1, sizeof memo);
        A.assign(N, 0);
        for (int i=0; i<N; i++) {
            scanf("%d", &A[i]);
        }
        printf("SET %d:\n", ++TC);
        for (int i=1; i<=Q; i++) {
            /* memset(memo, -1, sizeof memo); */
            int M, D; scanf("%d %d", &D, &M);
            printf("QUERY %d: %lld\n", i, dp(0, 0LL, M, D));
        }
    }
}

