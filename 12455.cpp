#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int main() {
    int t, goal, p;
    scanf("%d", &t);
    while (t--) {
        bool done = false;
        scanf("%d %d", &goal, &p);
        vector<int> v(p);
        for (int i=0; i<p;i++) {
            scanf("%d", &v[i]);
        }
        for (int i=0; i<(1<<p); i++) {
            /* int pos = i; */
            int total = 0;
            for (int j=0; j<p; j++) {
                if ((i>>j) & 1) {
                    total += v[j];
                }
            }

            /* while (pos) { */
            /*     int ls = (pos & -pos); */
            /*     total += v[__builtin_ctz(ls)]; */
            /*     pos -= ls; */
            /* } */
            if (total == goal) {
                printf("YES\n");
                done = true;
                break;
            }
        }
        if (!done) printf("NO\n");
    }

    return 0;
}

