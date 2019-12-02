#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    while (true) {
        cin >> s;
        if (cin.eof()) break;
        list<char> t;
        auto it = t.begin();
        for (char c: s) {
            if (c == '[') {
                it = t.begin();
            } else if (c == ']') {
                it = t.end();
            } else {
                t.insert(it, c);
            }
        }

        for (auto x : t) {
            cout << x;
        }
        cout << '\n';
    }

    return 0;
}

