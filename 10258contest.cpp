#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int,int>> results(101, {-1,-1});
    int T;
    int contestant, problem, time;
    char L;
    cin >> T;
    string line;
    getline(cin, line);
    while (T--) {
        while(getline(cin, line)) {
            istringstream ss(line);
            ss >> contestant >> problem >> time >> L;
            results[contestant]


    return 0;
}

