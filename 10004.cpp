#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

#define UNDEF 0
#define BLACK 1
#define WHITE 2

typedef vector<int> VI;
typedef vector<VI> VVI;

VVI G;
vector<int> color;

int main() {
    int n;
    while (scanf("%d", &n), n) {
        int l; scanf("%d", &l);
        G.assign(n, VI());
        color.assign(n, -1);
        while (l--) {
            int x, y;
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }

        queue<int> q;
        q.push(0);
        bool isBipartite = true;
        while (!q.empty() && isBipartite) {
            int u = q.front(); q.pop();

            for (int v: G[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    isBipartite = false;
                    break;
                }
            }
        }
        if (isBipartite) {
            printf("BICOLORABLE.\n");
        } else {
            printf("NOT BICOLORABLE.\n");
        }


    }

}

