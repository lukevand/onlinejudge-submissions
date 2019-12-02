#include <bits/stdc++.h>
using namespace std;

#define print(x)// cout << "DEBUG: " << #x << " " << x << '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n) {
        while (true) {
            int train;
            stack<int> A;
            stack<int> B;
            stack<int> station;
            string line;
            getline(cin, line);
            if (line == "") {
                getline(cin, line);
            }

            if (line[0] == '0') {
                break;
            }
            istringstream iss(line);
            for (int i=0; i<n; i++) {
                iss >> train;
                print(train);
                B.push(train);
            }

            int goal = n;
            while (true) {
                print(goal);
                if (!station.empty()) {
                    print(station.top());
                }
                if (goal == 0 || (B.empty() && station.empty())) {
                    cout << "Yes\n";
                    break;
                } else if (!station.empty() && station.top() == goal) {
                    A.push(station.top()); station.pop();
                    goal--;
                } else if (!B.empty()) {
                    station.push(B.top()); B.pop();
                } else if (B.empty() && !station.empty() && station.top() != goal) {
                    cout << "No\n";
                    break;
                }
            }
        }
        cin >> n;
        cout << '\n';
    }
    return 0;
}

