#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        printf("%d\n", k^(k>>1));
    }
    return 0;
}

