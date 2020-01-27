#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int n;
int price;

int coin[110];

const int INF = (int) 1e9;
const int MAX = 20001;

int memo[MAX];

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &price);
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &coin[i]);
        }
        for (int i=1; i<MAX; i++) {
            memo[i] = INF;
        }
        for (int c=0; c<n; c++) {
            int C=coin[c];
            for (int i=MAX-C-1; i>=0; --i) {
                if (memo[i] < INF) {
                    memo[i+C] = min(memo[i]+1, memo[i+C]);
                }
            }

        }
        /* for (int i=0; i<21; i++) { */
        /*     printf("%d ", memo[i]); */
        /* } printf("\n"); */
        int i;
        for (i=price; memo[i]==INF; i++);
        /* printf("%d %d\n", i-1, memo[i-1]); */
        printf("%d %d\n", i, memo[i]);
        /* printf("%d %d\n", i+1, memo[i+1]); */
    }
}
