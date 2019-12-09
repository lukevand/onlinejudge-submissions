#include <bits/stdc++.h>
using namespace std;
#define print(x)// cout << "DEBUG: " << x << '\n'

int main() {
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    int low, high;
    int size;
    int queryNum;
    while (T--) {
        cin >> size;
        vector<tuple<int,int,string>> database;
        while (size--) {
            cin >> s >> low >> high;
            database.emplace_back(low, high, s);
        }

        sort(database.begin(), database.end());
        cin >> queryNum;
        int query;
        string best;
        bool seenOne;
        while (queryNum--) {
            seenOne = false;
            best = "UNDETERMINED";
            cin >> query;
            for (auto item: database) {
                tie(low, high, s) = item;
                if (low <= query && query <= high) {
                    print(s);
                    if (seenOne) {
                        best = "UNDETERMINED";
                        break;
                    }
                    best = s;
                    seenOne = true;
                }
            }
            cout << best << '\n';
        }
        cout << (T ? "\n" : "");
    }

    return 0;
}

