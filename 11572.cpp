#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        map<int,int> m;
        int n, snowflake;
        scanf("%d", &n);
        int best = 0;
        int currentRun = 0;
        for (int i=0; i<n; i++) {
            scanf("%d", &snowflake);
            auto ret = m.emplace(snowflake, i);
            if (!ret.second) {
                best = max(best, currentRun);
                currentRun = i - (m[1] + 1);
                m.erase(m.find(snowflake));
                m.emplace(snowflake, i);
            } else {
                currentRun++;
            }
        }
        printf("%d\n", max(best, (int)m.size()));
    }


    return 0;
}

