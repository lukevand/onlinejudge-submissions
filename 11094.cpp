#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

#define DONE 1

vector<vector<char>> G;
int M, N;
int X, Y;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool ok(int i) {
    if (i < 0 || i >= M) return false;
    return true;
}

int wrap(int j) {
    return (j+3*N)%N;
}


int dfs(int i, int j, char start) {
    /* print(i << ' ' << j << ' ' << start); */
    G[i][j] = DONE;

    int this_island = 0;
    if (i == X && j == Y) this_island = -1000000;
    for (int k=0; k<4; k++) {
        int nexti = i+dx[k];
        int nextj = wrap(j+dy[k]);
        if (ok(nexti) && G[nexti][nextj] == start) {
            this_island += 1 + dfs(nexti, nextj, start);
        }
    }
    return this_island;
}


int main() {
    while (scanf("%d %d", &M, &N) != EOF) {
        G.assign(M, vector<char>(N));
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                scanf(" %c ", &G[i][j]);
            }
        }
        scanf("%d %d", &X, &Y);

        int best = 0;
        int land = G[X][Y];
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                if (G[i][j] == land) {
                    int count = dfs(i, j, G[i][j])+1;
                    best = max(best, count);
                }
            }
        }
        printf("%d\n", best);
    }
}

