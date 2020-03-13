#include <bits/stdc++.h>
using namespace std;
#define print(x)// cout << "DEBUG: " << x << '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
    cout << setprecision(4);

    int n;
    string s;
    getline(cin, s);
    istringstream tmpStream(s);
    tmpStream >> n;

    getline(cin, s);
    while (n--) {
        map<string,int> m;
        int total = 0;
        while (getline(cin, s), !s.empty()) {
            m[s]++; total++;
        }
        print(total);
        print(m["Ash"]);
        for (auto x: m) {
            cout << x.first << " " << (x.second*100.0)/total << '\n';
        }
        if (n>0) cout << '\n';
    }


    return 0;
}

