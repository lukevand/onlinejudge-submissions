#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
#define MOD 1000000

int memo[(int)1e6+5];

int solve(int i) {
    int &ans = memo[i];
    if (ans != -1) return ans;
    return ans = (solve(floor(i - sqrt(i))) + solve(floor(log(i))) + solve(floor(i*pow(sin(i), 2.0)))) % MOD;
}

int main() {
    int n;
    memset(memo, -1, sizeof memo);
    memo[0] = 1;
    while (scanf("%d", &n), n != -1) {
        printf("%d\n", solve(n));
    }
}

