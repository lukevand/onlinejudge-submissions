#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    vector<int> v;
    while (scanf("%d", &x) != EOF) {
        v.push_back(x);
        nth_element(v.begin(), v.begin() + v.size()/2, v.end());
        if (v.size() & 1) {
            printf("%d\n", (v[v.size()/2]));
        } else {
            nth_element(v.begin(), v.begin()+v.size()/2-1, v.begin()+v.size()/2);
            printf("%d\n", (v[v.size()/2] + v[v.size()/2-1])/2);
        }
    }
    return 0;
}

