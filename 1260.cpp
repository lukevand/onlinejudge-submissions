#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    int T, n, count;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        count = 0;
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (v[j] <= v[i]) count++;
            }
        }
        cout << count << '\n';
    }

    return 0;
}

