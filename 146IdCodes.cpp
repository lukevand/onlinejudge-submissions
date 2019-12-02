#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    while (cin >> s, s[0] != '#') {
        next_permutation(s.begin(), s.end());
        string t = s;
        sort(begin(t), end(t));
        if (s != t) {
            cout << s << '\n';
        } else {
            cout << "No Successor\n";
        }
    }
    return 0;
}

