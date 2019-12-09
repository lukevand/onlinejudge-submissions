#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int main() {
    long long N, A, B, C;
    scanf("%lld", &N);
    while (N--) {
        bool done = false;
        scanf("%lld %lld %lld", &A, &B, &C);
        for (long long x=-100; x<=100; x++) {
            if (x*x > C) continue;
            for (long long y=-100; y<=100; y++) {
                if (x == y || x*x + y*y > C) continue;
                for (long long z=-100; z<=100; z++) {
                    if (z == x || z == y) continue;
                    if (x+y+z == A && (x*y*z == B) && ((x*x + y*y + z*z) == C)) {
                        printf("%lld %lld %lld\n", x, y, z);
                        done = true;
                        break;
                    }
                }
                if (done) break;
            }
            if (done) break;
        }
        if (!done) {
            printf("No solution.\n");
        }
    }

    return 0;
}

