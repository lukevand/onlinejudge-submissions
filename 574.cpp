#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int num[15];
vector<int> soFar;
set<vector<int>> s;
int t, n;
bool boo;

void dfs(int cur, int sum, vector<int> soFar) {
    if (cur == n && sum == t) {
        if (s.find(soFar) != end(s)) {
            return;
        }
        s.insert(soFar);
        for (int i=0; i<(int)soFar.size(); i++) {
            printf(i == (int)soFar.size()-1 ? "%d" : "%d+", soFar[i]);
        }
        printf("\n");
        boo = true;
        return;
    }
    if (cur >= n) return;

    if (sum+num[cur] <= t) {
        soFar.push_back(num[cur]);
        dfs(cur+1, sum+num[cur], soFar);
        soFar.pop_back();
    }
    dfs(cur+1, sum, soFar);
}


int main() {
    while (scanf("%d %d", &t, &n), t) {
        boo = false;
        s.clear();
        for (int i=0; i<n; i++) {
            scanf("%d", &num[i]);
        }
        printf("Sums of %d:\n", t);
        dfs(0, 0, vector<int>());
        if (!boo) printf("NONE\n");
    }
}

