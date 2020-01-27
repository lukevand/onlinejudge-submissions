#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int main() {
    int n;
    while (scanf("%d", &n), n) {
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }
        int best = 0;
        int thisRun = 0;
        for (int i=0; i<n; i++) {
            thisRun += v[i];
            best = max(best, thisRun);
            if (thisRun < 0) thisRun = 0;
        }
        if (best > 0) {
            printf("The maximum winning streak is %d.\n", best);
        } else {
            printf("Losing streak.\n");
        }
    }
}

