#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

const int MAX = 50001;
int G[MAX], memo[MAX];
bitset<MAX> seen;

int dfs(int u) {
    seen[u] = true;
    int ans = 0;
    if (!seen[G[u]]) {
        ans = 1 + dfs(G[u]);
    }
    seen[u] = false;
    return memo[u] = ans;
}

int main() {
    int T; scanf("%d", &T);
    for (int TC=1; TC<=T; TC++) {
        int N; scanf("%d", &N);
        seen.reset();
        int x, y;
        for (int i=1; i<=N; i++) {
            scanf("%d %d", &x, &y);
            G[x] = y;

            memo[i] = -1;
        }

        int best = -1;
        int bestname = -1;
        for (int i=1; i<=N; i++) {
            /* printf("%d\n", best); */
            if (memo[i] == -1) {
                dfs(i);
            }

            if (memo[i] > best) {
                best = memo[i];
                bestname = i;
            }

        }
        printf("Case %d: %d\n", TC, bestname);
    }
}

