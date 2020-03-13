#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<VI> VVI;

int n, k;
int a, b;
bitset<110> black;
VVI G;
size_t bestSize;
VI bestPath;

bool canColor(int p) {
    for (int v: G[p]) {
        if (black[v]) return false;
    }
    return true;
}

void dfs(int cur, VI soFar) {
    /* print(cur); */
    /* for (auto x : soFar) cout << x << ' '; */
    /* cout << '\n'; */
    if (cur ==  n) {
        if (soFar.size() > bestSize) {
            bestSize = soFar.size();
            bestPath = soFar;
        }
        return;
    }

    if (!black[cur] && canColor(cur)) {
        black[cur] = 1;
        soFar.push_back(cur);
        dfs(cur+1, soFar);
        black[cur] = 0;
        soFar.pop_back();
    }

    dfs(cur+1, soFar);
}

int main() {
    int m;
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &n, &k);
        G.assign(n, VI());
        bestSize = 0;
        bestPath.clear();
        for (int i=0; i<k; i++) {
            scanf("%d %d", &a, &b);
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(0, VI());
        printf("%lu\n", bestSize);
        for (size_t i=0; i<bestSize; i++) {
            printf(i==bestSize-1 ? "%d\n" : "%d ", bestPath[i]+1);
        }
    }
}
