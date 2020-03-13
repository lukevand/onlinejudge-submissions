#include <bits/stdc++.h>
using namespace std;
#define print(x)// cout << "DEBUG: " << x << '\n'

typedef vector<int> VI;
typedef vector<VI> VVI;

VI visited, low, num;
VVI graph;
stack<int> st;
int dfs_counter;

int total;

void dfs(int u) {
    print(u);
    st.push(u);
    low[u] = num[u] = dfs_counter++;
    visited[u] = 1;
    for (int v: graph[u]) {
        if (num[v] == -1)
            dfs(v);
        if (visited[v]) {
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] == num[u]) {
        total++;
        while (1) {
            int v = st.top(); st.pop(); visited[v] = 0;
            if (u == v) break;
        }
    }

}

int main()
{
    int T, n, m, start, start2;
    scanf("%d", &T);
    while (T--) {
        total = 0;
        scanf("%d %d", &n, &m);
        graph.assign(n+1, VI());
        low.assign(n, 0);
        num.assign(n, -1);
        visited.assign(n, 0);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &start, &start2);
            --start; --start2;
            graph[start].push_back(start2);
        }

        for (int i=0; i<n; i++) {
            /* scanf("%d", &origin); */
            if (num[i] == -1) {
                dfs(i);
            }
        }
        printf("%d\n", total);
    }
    return 0;
}

