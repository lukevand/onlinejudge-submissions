#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
const int INF = 1e9;
int m, n, t;

int memo[10010];

int dp(int i) {
    if (i == t) {
        return 0;
    }
    if (i > t) return -INF;
    int &ans = memo[i];
    if (ans != -1) return ans;
    return ans = max({
            dp(i+1),
            1 + dp(i+m),
            1 + dp(i+n)
    });
}

int main() {
    while (scanf("%d %d %d", &m, &n, &t) != EOF) {
        memset(memo, -1, sizeof memo);
        memo[0] = 0;
        for (int i=0; i<=t; i++) {
            if (memo[i] != -1) {
                memo[i+m] = max(memo[i]+1, memo[i+m]);
                memo[i+n] = max(memo[i]+1, memo[i+n]);
            }
        }

        /* dp(0); */
        /* printf("%d %d\n", memo[0], 7); */
        for (int i=0; i<t+5; i++) {
            printf("%d ", memo[i]);
        }
        printf("\n");
        print(memo[t]);
    }
}

