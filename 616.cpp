#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

bool check(int coconuts, int people) {
    for (int i=0; i<people; i++) {
        if (coconuts % people != 1) {
            return false;
        }
        coconuts = coconuts - coconuts/people - 1;
    }
    return coconuts % people == 0;
}

int main() {
    int n;
    while (scanf("%d", &n), n >= 0) {
        int re = -1;
        for (int i=1; i<100; i++) {
            if (check(n, i)) {
                re = i;
            }
        }
        printf("%d coconuts, ", n);
        if (re != -1) {
            printf("%d people and 1 monkey\n", re);
        } else {
            printf("no solution\n");
        }
    }
}

