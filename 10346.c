#include <stdio.h>

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        int count = 0;
        int butts = 0;
        int smokes = n;

        while (smokes > 0) {
            /* printf("count=%d butts=%d smokes=%d\n", count, butts, smokes); */
            butts += smokes;
            count += smokes;
            smokes = 0;

            smokes += butts/k;
            butts %= k;
        }
        printf("%d\n", count);

    }
    return 0;
}
