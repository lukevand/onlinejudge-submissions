#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef uint64_t ll;

ll memo[50];

ll f(int n) {
    ll &ans = memo[n];
    if (ans != 0) return ans;
    return ans = 4*f(n-2) + 2*f(n-3) + f(n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(memo, 0, sizeof memo);
    memo[0] = 1; memo[1] = 1; memo[2] = 5;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        printf("%lu\n", f(n));
    }
}

