#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
vector<string> strings;
string pattern;

void dfs(int cur, string soFar) {
    if (cur == (int)pattern.size()) {
        cout << soFar << '\n';
        return;
    }
    if (pattern[cur] == '0') {
        for (int i=0; i<10; i++) {
            dfs(cur+1, soFar+to_string(i));
        }
    } else {
        for (string s: strings) {
            dfs(cur+1, soFar+s);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    int n; int m;
    string s;
    while (true) {
        cin >> n;
        if (cin.eof()) break;
        strings.clear();
        while (n--) {
            cin >> s;
            strings.push_back(s);
        }
        cin >> m;
        cout << "--\n";
        while (m--) {
            cin >> pattern;
            dfs(0, "");
        }
    }
}

