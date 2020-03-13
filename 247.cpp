#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
unordered_map<string, vector<string>> G;
unordered_map<

int main() {
    cin.sync_with_stdio(false);
    int n, m;
    for (int TC=1; cin >> n >> m, !cin.eof(); TC++) {
        G.clear();
        while (m--) {
            string x, y;
            cin >> x >> y;
            G[x].push_back(y);
        }
    }
}

