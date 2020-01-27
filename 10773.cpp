#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
#define EPS 1e-9

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(3);
    int n;
    double d, v, u;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> d >> v >> u;
        double fast = d/u;
        if (u-v < EPS || u < EPS || v < EPS) {
            cout << "Case " << i << ": can't determine\n";
            continue;
        }
        double shortDist = d/sqrt(u*u - v*v);
        cout << "Case " << i << ": " << shortDist-fast<< '\n';
    }
}

