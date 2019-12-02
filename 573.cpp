#include <bits/stdc++.h>
using namespace std;

#define print(x) cout << "DEBUG: " << #x << ": " << x << '\n'

int main() {
    int H, U, D, F;
    while (scanf("%d %d %d %d", &H, &U, &D, &F), H) {
        double dist = 0;
        int day = 0;
        double up = U;
        double lostToFatigue = U * (double) F/100;

        while (true) {
            if (day && dist < 0) {
                printf("failure on day %d\n", day);
                break;
            }
            day++;
            if (up > 0) {
                dist += up;
            }
            if (dist - 0 > H) {
                printf("success on day %d\n", day);
                break;
            }
            up -= lostToFatigue;
            dist -= D;
        }
    }

    return 0;
}

