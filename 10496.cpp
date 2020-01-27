#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
#define LSOne(S) ((S) & -(S))

const int MAX_n = 11;
const int INF = (int)2e9;
int n;
int dist[MAX_n][MAX_n], memo[MAX_n][1<<(MAX_n)];

int dp(int u, int mask) {
    if (mask == (1<<n)-1) return dist[u][0];
    int &ans = memo[u][mask];
    if (ans != -1) return ans;
    ans = INF;
    for (int nxt=0; nxt<n; ++nxt) {
        if ((mask & (1 << nxt))==0 && nxt != u) {
            ans = min(ans, dist[u][nxt] + dp(nxt, mask | (1 << nxt)));
        }
    }
    return ans;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int xsize, ysize; scanf("%d %d", &xsize, &ysize);
        int x[MAX_n], y[MAX_n];
        scanf("%d %d", &x[0], &y[0]);
        scanf("%d", &n); ++n;
        for (int i=1; i<n; i++) {
            scanf("%d %d", &x[i], &y[i]);
        }

        for (int i=0; i<n; ++i) {
            for (int j=i; j<n; ++j) {
                dist[i][j] = dist[j][i] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            }
        }
        memset(memo, -1, sizeof memo);
        printf("The shortest path has length %d\n", dp(0, 1));
        /* printf("The shortest path has length %d\n", dp(0, (1<<(n-1))-1)); */
    }
}

