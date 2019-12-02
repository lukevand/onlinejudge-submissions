#include <bits/stdc++.h>
using namespace std;
typedef long long L;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        L s, d;
        scanf("%lld %lld\n", &s, &d);
        L x = (s+d)/2;
        L y = s-x;
        if (y < 0 || ((s+d)%2 != 0)) {
            printf("impossible\n");
        } else {
            printf("%lld %lld\n", x, y);
        }
    }
    return 0;
}

