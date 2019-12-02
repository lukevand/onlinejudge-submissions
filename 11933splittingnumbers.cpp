#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n), n) {
        int a=0; int b=0;
        vector<int> indexes;
        for (int i=0; i<32; i++) {
            if (n & (1 << i)) {
                indexes.push_back(i);
            }
        }
        for (int i=0; i<indexes.size(); i+= 2) {
            a |= (1 << indexes[i]);
        }
        for (int i=1; i<indexes.size(); i+= 2) {
            b |= (1 << indexes[i]);
        }
        printf("%d %d\n", a, b);
    }

    return 0;
}

