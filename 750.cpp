#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

vector<int> row(8);
int TC, a, b, lineCounter;

bool place(int r, int c) {
    for (int prev=0; prev<c; prev++) {
        if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c))) {
            return false;
        }
    }
    return true;
}

void solve(int c) {
    if (c == 8 && row[b] == a) {
        printf("%2d      %d", ++lineCounter, row[0] + 1);
        for (int j=1;j<8;j++) printf(" %d", row[j]+1);
        printf("\n");
    }
    for (int r=0; r<8; r++) {
        if (place(r, c)) {
            row[c] = r;
            solve(c+1);
        }
    }
}

int main() {
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &a, &b);
        --a; --b;
        row.assign(8, 0); lineCounter = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        solve(0);
        if (TC) printf("\n");
    }
}

