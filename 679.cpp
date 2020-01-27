#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

void solve(int D, int I) {
    int x = 1;
    while (2*x < (1<<D)) {
        if (I % 2 == 0) {
            x = 2*x+1;
        } else {
            x = 2*x;
        }
        I = (I + 1)/2;
    }
    printf("%d\n", x);
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int D, I;
        scanf("%d %d", &D, &I);
        solve(D, I);
    }
}

