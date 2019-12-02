#include <bits/stdc++.h>
using namespace std;

#define MILLION 1000001

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m), n | m) {
        bitset<MILLION> b;
        int s, e, r;
        bool conflict = false;
        for (int j=0; j<n; j++) {
            scanf("%d %d", &s, &e);
            if (conflict) continue;
            for (int i=s; i<e; i++) {
                if (!b[i]) {
                    b[i] = 1;
                } else {
                    printf("CONFLICT\n");
                    conflict = true;
                    break;
                }
            }
        }

        for (int k=0; k<m; k++) {
            scanf("%d %d %d", &s, &e, &r);
            if (conflict) continue;
            int numTimes = MILLION/r + 1;
            for (int j=0; j<numTimes && !conflict; j++) {
                for (int i=s+j*r; i<min(e+j*r, MILLION); i++) {
                    if (!b[i]) {
                        b[i] = 1;
                    } else {
                        printf("CONFLICT\n");
                        conflict = true;
                        break;
                    }
                }
            }
        }

        if (conflict) {
            continue;
        } else {
            printf("NO CONFLICT\n");
        }

    }

    return 0;
}

