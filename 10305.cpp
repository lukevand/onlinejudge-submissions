#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
int n, m;
vector<vector<int>> G;
bitset<101> has_incoming;
bitset<101> seen;
vector<int> result;

void dfs(int v) {
    seen[v] = 1;
    for (auto u: G[v]) {
        if (!seen[u]) dfs(u);
    }
    print(v);
    result.push_back(v);
}

int main() {
    while (scanf("%d %d", &n, &m), n || m) {
        G.assign(n+1, vector<int>());
        has_incoming.reset();
        seen.reset();
        result.clear();
        for (int i=1; i<=m; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
            has_incoming[y] = true;
            print(x);
        }
        print(G[1][0]);
        for (int i=1; i<=m; i++) {
            print(i);
            if (!has_incoming[i]) {
                dfs(i);
            }
        }
        for (size_t i=result.size()-1; i>0; i--) {
            printf("%d ", result[i]);
        }
        printf("%d\n", result[0]);
    }
}
