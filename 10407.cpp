#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a%b));
}

int main() {
    int n;
    while (scanf("%d", &n), n != 0) {
        vector<int> v;
        v.push_back(n);
        while (scanf("%d", &n), n != 0) {
            v.push_back(n);
        }
        vector<int> diffs;
        for (size_t i=1; i<v.size(); i++) {
            for (size_t j=0; j<i; j++) {
                diffs.push_back(abs(v[i]-v[j]));
            }
        }
        int g=diffs[0];
        for (size_t i=1; i<diffs.size(); i++) {
            g = gcd(max(g,diffs[i]), min(g,diffs[i]));
        }
        printf("%d\n", g);
    }
}

