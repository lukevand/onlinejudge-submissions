#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;
VI v;
int T, n;

bool can(int k) {
    int diff = -1;
    if (k < v[0]) return false;
    if (k == v[0]) --k;
    for (int i=1; i<n; i++) {
        diff = v[i] - v[i-1];
        if (diff > k) return false;
        else if (diff == k) --k;
    }
    return true;
}


int main() {
    scanf("%d", &T);
    for (int TC=0; TC<T; TC++) {
        scanf("%d", &n);
        v.clear();
        v.assign(n, 0);
        for (int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }
        if (n == 1) {
            printf("Case %d: %d\n", TC+1, v[0]);
            continue;
        }
        int lo=1, hi=(int)1e7, mid=1;
        while (lo < hi) {
            mid = lo + (hi-lo)/2;
            can(mid) ? hi = mid : lo = mid+1;
        }
        /* print(lo << " " << mid << " " << hi); */
        /* print(can(lo-1) << " " << can(lo) << " " << can(hi)); */
        printf("Case %d: %d\n", TC+1, hi);
    }
}

