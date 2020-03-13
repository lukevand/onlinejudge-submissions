#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int main() {
    uint32_t n, k;
    while (scanf("%u %u", &n, &k) == 2) {
        double lognf=0, logkf=0, lognkf=0;
        for (uint32_t i=1; i<=n; i++) {
            lognf += log10(i);
            if (i == k) {
                logkf = lognf;
            }
            if (i == n-k) {
                lognkf = lognf;
            }

        }
        printf("%u\n", (uint32_t) (lognf - logkf - lognkf + 1));

    }
}

