#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int main() {
    int N, top, tmp, used;
    bool firstTime = true;
    while (scanf("%d", &N), N) {
        if (!firstTime) {
            printf("\n");
        }
        firstTime = false;

        bool doneSomething = false;
        for (int bot=1234; bot<=98765/N; bot++) {
            top = bot*N;
            if (top/bot != N) {
                print(top);
                continue;
            }
            used = (bot < 10000);
            tmp = top;
            while (tmp) {
                used |= (1 << (tmp%10));
                tmp /= 10;
            }
            tmp = bot;
            while (tmp) {
                used |= (1 << (tmp%10));
                tmp /= 10;
            }
            if (used == (1<<10) - 1) {
                printf("%.5d / %.5d = %d\n", top, bot, N);
                doneSomething = 1;
            }
        }
        if (!doneSomething) {
            printf("There are no solutions for %d.\n", N);
        }
    }

    return 0;
}

