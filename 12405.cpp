#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int main() {
    int T, N;
    ios_base::sync_with_stdio(false);
    cin >> T;
    string s;
    for (int TC=1; TC<=T; ++TC) {
        int c = 0;
        cin >> N >> s;
        for (int i=0; i<N; i++) {
            if (s[i] == '.') {
                ++c;
                s[i] = s[i+1] = s[i+2] = '#';
            }
        }
        cout << "Case " << TC << ": " << c << '\n';
    }

}

