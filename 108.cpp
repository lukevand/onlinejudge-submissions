#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
int C[110][110];

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &C[i][j]);
            if (i > 0) C[i][j] += C[i-1][j];
            if (j > 0) C[i][j] += C[i][j-1];
            if (i > 0 && j > 0) C[i][j] -= C[i-1][j-1];
        }
    }
    int subRect;
    int best = INT_MIN;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=i; k<n; k++) {
                for (int l=j; l<n; l++) {
                    subRect = C[k][l];
                    if (i > 0) subRect -= C[i-1][l];
                    if (j > 0) subRect -= C[k][j-1];
                    if (i > 0 && j > 0) subRect += C[i-1][j-1];
                    best = max(best, subRect);
                }
            }
        }
    }
    printf("%d\n", best);
}

