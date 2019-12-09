#include <bits/stdc++.h>
using namespace std;

bool comp(char a, char b) {
    if (tolower(a) == tolower(b)) {
        return a < b;
    } else {
        return tolower(a) < tolower(b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        sort(begin(s), end(s), comp);
        do {
            cout << s << '\n';
        } while (next_permutation(begin(s), end(s), comp));
    }

    return 0;
}

