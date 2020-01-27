#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef long long L;
vector<int> A;

int solve(int n) {
    if (n == 1) {
        return A[0];
    } else {
        return max(A[n], solve(n-1) * A[n]);
    }
}

int main() {
    int n;
    while (true) {
        A.clear();
        if (scanf("%d", &n) == EOF) {
            break;
        }
        A.push_back(n);
        while (scanf("%d", &n), n != -999999) {
            A.push_back(n);
        }
        int size = A.size();

        /* L prod = 1; */
        /* L best = -1e9; */
        /* for (int i=0; i<size; i++) { */
        /*     for (int j=i; j<size; j++) { */
        /*         prod = 1; */
        /*         for (int k=i; k<=j; k++) { */
        /*             prod *= A[k]; */
        /*         } */
        /*         best = max(best, prod); */
        /*     } */
        /* } */
        /* printf("%lld\n", best); */
        int bestPos = 1, bestNeg = 1;
        for (int i=0; i<A.size(); i++) {
            if (A[i] == 0) {
                bestPos = 1, bestNeg = 1;
            } else if (A[i] < 0) {
                bestPos = max(bestPos, bestNeg*A[i]);
                bestNeg = min(bestNeg, bestPos*A[i]);
            } else {
                bestPos = max(bestPos, bestPos*A[i]);
                bestNeg = min(bestNeg, bestNeg*A[i]);
            }
        }
        printf("%d %d\n", bestPos, bestNeg);

    }
}

