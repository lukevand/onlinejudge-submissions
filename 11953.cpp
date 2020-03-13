#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int T, N;
vector<vector<char>> G;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool ok(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N;
}

void dfs(int i, int j) {
    G[i][j] = 'A';
    for (int k=0; k<4; k++) {
        int u = i+dy[k];
        int v = j+dx[k];
        if (ok(u, v) && (G[u][v] == 'x' || G[u][v] == '@')) {
            dfs(u, v);
        }
    }
}

int main() {
    scanf("%d", &T);
    for (int TC=1; TC<=T; TC++) {
        scanf("%d", &N);
        G.assign(N, vector<char>(N));
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                scanf(" %c ", &G[i][j]);
            }
        }

        int count = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (G[i][j] == 'x') {
                    count++;
                    dfs(i, j);
                }
            }
        }

        printf("Case %d: %d\n", TC, count);
    }
}

