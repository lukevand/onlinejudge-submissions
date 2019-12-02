#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    int tmp;
    while (scanf("%d", &n), n) {
        v.assign(n, 0);
        int total = 0;
        for (int i=0; i<n; i++) {
            scanf("%d", &tmp);
            pq.push(tmp);
        }
        while (!pq.empty()) {
            int top = pq.top(); pq.pop();
            if (pq.empty()) {
                break;
            }
            int next = pq.top(); pq.pop();
            int backIn = top + next;
            pq.push(backIn);
            total += backIn;
        }
        printf("%d\n", total);
    }
    return 0;
}

