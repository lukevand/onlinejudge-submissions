#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int s, d, total;
int localSum;
int best;
vector<int> soFar;

void solve(int p, int pathCost) {
    /* print(p << " " << pathCost); */
    /* for (auto x: soFar) { cout << x << " "; }; cout << '\n'; */

    if (p >= 5) {
        localSum = 0;
        for (int i=p-5; i<p; i++) {
            localSum += soFar[i];
        }
        if (localSum >= 0) return;
    }

    if (p >= 12) {
        best = max(pathCost, best);
        return;
    }

    soFar[p] = s;
    solve(p+1, pathCost + s);

    soFar[p] = -d;
    solve(p+1, pathCost - d);
}

int main() {
    while (scanf("%d %d", &s, &d) != EOF) {
        soFar.clear();
        soFar.assign(12, 0);
        best = INT_MIN;
        solve(0, 0);
        if (best >= 0) printf("%d\n", best);
        else printf("Deficit\n");
    }
    return 0;
}

