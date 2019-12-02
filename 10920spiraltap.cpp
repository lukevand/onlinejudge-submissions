#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;

int main() {
    int SZ, P;
    VI squares;
    for (int i=1; i<318; i+=2) {
        squares.push_back(i*i);
    }
    while (scanf("%d %d", &SZ, &P), SZ | P) {
        int it = lower_bound(squares.begin(), squares.end(), P)-squares.begin();

    return 0;
}

