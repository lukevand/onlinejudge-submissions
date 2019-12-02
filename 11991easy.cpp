#include <bits/stdc++.h>
using namespace std;

#define print(x) cout << "DEBUG: " << x << '\n'

typedef vector<int> VI;
typedef vector<VI> VVI;

int main() {
    int n, m;
    int a;
    while (scanf("%d %d", &n, &m) != EOF) {
        VVI G(n);
        unordered_map<int,VI> M;
        for (int i=0; i<n; i++) {
            scanf("%d", &a);
            auto p = M.emplace(a, VI(1, i+1));
            if (!p.second) {
                M[a].push_back(i+1);
            }
        }
        int b;
        for (int i=0; i<m; i++) {
            scanf("%d %d", &a, &b);
            a--;
            if (a < M[b].size()) {
                printf("%d\n", M[b][a]);
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}

