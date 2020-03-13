#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int x, k; scanf("%d %d", &x, &k);
        if ((x % k) == 0) {
            printf("%d %d\n", 0, k);
        } else if (k > x) {
            printf("%d %d\n", 0, x);
        } else {
            int q = x%k;
            int p = x/(x/k) - q;
            printf("%d %d\n", p, q);
        }
    }
}

