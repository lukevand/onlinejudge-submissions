#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;
int A[2005];
VI LIS;
VI LDS;
int TC, n, localMax;

int main() {
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++)
            scanf("%d", &A[i]);
        int best=0;
        LIS.assign(n, 1);
        LDS.assign(n, 1);
        /* LIS[n-1]=1; LDS[n-1] = 1; */

        for (int i=n-1; i>-1; --i) {
            for (int j=n-1; j>i; --j) {
                if (A[j] > A[i]) {
                    LIS[i] = max(LIS[i], LIS[j]+1);
                }
                if (A[j] < A[i]) {
                    LDS[i] = max(LDS[i], LDS[j]+1);
                }
            }
            best = max(best, LIS[i]+LDS[i]-1);
        }
        printf("%d\n", best);
    }

}

