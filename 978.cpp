#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;
typedef pair<int,int> II;
typedef vector<II> VII;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, B, SG, SB;
    int tmp;
    int numFight;
    cin >> N;
    while (N--) {
        multiset<int> green, blue;
        cin >> B >> SG >> SB;
        for (int i=0; i<SG; i++) {
            cin >> tmp; green.insert(tmp);
        }
        for (int i=0; i<SB; i++) {
            cin >> tmp; blue.insert(tmp);
        }
        while (!green.empty() && !blue.empty()) {
            numFight = min({B, (int)green.size(), (int)blue.size()});
            VII addlater;
            for (int i=0; i<numFight; i++) {
                auto greenBest = green.end();
                auto blueBest = blue.end();
                --greenBest; --blueBest;
                if (*greenBest == *blueBest) {
                    ;
                } else if (*greenBest > *blueBest) {
                    addlater.emplace_back(*greenBest-*blueBest, 1);
                } else {
                    addlater.emplace_back(*blueBest-*greenBest, 0);
                }
                green.erase(greenBest);
                blue.erase(blueBest);
            }
            for (II x: addlater) {
                if (x.second == 1) {
                    green.insert(x.first);
                } else {
                    blue.insert(x.first);
                }
            }
        }

        if (green.empty() && !blue.empty()) {
            cout << "blue wins\n";
            for (auto it=blue.rbegin(); it!=blue.rend(); it++) {
                cout << *it << '\n';
            }
        } else if (!green.empty() && blue.empty()) {
            cout << "green wins\n";
            for (auto it=green.rbegin(); it!=green.rend(); it++) {
                cout << *it << '\n';
            }
        } else {
            cout << "green and blue died\n";
        }
        cout << (N ? '\n' : '\0');
    }

    return 0;
}

