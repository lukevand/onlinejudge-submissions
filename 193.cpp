#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<II> VII;

int n, k;
int a, b;
bitset<110> visited;
bitset<110> black;
VVI G;
int best;
VI bestPath;

bool canColor(int p) {
    for (int v: G[p]) {
        if (black[v]) return false;
    }
    return true;
}

void dfs(int cur, VI soFar) {
    if (cur > best) {
        print(cur);
        best = soFar.size();
        bestPath = soFar;
    }
    if (cur == n-1) return;

    for (int v=0; v<n; v++) {
        if (!black[v] && canColor(v)) {
            black[v] = 1;
            soFar.push_back(v);
            dfs(cur+1, soFar);
            soFar.pop_back();
            black[v] = 0;
        }
    }
}

int main() {
    int m;
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &n, &k);
        G.assign(n, VI());
        visited.reset();
        best = -1;
        bestPath.clear();
        for (int i=0; i<k; i++) {
            scanf("%d %d", &a, &b);
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(0, VI());
        printf("%d\n", best);
        for (int i=0; i<best; i++) {
            printf(i==best-1 ? "%d" : "%d ", bestPath[i]+1);
        }
        printf("\n");
    }
}
