#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int v[5];
bool used[5];
bool done;

void solve(int i, int soFar) {
    if (i == 5) {
        if (soFar==23) {
            done = true;
        }
        return;
    }

    for (int j=0; j<5; j++) {
        if (!used[j]) {
            used[j] = true;
            solve(i+1, soFar+v[j]);
            solve(i+1, soFar*v[j]);
            solve(i+1, soFar-v[j]);
            used[j] = false;
        }
    }
}

int main() {
    while (scanf("%d %d %d %d %d", &v[0], &v[1], &v[2], &v[3], &v[4]), v[0] && v[1] && v[2] && v[3]&&v[4]) {
        done = false;
        memset(used, false, sizeof used);
        for (int i=0; i<5; i++) {
            used[i] = true;
            solve(1, v[i]);
            used[i] = false;
        }
        printf("%s\n", (done ? "Possible" : "Impossible"));
    }
}

