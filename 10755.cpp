#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
const int MAX_SIZE = 20;

int main() {
    int TC; scanf("%d", &TC);
    int A, B, C;
    while (TC--) {
        scanf("%d %d %d", &A, &B, &C);
        int M[MAX_SIZE][MAX_SIZE][MAX_SIZE];
        for (int i=0; i<A; i++) {
            for (int j=0; j<B; j++) {
                for (int k=0; k<C; k++) {
                    scanf("%d", &M[i][j][k]);
                    if (j > 0) M[i][j][k] += M[i][j-1][k];
                    if (k > 0) M[i][j][k] += M[i][j][k-1];
                    if (k > 0 && j > 0) M[i][j][k] -= M[i][j-1][k-1];
                }
            }
        }

        for (int L=0; L<A; ++L) {
            for (int R=L; R<B; ++R) {
                for (int U=R; U<C; ++U) {
                    int subSq = 0;
                    for (int row=0; row<
    }

}

