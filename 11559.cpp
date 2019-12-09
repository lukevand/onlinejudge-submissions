#include <bits/stdc++.h>
using namespace std;
#define INF ((int) 1e9)

int main() {
    int N, budget, H, W;
    int price, available;
    while (scanf("%d %d %d %d", &N, &budget, &H, &W) == 4) {
        int best = INF;
        for (int i=0; i<H; i++) {
            scanf("%d", &price);
            for (int j=0; j<W; j++) {
                scanf("%d", &available);
                if (N > available) continue;
                if (price*N <= budget) best = min(best, price*N);
            }
        }
        if (best!=INF) printf("%d\n", best);
        else printf("stay home\n");
    }
    return 0;
}

