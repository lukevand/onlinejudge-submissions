#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
int m, S;
int conven[45];
int infotech[45];
const int INF = (int)1e9;

int memo[1000][1000];

int dp(int v1, int v2) {
    int v = v1*v1 + v2*v2 - S*S;
    if (v > 0) return INF;
    if (v == 0) return 0;
    int &ans = memo[v1][v2];
    if (ans!=-1) return ans;
    ans = INF;
    for (int i=0; i<m; i++) {
        ans = min(1+dp(v1+conven[i], v2+infotech[i]), ans);
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &m, &S);
        memset(memo, -1, sizeof memo);
        for (int i=0; i<m; i++) {
            scanf("%d %d", &conven[i], &infotech[i]);
        }
        int ans = dp(0, 0);
        if (ans < INF) {
            printf("%d\n", ans);
        } else {
            printf("not possible\n");
        }
    }
}

