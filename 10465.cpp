#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
const int INF = 1e9;
int m, n, t;

int memo[10010];

int main() {
    while (scanf("%d %d %d", &m, &n, &t) != EOF) {
        memset(memo, -1, sizeof memo);

        memo[0] = 0;
        for (int i=0; i<t+5; i++) {
            int x = (i-n>=0) ? memo[i-n] + 1 : 0;
            int y = (i-m>=0) ? memo[i-m] + 1 : 0;
            int best = max(x, y);
            if (best > 0) {
                memo[i] = best;
            }
        }

        if (memo[t] >= 0) {
            printf("%d\n", memo[t]);
        } else {
            for (int i=t-1; i>=0; i--) {
                if (memo[i] >= 0) {
                    printf("%d %d\n", memo[i], t-i);
                    break;
                }
            }
        }
    }
}

