#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

#define MAX 12
bitset<12> visited;
int G[MAX][MAX];
int m, n;
bool done;

void dfs(int cur, vector<int> soFar) {
    soFar.push_back(cur);
    if ((int)soFar.size() == n+1) {
        done = true;
        printf("(");
        for (int i=0; i<(int)soFar.size(); i++) {
            printf("%d", soFar[i]+1);
            if (i < (int)soFar.size()-1) {
                printf(",");
            }
        }
        printf(")\n");
        return;
    }
    for (int j=0; j<m; j++) {
        if (G[cur][j] != 0 && !visited[j]) {
            visited[j] = 1;
            dfs(j, soFar);
            visited[j] = 0;
        }
    }
}

int main() {
    while (scanf("%d %d", &m, &n) == 2) {
        visited.reset();
        done = false;
        memset(G, 0, sizeof G);
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                scanf("%d", &G[i][j]);
            }
        }
        visited[0] = 1;
        dfs(0, vector<int>());
        if (!done) {
            printf("no walk of length %d\n", n);
        }

        scanf("%d", &m);
        if (m == -9999) printf("\n");
    }
}

