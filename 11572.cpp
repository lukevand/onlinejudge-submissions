#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        unordered_map<int,int> m;
        int n, snowflake;
        scanf("%d", &n);
        int best = 0;
        int start = 0;
        for (int i=0; i<n; i++) {
            scanf("%d", &snowflake);
            auto ret = m.emplace(snowflake, i);
            if (!ret.second) {
                if (ret.first->second >= start) {
                    start = ret.first->second + 1;
                }
                m.erase(ret.first);
                m.emplace(snowflake, i);
            }
            best = max(best, i-start+1);
        }
        printf("%d\n", best);
    }


    return 0;
}

