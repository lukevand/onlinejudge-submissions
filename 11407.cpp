#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
vector<int> squares;
int memo[10010];

int f(int n) {
    /* print(n); */
    if (memo[n] != -1) return memo[n];
    int best = INT_MAX;
    for (int i=1; ; i++) {
        if (squares[i] > n) break;
        best = min(1 + f(n - squares[i]), best);
    }
    return memo[n] = best;
}


int main() {
    int t; scanf("%d", &t);
    memset(memo, -1, sizeof memo);
    for (int i=0; i<=100; i++) {
        squares.push_back(i*i);
        memo[i*i] = 1;
    }
    while (t--) {
        int n; scanf("%d", &n);
        printf("%d\n", f(n));
    }
}

