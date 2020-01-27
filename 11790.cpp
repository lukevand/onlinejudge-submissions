#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;

int main() {
    int T; scanf("%d", &T);
    for (int TC=1; TC<=T; TC++) {
        int N; scanf("%d", &N);
        if (N == 0) {
            printf("Case %d. Increasing (0). Decreasing (0).\n", TC);
            continue;
        }
        VI H(N);
        VI W(N);
        for (int i=0; i<N; i++) scanf("%d", &H[i]);
        for (int i=0; i<N; i++) scanf("%d", &W[i]);

        VI L(W);
        VI LD(W);
        int lis = W[0];
        int lds = W[0];

        for (int i=0; i<N; i++) {
            for (int j=0; j<i; j++) {
                if (H[j] < H[i]) {
                    L[i] = max(L[i], W[i]+L[j]);
                }
                if (H[j] > H[i]) {
                    LD[i] = max(LD[i], W[i]+LD[j]);
                }
                lis = max(L[i], lis);
                lds = max(LD[i], lds);
            }
        }
        /* for (auto x : LD) printf("%d ", x); */
        /* printf("\n"); */
        if (lis >= lds) {
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", TC, lis, lds);
        } else {
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", TC, lds, lis);
        }
    }

}
