#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << #x << " " << x << '\n'
typedef vector<int> VI;

VI tracks;
int N, numTracks;
int best;
VI bestPath;

void solve(int current, VI path, int costOfPath) {
    if (current >= numTracks) {
        if (costOfPath > best) {
            best = costOfPath;
            bestPath = path;
        }
        return;
    }

    if (costOfPath + tracks[current] <= N) {
        path.push_back(current);
        solve(current+1, path, costOfPath+tracks[current]);
        path.pop_back();
    }

    solve(current+1, path, costOfPath);
}

int main() {
    while (scanf("%d %d", &N, &numTracks) != -1) {
        tracks.clear(); tracks.assign(numTracks, -1);
        bestPath.clear();
        best = 0;

        for (int i=0; i<numTracks; i++) {
            scanf("%d", &tracks[i]);
        }
        solve(0, VI(), 0);
        for (int x: bestPath) {
            printf("%d ", tracks[x]);
        }
        printf("sum:%d\n", best);
    }

    return 0;
}

