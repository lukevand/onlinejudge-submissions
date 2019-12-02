#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int V = 1<<N;
        int best = -1;
        vector<int> v(V);
        vector<int> cornerSum(V);

        for (int i=0; i<V; i++) {
            scanf("%d", &v[i]);
        }

        for (int i=0; i<V; i++) {
            int cur = 0;
            for (int j=0; j<N; j++) {
                cur += v[i^(1<<j)];
            }
            cornerSum[i] = cur;
        }

        for (int i=0; i<V; i++) {
            for (int j=0; j<N; j++) {
                best = max(best, cornerSum[i]+cornerSum[i^(1<<j)]);
            }
        }


        printf("%d\n", best);
    }

    return 0;
}

