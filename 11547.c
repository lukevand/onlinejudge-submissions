#include <stdio.h>

int abs(int n) {
    return n >= 0 ? n : -n;
}

int f(int n) {
    int tmp = (((n * 567.0)/9.0 + 7492) * 235.0 / 47.0) - 498;
    return abs((tmp/10) % 10);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", f(n));
    }
    return 0;
}
