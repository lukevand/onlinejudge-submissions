#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<string> VS;
typedef vector<string> VI;
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
int n, m;

bool valid(int i, int j) {
    if (0 <= i && i < n && 0 <= j && j < m) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    bool first = true;
    int TC=0;
    while (cin >> n >> m, n || m) {
        if (!first) cout << '\n';
        first = false;
        vector<string> v(n+1);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        cout << "Field #" << ++TC << ":\n";
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (v[i][j] == '*') {
                    cout << '*';
                    continue;
                }
                int thisCount = 0;
                for (int k=0; k<8; k++) {
                    int ddy = i+dy[k];
                    int ddx = j+dx[k];
                    if (valid(ddy, ddx) && v[ddy][ddx] == '*') {
                        ++thisCount;
                    }
                }
                cout << thisCount;
            }
            cout << '\n';
        }
    }

}

