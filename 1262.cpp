#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
#define ALL(x) x.begin(), x.end()

int perm_count = 0;

void dfs(

int main() {
    int T; cin >> T;
    while (T--) {
        int K; cin >> K;
        vector<string> book1(6);
        vector<string> book2(6);
        vector<vector<char>> G1(5, vector<char>(6));
        vector<vector<char>> G2(5, vector<char>(6));
        for (int i=0; i<6; i++) {
            cin >> book1[i];
        }
        for (int i=0; i<6; i++) {
            cin >> book2[i];
        }
        // transpose
        for (int i=0; i<6; i++) {
            for (int j=0; j<5; j++) {
                G1[i][j] = book1[j][i];
                G2[i][j] = book2[j][i];
            }
        }
        for (auto x: G1) {
            sort(ALL(x));
        }
        for (auto x: G2) {
            sort(ALL(x));
        }
    }
}

