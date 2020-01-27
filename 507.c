#include <stdio.h>
#include <string.h>

#define INF (int) 1e9

int A[20001];

int main() {
    int b;
    scanf("%d", &b);
    for (int r=1; r<=b; ++r) {
        int s;
        scanf("%d", &s);
        --s;

        for (int i=0; i<s; i++) {
            scanf("%d", &A[i]);
        }

        int start = 0;
        int end = s-1;
        int sum = 0;
        int ans = 0;
        for (int i=0; i<s; ++i) {
            sum += A[i];
            if (sum > ans) {
                ans = sum;
                end = s;
            }

            if (sum < 0) {
                sum = 0;
                start = i+1;
            }
        }

        if (ans > 0) {
            printf("The nicest part of route %d is between stops %d and %d\n", r, ++start, end);
        } else {
            printf("Route %d has no nice parts\n", r);
        }

    }
}

