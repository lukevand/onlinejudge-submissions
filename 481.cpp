#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;
VI A;
VI p;

void print_LIS(int i) {                          // backtracking routine
    if (p[i] == -1) { printf("%d\n", A[i]); return; }// base case
    print_LIS(p[i]);                               // backtrack
    printf("%d\n", A[i]);
}

int main() {
    int a;
    while (scanf("%d", &a) != EOF) {
        A.push_back(a);
    }
    int n = (int)A.size();

    int k = 0, lis_end = 0;
    VI L(n, 0), L_id(n, 0);
    p.assign(n, -1);

    for (int i = 0; i < n; ++i) {                  // O(n)
        int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
        L[pos] = A[i];                               // greedily overwrite this
        L_id[pos] = i;                               // remember the index too
        p[i] = pos ? L_id[pos-1] : -1;               // predecessor info
        if (pos == k) {                              // can extend LIS?
            k = pos+1;                                 // k = longer LIS by +1
            lis_end = i;                               // keep best ending i
        }
    }
    printf("%d\n-\n", k);
    print_LIS(lis_end);
}

