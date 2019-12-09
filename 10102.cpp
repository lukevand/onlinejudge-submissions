#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;

int main() {
    int M;
    int c;
    while (scanf("%d", &M) != EOF) {
        VII ones;
        VII threes;
        for (int i=0; i<M; i++) {
            for (int j=0; j<M; j++) {
                scanf("%1d", &c);
                if (c == 1) {
                    ones.emplace_back(i, j);
                } else if (c == 3) {
                    threes.emplace_back(i, j);
                }
            }
        }

        int best = -1;
        for (II one: ones) {
            int localBest = INT_MAX-10;
            for (II three : threes) {
                localBest = min(localBest, abs(one.first - three.first) + abs(one.second - three.second));
            }
            best = max(localBest, best);
        }
        printf("%d\n", best);
    }

    return 0;
}

