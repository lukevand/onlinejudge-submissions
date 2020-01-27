#include <stdio.h>

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        int count = 0;
        int butts = 0;
        int smokes = n;
        while (1) {
            count += smokes;
            butts = smokes;

        while (n >= k) {
            n /= k;
            count += n;
        }
        printf("%d\n", count);
    }
    return 0;
}
