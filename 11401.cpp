#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef long ll;

const int MAX = (int) 1e6 + 10;
ll memo[MAX];

void solve() {
    for (int n=4; n<MAX; n++) {
        if ((n % 2) == 0) {
            ll h = n/2 - 2;
            memo[n] = memo[n-1] + h*(h+1) + n/2 - 1;
        } else {
            ll h = n/2 - 1;
            memo[n] = memo[n-1] + h*(h+1);
        }
    }
}

int main() {
    int N;
    memo[3] = 0;
    solve();
    while (scanf("%d", &N), N >= 3) {
        printf("%ld\n", memo[N]);
    }
}

