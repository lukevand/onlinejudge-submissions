#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << #x << " DEBUG: " << x << '\n'
typedef long long L;

L ipow(L x, L y) {
    if (y == 0) return 1;
    if (y & 1) return x*ipow(x*x, y/2);
    return ipow(x*x, y/2);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int x, a;
    vector<L> A;
    while (cin >> x) {
        A.clear();
        string s;
        getline(cin, s);
        getline(cin, s);
        istringstream is(s);
        while (is >> a) {
            A.push_back(a);
        }
        L tot = 0;
        int n = (int)A.size()-1;
        for (int i=0; i<=n-1; ++i) {
            tot += A[i]*(n-i)*ipow(x, n-i-1);
        }
        cout << tot << '\n';

    }
}

