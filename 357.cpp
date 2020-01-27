#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << #x << " " << x << '\n'
typedef vector<int> VI;
VI denoms = {1, 5, 10, 25, 50};

long memo[5][30005];

long cc(int type, int c) {
    if (c < 0 || type == 5) return 0;
    long &ans = memo[type][c];
    if (ans != -1) return ans;
    return ans = cc(type+1, c) + cc(type, c-denoms[type]);
}

int main() {
    int n;
    memset(memo, -1, sizeof memo);
    for (int i=0; i<5; i++) memo[i][0] = 1;
    while (scanf("%d", &n) != EOF) {
        long x = cc(0, n);
        if (x != 1) {
            printf("There are %ld ways to produce %d cents change.\n", x, n);
        } else {
            printf("There is only 1 way to produce %d cents change.\n", n);
        }
    }
}

