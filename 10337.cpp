#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
int X;
int w;
const int INF = (int)1e9;

int M[11][1001];
int memo[11][1001];

int dp(int j, int h) {
    if (h < 0 || h >= 10) return INF;
    if (j == w) {
        if (h == 0) return 0;
        if (h > 0) return INF;
    }
    int &ans = memo[h][j];
    if (ans != -1) return ans;
    return ans = min({
            60 - M[h][j] + dp(j+1, h+1),
            30 - M[h][j] + dp(j+1, h),
            20 - M[h][j] + dp(j+1, h-1)
    });
}

int main() {
    int N; scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        w = X/100;
        memset(memo, -1, sizeof memo);
        for (int i=9; i>=0; i--) {
            for (int j=0; j<w; j++) {
                scanf("%d", &M[i][j]);
            }
        }
        printf("%d\n\n", dp(0, 0));
    }
}

