#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int main() {
    int f, r;
    while (scanf("%d %d", &f, &r) == 2) {
        vector<int> fs(f);
        vector<int> rs(r);
        for (int i=0; i<f; i++) {
            scanf("%d", &fs[i]);
        }
        for (int i=0; i<r; i++) {
            scanf("%d", &rs[i]);
        }
        vector<double> rats;
        for (int i=0; i<f; i++) {
            for (int j=0; j<r; j++) {
                rats.push_back((double)rs[j]/fs[i]);
            }
        }
        sort(begin(rats), end(rats));
        double m = 0;
        for (int i=0; i<(int)rats.size()-1; i++) {
            m = fmax(m, rats[i+1]/rats[i]);
        }
        printf("%.02f\n", m);
    }

    return 0;
}

