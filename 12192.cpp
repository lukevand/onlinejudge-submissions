#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
int M[502][502];
int n, m;

int bs(int x0, int y0, int q) {
    int mid = (lo + hi)/2;
    if (M[x0+mid][y0+mid] ==

void solve(int L, int H) {
    for (int i=0; i<n; i++) {
        auto x = lower_bound(M[i], M[i]+m, L);


int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m, n || m) {
        memset(M, 0, sizeof(M));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; j++) {
                cin >> M[i][j];
            }
        }
        int Q, L, U;
        cin >> Q;
        while (Q--) {
            cin >> L >> Q;
            solve(L, Q);
        }

    }

}

