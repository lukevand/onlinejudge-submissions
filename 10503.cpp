#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;
typedef pair<int,int> II;
typedef vector<II> VII;

VII doms;
bitset<30> used;
II l;
II r;
int n, m, a, b;

bool dfs(int cur, int val) {
    if (cur == n && (val == r.first)) {
        return true;
    } else if (cur >= n) return false;

    for (int i=0; i<m; i++) {
        II dom = doms[i];
        if (!used[i]) {
            used[i] = 1;
            if (dom.first == val) {
                if (dfs(cur+1, dom.second)) return true;
            } else if (dom.second == val) {
                if (dfs(cur+1, dom.first)) return true;
            }
            used[i] = 0;
        }
    }
    return false;
}

int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        doms.clear();
        used.reset();
        scanf("%d %d", &a, &b);
        l = {a, b};
        scanf("%d %d", &a, &b);
        r = {a, b};
        for (int i=0; i<m; i++) {
            scanf("%d %d", &a, &b);
            doms.emplace_back(a, b);
        }

        if (dfs(0, l.second)) printf("YES\n");
        else printf("NO\n");
    }
}

