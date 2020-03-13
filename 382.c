#include <stdio.h>

int main() {
    int n;
    int sum;
    int i;
    printf("PERFECTION OUTPUT\n");
    while (scanf("%d", &n), n) {
        sum = 0;
        for (i=1; i<=n/2; i++) {
            if (n%i == 0) {
                sum += i;
            }
        }
        printf("%5d  ", n);
        if (sum < n) {
            printf("DEFICIENT\n");
        } else if (sum > n) {
            printf("ABUNDANT\n");
        } else {
            printf("PERFECT\n");
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}

