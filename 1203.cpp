#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef pair<int,int> II;
typedef tuple<int,int,int,int> III;

int main() {
    ios::sync_with_stdio(false);
    int Q_num, period, N;
    string s;
    priority_queue<III, vector<III>, greater<III>> pq;
    while (cin >> s, s != "#") {
        cin >> Q_num >> period;
        pq.emplace(period, Q_num, period, 1);
    }
    cin >> N;
    int mult, originalPeriod;
    while (N--) {
        tie(period, Q_num, originalPeriod, mult) = pq.top(); pq.pop();
        cout << Q_num << '\n';
        ++mult;
        pq.emplace(originalPeriod*mult, Q_num, originalPeriod, mult);
    }
}

