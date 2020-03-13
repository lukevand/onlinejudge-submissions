#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; scanf("%d", &T);
    for (int TC=1; TC<=T; TC++) {
        int N; scanf("%d", &N);
        vector<int> v(N);
        for (int i=0; i<N; i++) {
            scanf("%d", &v[i]);
        }
        nth_element(v.begin(), v.begin() + v.size()/2, v.end());
        printf("Case %d: %d\n", TC, v[v.size()/2]);
    }
}

