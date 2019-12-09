#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef pair<int,int> II;

int main() {
    int T, maxCapacity, timeToCross, m;
    char dir[6];
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &maxCapacity, &timeToCross, &m);
        queue<II> ql;
        queue<II> qr;
        int arriveTime;
        for (int i=0; i<m; i++) {
            scanf("%d %s", &arriveTime, dir);
            if (dir[0] == 'r') qr.emplace(arriveTime, i);
            else ql.emplace(arriveTime, i);
        }

        char side = 'l';
        while (true) {
            if (side == 'l') {
                for (int i=1; i<=maxCapacity; i++) {


    }

    return 0;
}

