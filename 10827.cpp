#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
const int N = 80;
int A[2*N][2*N];

int main() {
    int TC, n;
    scanf("%d", &TC);
    while (TC--) {
        int biggest = INT_MIN;
        scanf("%d", &n);
        /* memset(A, 0, sizeof A); */
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                scanf("%d", &A[i][j]);
                biggest = max(A[i][j], biggest);
                A[i+n][j] = A[i][j];
                A[i][j+n] = A[i][j];
                A[i+n][j+n] = A[i][j];
            }
        }
        if (biggest < 0) {
            printf("%d\n", biggest);
            continue;
        }

        for (int i=0; i<2*n; i++) {
            for (int j=0; j<2*n; j++) {
                if (j > 0) A[i][j] += A[i][j-1];
            }
        }

        /* for (int i=0; i<2*n; i++) { */
        /*     for (int j=0; j<2*n; j++) { */
        /*         printf("%d ", A[i][j]); */
        /*     } */
        /*     printf("\n"); */
        /* } */

        int maxSubRect = INT_MIN;                 // lowest possible val
        for (int l = 0; l < n; ++l)
            for (int r = l; r < min(2*n-1, n+l); ++r) {
                for (int k=0; k<n; k++) {
                    int subRect = 0;
                    for (int row = k; row < n+k; ++row) {
                        if (l > 0) subRect += A[row][r] - A[row][l-1];
                        else       subRect += A[row][r];
                        if (subRect < 0) subRect = 0;
                        maxSubRect = max(maxSubRect, subRect);
                    }
                }
            }
        printf("%d\n", maxSubRect);
    }
}

