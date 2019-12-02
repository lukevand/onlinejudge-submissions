#include <bits/stdc++.h>
using namespace std;

#define print(x) //cerr << "DEBUG " << #x << ": " << x << endl

int main() {
    int N, n, m;
    char c;
    scanf("%d", &N);
    while (N--) {
        scanf(" %c %d %d", &c, &n, &m);
        print(c);
        switch (c) {
            case 'r':
            case 'Q':
                printf("%d\n", min(n,m));
                break;
            case 'k':
                printf("%d\n", (m*n + 1)/2);
                break;
            case 'K':
                printf("%d\n", ((m+1)/2) * ((n+1)/2));
                break;
        }
    }

    return 0;
}

