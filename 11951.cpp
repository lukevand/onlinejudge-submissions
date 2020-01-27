#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
const int MAX = 101;
typedef long long L;

int main() {
    int T; scanf("%d", &T);
    for (int TC=1; TC<=T; TC++) {
        L A[MAX][MAX];
        int N, M, K; scanf("%d %d %d", &N, &M, &K);
        L smallest = INT_MAX;
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                scanf("%lld", &A[i][j]);
                smallest = min(smallest, A[i][j]);
                if (i > 0) A[i][j] += A[i-1][j];
                if (j > 0) A[i][j] += A[i][j-1];
                if (i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
            }
        }
        if (smallest > K) {
            printf("Case #%d: %d %d\n", TC, 0, 0);
            continue;
        }

        L bestArea = -123456789;
        L bestCost = INT_MAX;
        for (int i=0; i<N; ++i)
            for (int j=0; j<M; ++j) {
                for (int k=i; k<N; k++) {
                    for (int l=j; l<M; ++l) {
                        L subRect = A[k][l];

                        if (i > 0) subRect -= A[i-1][l];
                        if (j > 0) subRect -= A[k][j-1];
                        if (i > 0 && j > 0) subRect += A[i-1][j-1];
                        if (subRect > K) break;
                        int area = ((k-i+1) * (l-j+1));
                        if (area > bestArea) {
                            bestArea = area;
                            bestCost = subRect;
                        } else if (area == bestArea) {
                            bestCost = min(bestCost, subRect);
                        }
                    }
                }
            }
        printf("Case #%d: %lld %lld\n", TC, bestArea, bestCost);
    }

}

