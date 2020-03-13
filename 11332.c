#include <stdio.h>

int f(int n) {
    int total = 0;
    while (n > 0) {
        total += (n%10);
        n /= 10;
    }
    return total;
}


int main() {
    int n;
    while (scanf("%d", &n), n) {
        int last = n;
        int current = f(n);
        while (last != current) {
            last = current;
            current = f(current);
        }
        printf("%d\n", current);
    }
    return 0;
}
