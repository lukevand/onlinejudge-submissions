#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;
int n;
bitset<17> available;

VI primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
VI chain;

bool inPrimes(int p) {
    for (int prime : primes) {
        if (p == prime) return true;
    }
    return false;
}

void dfs(int cur, VI soFar) {
    /* print("CUR: " << cur); */
    /* cout << "DEBUG: "; for (auto x : soFar) { cout << x << " ";}; cout << '\n'; */
    /* soFar.push_back(cur); */
    if (cur == n-1) {
        for (int i=0; i<(int)soFar.size()-1; ++i) {
            printf("%d ", soFar[i]);
        }
        printf("%d\n", soFar.back());
    }

    for (int i=2; i<=n; i++) {
        if (available[i] && inPrimes(i+soFar.back())) {
            if (cur == n-2 && !inPrimes(i+1)) {
                /* print("DJFIDJIFJDIFJDIFJDF"); */
                continue;
            }
            soFar.push_back(i);
            available[i] = 0;
            dfs(cur+1, soFar);
            soFar.pop_back();
            available[i] = 1;
        }
    }
}


int main() {
    int NC = 1;
    while (scanf("%d", &n) != EOF) {
        if (NC!=1) printf("\n");
        chain.clear(); available.set();
        printf("Case %d:\n", NC++);
        VI v = {1};
        dfs(0, v);
    }
}

