#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

vector<int> initPos(8);
vector<int> prevRowPos(8);
vector<int> rowPos(8);
int best;

bool safe(int r, int c) {
    for (int prev=0; prev<c; prev++) {
        if (rowPos[prev] == r || (abs(rowPos[prev] - r) == abs(prev - c))) return false;
    }
    return true;
}

void solve(int col, int lenPath) {
    if (col >= 8) {
        /* for (auto x : rowPos) { cout << x << " "; }; cout << '\n'; */
        best = min(best, lenPath);
    }
    for (int row=0; row<8; row++) {
        if (safe(row, col)) {
            rowPos[col] = row;
            solve(col+1, lenPath + (row != initPos[col]));
        }
    }
}

int main() {
    for (int i=1; scanf("%d", &initPos[0]) != EOF; i++) {
        initPos[0]--;
        best = INT_MAX; rowPos.assign(8, 0);
        for (int j=1; j<8; j++) {
            scanf("%d", &initPos[j]); initPos[j]--;
        }
        /* for (auto x : initPos) { cout << x << " "; }; cout << '\n'; */
        solve(0, 0);
        printf("Case %d: %d\n", i, best);
    }
}

