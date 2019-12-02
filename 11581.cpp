#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,a,b,c;
    scanf("%d\n", N);
    while (N--) {
        vector<vector<int>> G(3, vector<int>(3));
        for (int i=0; i<3; i++) {
            scanf("%d%d%d", &a, &b,&c);
            G[i][0]=a;
            G[i][1]=b;
            G[i][2]=c;
        }



    return 0;
}

