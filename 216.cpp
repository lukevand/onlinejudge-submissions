#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
#define LSOne(S) ((S) & -(S))

const int MAX_n = 8;
const int INF = (int)2e9;
int n;
int dist[MAX_n][MAX_n], memo[MAX_n][1<<(MAX_n)];

int square(int x) { return x*x; }

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
        int x[MAX_n], y[MAX_n];
        /* scanf("%d %d", &x[0], &y[0]); */
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d %d", &x[i], &y[i]);
        }

        for (int i=0; i<n; ++i) {
            for (int j=i; j<n; ++j) {
                dist[i][j] = dist[j][i] = square(x[i]-x[j]) + square(y[i]-y[j]);
            }
        }
        memset(memo, -1, sizeof memo);
        int best = 0;
        for (int i=0; i<n; i++) {
            int thisdp = dp(i, 1<<i);
            print(thisdp);
            if (thisdp > best) {
                best = thisdp;
            }
        }
        /* printf("The shortest path has length %d\n", dp(0, 1)); */
    }
}

