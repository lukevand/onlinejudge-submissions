#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int main() {
    int N, M;
    while (scanf("%d", &N) != EOF) {
        vector<int> v(N);
        for (int i=0; i<N; i++) {
            scanf("%d", &v[i]);
        }
        scanf("%d", &M);
        sort(begin(v), end(v));
        pair<int,int> best;
        int diff = INT_MAX;
        for (int i=0; i<N; i++) {
            auto x = lower_bound(begin(v)+i+1, end(v), M-v[i]);
            int j = x - begin(v);
            if (x != end(v) && v[j] == M-v[i] && j != i) {
                if (abs(v[j] - v[i]) < diff) {
                    diff = abs(v[j] - v[i]);
                    best = {min(*x, v[i]), max(*x, v[i])};
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", best.first, best.second);
    }
}

