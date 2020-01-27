#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int A[101];
int m;
int limit;

int memo[110][50100];

int dp(int i, int w) {
    if (i == m) return 0;
    int& ans = memo[i][w];
    if (ans != -1) return ans;
    if (w + A[i] > limit) return ans = dp(i+1, w);
    return ans = max(dp(i+1, w), A[i] + dp(i+1, w+A[i]));
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &m);
        int total = 0;
        memset(memo, -1, sizeof memo);
        for (int i=0; i<m; i++) {
            scanf("%d", &A[i]);
            total += A[i];
        }
        limit = total/2;
        int x = dp(0, 0);
        printf("%d\n", abs(x - (total-x)));
    }
}

