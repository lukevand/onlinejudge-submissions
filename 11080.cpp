#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;

vector<VI> G;
VI color;

int dfs(int u) {
    queue<int> q;
    q.push(u);
    color[u] = 0;
    int c = 0;
    int t = 0;
    while (!q.empty()) {
        int w = q.front(); q.pop();
        t++;
        if (color[w] == 0) c++;
        for (int v: G[w]) {
            if (color[v] == -1) {
                color[v] = 1 - color[w];
                q.push(v);
            } else if (color[v] == color[w]) {
                return -1;
            }
        }
    }
    if (t == 1) return 1;
    return min(t-c,c);
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int v, e; scanf("%d %d", &v, &e);
        G.assign(v, VI());
        color.assign(v, -1);
        bool bad = false;
        while (e--) {
            int f, t; scanf("%d %d", &f, &t);
            G[f].push_back(t);
            G[t].push_back(f);
        }
        int total = 0;
        for (int i=0; i<v; i++) {
            if (color[i] == -1) {
                int re = dfs(i);
                if (re < 0) {
                    bad = true;
                    break;
                }
                total += re;
            }
        }
        if (bad) {
            printf("-1\n");
        } else {
            printf("%d\n", total);
        }
    }


}

