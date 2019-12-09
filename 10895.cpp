#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << #x << " " << x << '\n'

typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VII> VVII;

int main() {
    ios::sync_with_stdio(false);
    int n, m, r;
    while (cin >> m >> n) {
        string s;
        VVII G(n, VII());

        for (int i=0; i<m; i++) {
            cin >> r;
            if (r == 0) continue;
            int value;
            VI locations(r);
            for (int j=0; j<r; j++) {
                cin >> locations[j];
                locations[j]--;
            }
            for (int j=0; j<r; j++) {
                cin >> value;
                G[locations[j]].emplace_back(i, value);
            }
        }

        cout << n << ' ' << m << '\n';
        for (VII x: G) {
            cout << x.size();
            if (x.size()) cout << ' ';
            for (auto it=x.begin(); it!=x.end(); it++) {
                II y = *it;
                cout << y.first+1;
                if (it != x.end()-1) {
                    cout << " ";
                }
            }
            cout << '\n';
            for (auto it=x.begin(); it!=x.end(); it++) {
                II y = *it;
                cout << y.second;
                if (it != x.end()-1) {
                    cout << " ";
                }
            }
            cout << '\n';
        }
    }

    return 0;
}

