#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int main() {
    cin.sync_with_stdio(false);
    string n;
    while (cin >> n, n != "0") {
        reverse(n.begin(), n.end());
        int64_t total = 0;
        for (size_t i=0; i<n.size(); i++) {
            total += (n[i]-'0')*((int)pow(2, i+1)  - 1);
        }
        cout << total << '\n';
    }

}

