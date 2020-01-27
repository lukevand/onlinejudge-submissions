#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;
#define ALL(x) begin(x), end(x)

int main() {
    int n, d, r;
    ios::sync_with_stdio(false);
    while (cin >> n >> d >> r, n) {
        VI m(n);
        VI a(n);
        for (int &i: m) cin >> i;
        for (int &i: a) cin >> i;
        sort(ALL(m));
        sort(ALL(a), greater<int>());
        int tot = 0;
        for (int i=0; i<n; i++) {
            int over = m[i] + a[i];
            tot += max(over-d, 0);
        }
        printf("%d\n", tot*r);
    }

}

