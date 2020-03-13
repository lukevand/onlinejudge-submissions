#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int main() {
    int N; cin >> N;
    string blank; getline(cin, blank);
    while (N--) {
        string line;
        getline(cin, line);
        istringstream sin(line);
        vector<string> vars;
        string s;
        while (sin >> s, !sin.eof()) {
            vars.push_back(s);
        }

        getline(cin, line);
        istringstream sin2(line);
}

