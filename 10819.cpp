#include <bits/stdc++.h>
using namespace std;
#define print(x)// cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;

VI value;
VI weight;

int memo[101][10001];
int m, n;

int dp(int cur, int w) {
    print(cur << " " << w);
    if (w > m && w > m + 200) return -1000;
    if (m < 1800 && w > m) return -1000;
    if (cur == n) {
        if (w > m && w <= 2000) return -1000;
        return 0;
    }
    int &ans = memo[cur][w];
    if (ans != -1) return ans;
    return ans = max(dp(cur+1, w), value[cur] + dp(cur+1, w+weight[cur]));
}

int main() {
    while (scanf("%d %d", &m, &n) != EOF) {
        memset(memo, -1, sizeof memo);
        value.assign(n, 0);
        weight.assign(n, 0);
        for (int i=0; i<n; ++i) {
            scanf("%d %d", &weight[i], &value[i]);
        }
        printf("%d\n", dp(0, 0));
    }
}

