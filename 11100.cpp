#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int main() {
    cin.sync_with_stdio(false);
    int n;
    while (cin >> n, n) {
        /* vector<int> v(n); */
        multiset<int> v;
        int a;
        int c = 0;
        for (int i=0; i<n; i++) {
            cin >> a;
            v.insert(a);
        }
        vector<vector<int>> bins;
        while (!v.empty()) {
            auto first = v.begin();
            auto y = v.upper_bound(*first+1);
            if (y != end(v)) {
                bins.push_back({*first, *y});
                v.erase(first); v.erase(y);
            } else {
                break;
            }
        }
        for (auto x: bins) {

    }

}

