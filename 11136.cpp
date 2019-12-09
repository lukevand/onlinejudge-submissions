#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef unsigned int L;

int main() {
    int n;
    while(scanf("%d", &n), n) {
        multiset<int> s;
        int bill, k;
        L total = 0LL;
        for (int i=0; i<n; i++) {
            scanf("%d", &k);
            for (int j=0; j<k; j++) {
                scanf("%d", &bill);
                s.insert(bill);
            }
            auto smallest = s.begin();
            auto largest = s.end();
            --largest;
            total += (*largest - *smallest);
            s.erase(largest);
            s.erase(smallest);
        }
        printf("%u\n", total);
    }

    return 0;
}

