#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<pair<int,int>> VII;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int B, S, L, R;
    while (cin >> B >> S, B || S) {
        VII line;
        line.emplace_back(-1, -1);
        for (int i=1; i<=B; i++) {
            line.emplace_back(i-1, i+1);
        }
        line.emplace_back(-1, -1);
        for (int i=0; i<S; i++) {
            cin >> L >> R;
            line[line[R].second].first = line[L].first;
            line[line[L].first].second = line[R].second;
            if (line[L].first == 0) {
                cout << "* ";
            } else {
                cout << line[L].first << " ";
            }
            if (line[R].second == B+1) {
                cout << "*\n";
            } else {
                cout << line[R].second << '\n';
            }
        }
        cout << "-\n";
    }

    return 0;
}

