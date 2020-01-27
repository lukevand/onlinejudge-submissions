#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;

int N, x, T, K;

VI cost;
VI value;

int memo[101][1102][102];

int dp(int i, int total, int count) {
    /* print(i << " " << total << " " << count); */
    if (count > 2*(N+1)) return INT_MIN;

    int finaltotal = (int)ceil(((double)(total + (1+N)*T)) * 1.1L);
    if (finaltotal > x*(N+1)) return INT_MIN;

    if (i == K) return 0;

    int &ans = memo[i][total][count];
    if (ans != -1) return ans;

    return ans = max({
            dp(i+1, total, count),
            value[i] + dp(i+1, total+cost[i], count+1),
            2*value[i] + dp(i+1, total+2*cost[i], count+2)
    });
}


int main() {
    while (scanf("%d %d %d %d", &N, &x, &T, &K), N || x || T || K) {
        cost.assign(K, 0);
        value.assign(K, 0);
        memset(memo, -1, sizeof memo);

        for (int i=0; i<K; i++) {
            scanf("%d", &cost[i]);
            int s = 0, a;

            for (int j=0; j<=N; j++) {
                scanf("%d", &a);
                s += a;
            }
            value[i] = s;
        }

        printf("%.2f\n", (double)dp(0, 0, 0) / (double)(N+1));
    }
}

