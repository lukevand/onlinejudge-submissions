#include <bits/stdc++.h>
using namespace std;

int x, y;
struct position {
    int x, y;
};
int N, M, S;
int sticker;
typedef pair<int,int> II;

char facing_direction;
const string dirs = "NLSO"; /* NESW */

vector<vector<char>> G;
char cmd[50000 + 5];


void rot(char dir) {
    size_t p = dirs.find(facing_direction);
    if (dir == 'D') {/* clockwise */
        facing_direction = dirs[(p+1)%4];
    } else {
        facing_direction = dirs[(p+7)%4];
    }
}

bool isok(int i, int j) {
    if (i < 0 || j < 0 || i >= N || j >= M) return false;
    if (G[i][j] == '#') return false;
    return true;
}


void forward() {
    switch (facing_direction) {
        case 'N':
            if (isok(y-1, x)) {
                y -= 1;
            }
            break;
        case 'L':
            if (isok(y, x+1)) {
                x += 1;
            }
            break;
        case 'S':
            if (isok(y+1, x)) {
                y += 1;
            }
            break;
        case 'O':
            if (isok(y, x-1)) {
                x -= 1;
            }
            break;
        default:
            printf("NEVER HAPPENS\n");
            exit(1);
            ;;
    }
    if (G[y][x] == '*') {
        G[y][x] = '.';
        sticker++;
    }
}

int main() {
    while (scanf("%d %d %d", &N, &M, &S), N) {
        G.assign(N, vector<char>(M));
        sticker = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                scanf(" %c ", &G[i][j]);
                if (isupper(G[i][j])) {
                    y = i;
                    x = j;
                    facing_direction = G[i][j];
                }
            }
        }
        scanf("%s", cmd);

        for (int i=0; i<S; i++) {
            /* printf("BEFORE: %c: (%d %d) dir: %c\n", cmd[i], y, x, facing_direction); */
            switch (cmd[i]) {
                case 'D':
                case 'E':
                    rot(cmd[i]);
                    break;
                case 'F':
                    forward();
                    break;
            }
            /* printf("AFTERR: %c: (%d %d) dir: %c\n\n", cmd[i], y, x, facing_direction); */
        }

    printf("%d\n", sticker);
    }

return 0;
}

