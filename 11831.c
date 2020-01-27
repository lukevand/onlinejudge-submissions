#include <stdio.h>
#include <ctype.h>

char G[101][101];
char cmd[5*(int)1e4 + 5];

char rot(char c, char dir) {
    if (dir == 'D') // clockwise
        switch (c) {
            case 'N':
                return 'L';
            case 'L':
                return 'S';
            case 'S':
                return 'O';
            case 'O':
                return 'N';
        }
    else
        switch (c) {
            case 'L':
                return 'N';
            case 'S':
                return 'L';
            case 'O':
                return 'S';
            case 'N':
                return 'O';
        }
}

int main() {
    int N, M, S;
    while (scanf("%d %d %d", &N, &M, &S), N) {
        int x, y;
        char or;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                scanf(" %c", &G[i][j]);
                if (isupper(G[i][j])) {
                    y = i;
                    x = j;
                    or = G[i][j];
                }
                /* if (G[i][j] == 'N' || */
                /*         G[i][j] == 'S' || */
                /*         G[i][j] == 'L' || */
                /*         G[i][j] == 'O') { */
                /*     y = i; x = j; */
                /* } */
            }
            scanf("%s", cmd);

            for (int i=0; i<S; i++) {
                switch (cmd[i]) {
                    case 'D':
                    case 'E':
                        rot(G[y][x], cmd[i]);
                        break;
                    default:


                }


                }
                return 0;
            }

