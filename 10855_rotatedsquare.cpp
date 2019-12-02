#include <bits/stdc++.h>
using namespace std;

typedef vector<string> VS;

vector<int> total(4, 0);

void check(const VS& big, const VS& small, const int& n, const int& a, const int& b) {
    bitset<4> bits;
    bits.set();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (bits[0] && big[a+i][b+j] != small[i][j]) {
                bits[0] = 0;
            }
            if (bits[1] && big[a+i][b+j] != small[n-1-j][i]) {
                bits[1] = 0;
            }
            if (bits[2] && big[a+i][b+j] != small[n-1-i][n-1-j]) {
                bits[2] = 0;
            }
            if (bits[3] && big[a+i][b+j] != small[j][n-1-i]) {
                bits[3] = 0;
            }
        }
    }
    for (int i=0; i<4; i++) {
        if (bits[i]) {
            total[i] += bits[i];
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, n;
    while (cin >> N >> n, N || n) {
        total.assign(4, 0);
        VS M(N);
        for (int i=0; i<N; i++) {
            cin >> M[i];
        }
        VS m(n);
        for (int i=0; i<n; i++) {
            cin >> m[i];
        }
        for (int i=0; i<N-n+1; i++) {
            for (int j=0; j<N-n+1; j++) {
                check(M, m, n, i, j);
            }
        }
        cout << total[0] << " " << total[1] << " " << total[2] << " " << total[3] << '\n';
    }

    return 0;
}

