#include <math.h>
#include <stdint.h>
#include <stdio.h>

int main() {
    uint32_t n;
    while (scanf("%u", &n), n) {
        uint32_t x = (uint32_t) sqrt(n);
        if (x*x == n) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
