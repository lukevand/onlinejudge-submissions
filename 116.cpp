#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

long G[10][100];
int pred[10][100];
long memo[10][100];
bool seen[10][100];

int n, m;

int new_dir(int i, int dir) {
    return (i + dir + 2*n) % n;
}

long solve(int i, int j) {
    /* print(i << ' ' << j << ' ' << soFar); */
    if (j == 0) {
        return G[i][j];
    }

    if (seen[i][j]) return memo[i][j];

    long best = INT_MAX;
    for (int dir=-1; dir<=1; dir++) {
        int v = new_dir(i, dir);
        /* print("j="<<j<<" " <<i << " to " << v); */
        long re = G[i][j]+solve(v, j-1);
        if (re < best) {
            best = re;
            pred[i][j] = v;
        }
    }
    seen[i][j] = true;
    return memo[i][j] = best;
}

int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                scanf("%ld", &G[i][j]);
            }
        }
        memset(memo, -1, sizeof memo);
        memset(seen, 0, sizeof seen);
        for (int i=0; i<n; i++) {
            memo[i][0] = G[i][0];
        }
        long best = INT_MAX;
        for (int i=0; i<n; i++) {
            best = min(best, solve(i, m-1));
        }

        // print best path
        vector<int> path;
        for (int i=0; i<n; i++) {
            if (memo[i][m-1] == best) {
                path.push_back(i);
                break;
            }
        }
        for (int j=m-2; j>=0; j--) {
            long localmin = LONG_MAX;
            int bestrow;

            vector<int> mydirs;
            for (int dir=-1; dir<=1; dir++) {
                int v = new_dir(path[m-2-j], dir);
                mydirs.push_back(v);
            }
            sort(mydirs.begin(), mydirs.end());
            for (int v: mydirs) {
                if (memo[v][j] <= localmin) {
                    localmin = memo[v][j];
                    bestrow = v;
                }

            }
            path.push_back(bestrow);
        }
        reverse(path.begin(), path.end());
        for (size_t i=0; i<path.size()-1; i++) {
            printf("%d ", path[i]+1);
        }
        printf("%d\n", path[path.size()-1]+1);

        printf("%ld\n", best);
    }
    return 0;
}

