#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;
VI v, st;

/* void build(int p, int L, int R) { */
/*     if (L == R) st[p] = L; */
/*     else { */
/*         int m = (L+R)/2; */
/*         build(2*p, L, m); */
/*         build(2*p+1, m+1, R); */
/*         st[p] = conquer(st[2*p], st[2*p+1]); */
/*     } */
/* } */

int main() {
    int n, q, query;
    while (scanf("%d %d", &n, &q), n) {
        v.clear(); v.resize(n);
        st.clear(); st.resize(4*n);
        VI cf(n);
        for (int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }

        cf[0] = st[0];
        for (int i=1; i<n; i++) {
            cf[i] = cf[i-1] + st[i];
        }
        /* build(1, 0, n-1); */
        for (int i=0; i<q; i++) {
            scanf("%d", &query);
        }
    return 0;
}

