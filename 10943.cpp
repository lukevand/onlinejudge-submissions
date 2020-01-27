#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
#define MOD 1000000
int N, K;

int memo[1002][1002];

int dp(int n, int k) {
    if (k == 1) return 1;
    if (memo[n][k] != -1) return memo[n][k];
    int ans = 0;
    for (int i=0; i<=n; i++) {
        ans += dp(n-i, k-1);
        ans %= MOD;
    }
    return memo[n][k] = ans;
}

int main() {
    memset(memo, -1, sizeof memo);
    while (scanf("%d %d", &N, &K), N) {
        printf("%d\n", dp(N, K)%MOD);
    }
}

