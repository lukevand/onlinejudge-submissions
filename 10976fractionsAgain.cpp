#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    vector<pair<int,int>> v;
    while (scanf("%d", &k) != EOF) {
        v.clear();
        for (int x=k+1; x<2*k+1; x++) {
            if ((k*x)%(x-k) != 0) continue;
            int y = (k*x)/(x-k);
            /* printf("%d %d\n", x, y); */
            v.push_back({y, x});
        }
        printf("%ld\n", v.size());
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        for (auto x: v) {
            printf("1/%d = 1/%d + 1/%d\n", k, x.first, x.second);
        }

    }
    return 0;
}

