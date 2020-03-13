#include <stdio.h>

int main() {
    int n;
    int i, j;
    int first = 1;
    int amp, freq;
    scanf("%d", &n);

    while (n--) {
        if (first != 1) {
            printf("\n");
        }
        first = 0;

        scanf("%d %d", &amp, &freq);
        while (freq--) {
            for (i=1; i<= amp; i++) {
                for (j=0; j<i; j++) {
                    printf("%d", i);
                }
                printf("\n");
            }
            for (i=amp-1; i>0; i--) {
                for (j=0; j<i; j++) {
                    printf("%d", i);
                }
                printf("\n");
            }
            if (freq) printf("\n");
        }

    }
    return 0;
}
