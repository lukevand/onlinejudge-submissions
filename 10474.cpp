#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;

int main() {
    int N, Q, q;
    int TC = 0;
    while (scanf("%d %d", &N, &Q), N | Q) {
        VI v(N);
        for (int i=0; i<N; i++) {
            scanf("%d", &v[i]);
            /* v.insert(x); */
        }
        printf("CASE# %d:\n", ++TC);
        sort(begin(v), end(v));
        for (int i=0; i<Q; i++) {
            scanf("%d", &q);
            auto x = lower_bound(begin(v), end(v), q);
            if (v[x-begin(v)] == q) {
                printf("%d found at %ld\n", q, 1+(x - begin(v)));
            } else {
                printf("%d not found\n", q);
            }
        }
    }
}

