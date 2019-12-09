#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int G[9][9];
int t, n;
int total;
int best;
int indexes[] = {0,1,2,3,4,5,6,7,8};

int main() {
    scanf("%d", &t);
    while (t--) {
        /* sort(indexes, indexes+9); */
        best = INT_MIN;
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                scanf("%d", &G[i][j]);
            }
        }
        do {
            total = 0;
            for (int i=0; i<n; i++) {
                total += G[i][indexes[i]];
            }
            best = max(best, total);
        } while (next_permutation(indexes, indexes+n));
        printf("%d\n", best);
    }
    return 0;
}

