#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
#define ALL(x) x.begin(), x.end()


int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    for (int N, TC=1; cin >> N, !cin.eof(); TC++) {
        vector<vector<int>> G(N, vector<int>());
        vector<string> toposort;
        vector<string> drinks;
        vector<int> numIncoming(N, 0);
        queue<size_t> q;
        vector<bool> done(N, false);

        for (int i=0; i<N; i++) {
            string s;
            cin >> s;
            drinks.push_back(s);
        }
        int M; cin >> M;
        while (M--) {
            string x, y;
            cin >> x >> y;
            int xpos = find(ALL(drinks), x)-drinks.begin();
            int ypos = find(ALL(drinks), y)-drinks.begin();
            G[xpos].push_back(ypos);
            numIncoming[ypos]++;
        }

        for (size_t i=0; i<drinks.size(); i++) {
            if (numIncoming[i] == 0) {
                q.push(i);
                break;
            }
        }

        while (!q.empty()) {
            size_t u = q.front(); q.pop();
            done[u] = true;
            toposort.push_back(drinks[u]);

            for (int v: G[u]) {
                numIncoming[v]--;
            }

            for (size_t i=0; i<drinks.size(); i++) {
                if (!done[i] && numIncoming[i] == 0) {
                    q.push(i);
                    break;
                }
            }

        }

        cout << "Case #" << TC << ": Dilbert should drink beverages in this order:";

        for (size_t i=0; i<toposort.size(); i++) {
            cout << ' ' << toposort[i];
        }
        cout << ".\n\n";
    }
}

