#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; scanf("%d", &T);
    for (int i=1; i<=T; i++) {
        long N; scanf("%ld", &N);

        long p = N*(N-1)/2;

        printf("Case %d: ", i);
        if (p % 2 == 0) {
            printf("%ld\n", p/2);
        } else {
            printf("%ld/%d\n", p, 2);
        }
    }

}
