#include <bits/stdc++.h>
using namespace std;
#define print(x)// cout << "DEBUG: " << x << '\n'

int main() {
    ios::sync_with_stdio(false);
    int n;
    string s;
    while (cin >> n, n) {
        map<string,int> m;
        for (int i=0; i<n; i++) {
            set<string> thisOne;
            string re = "";
            for (int j=0; j<5; j++) {
                cin >> s;
                thisOne.insert(s);
            }
            for (string j: thisOne) {
                re += j;
            }
            m[re] += 1;
        }
        int ma = 0;
        for (auto x: m) {
            print(x.first << " " << x.second);
            ma = max(ma, x.second);
        }
        int tot = 0;
        for (auto x: m) {
            if (x.second == ma) {
                tot += x.second;
            }
        }
        cout << tot << '\n';
    }

    return 0;
}

