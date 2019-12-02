#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int L;
    vector<string> v;
    string operation;
    string state = "+x";
    while ((cin >> L), L) {
        v.resize(L);
        for (int i=0; i<L-1; i++) {
            cin >> operation;
            if (operation == "+y") {
                if (state == "+x") {
                    state = "+y";
                } else if (state == "-x") {
                    state = "-y";
                } else if (state == "+y") {
                    state = "-x";
                } else if (state == "-y") {
                    state = "+x";
                }

        }

    }
    return 0;
}

