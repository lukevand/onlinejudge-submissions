#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

int main() {
    int T;
    int d, m, y, goal;
    int re;
    scanf("%d", &T);
    for (int i=1; i<=T; i++) {
        scanf("%d %d %d %d", &d, &m, &y, &goal);
        if (d == 29 && m == 2) {
            int c=0;
            for (int j=y; j<goal; j++) if (isLeapYear(j)) c++;
            re = c;
            if (!isLeapYear(goal)) re--;
        } else {
            re = goal-y;
        }
        printf("Case %d: %d\n", i, re);
    }
    return 0;
}

