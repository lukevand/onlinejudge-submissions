#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
bitset<100> used;
unordered_set<int> s;

int main() {
    int n;
    used.reset();
    vector<int> ss;
    for (int i=1; i<=20; i++) {
        for (int j=1; j<=3; j++) {
            if (!used[i*j]) {
                used[i*j] = 1;
                ss.push_back(i*j);
            }
        }
    }
    ss.push_back(50);
    ss.push_back(0);
    sort(begin(ss), end(ss));
    int size=ss.size();
    while (scanf("%d", &n), n > 0) {
        int perm = 0;
        s.clear();
        used.reset();

        for (int x: ss) {
            if (x > n) break;
            for (int y: ss) {
                if (x+y > n) break;
                for (int z: ss) {
                    if (x+y+z > n) break;
                    if (x+y+z == n) {
                        perm++;
                    }
                }
            }
        }
        int comb=0;
        for (int i=0; i<size; i++) {
            for (int j=i; j<size; j++) {
                for (int k=j; k<size; k++) {
                    if (ss[i] + ss[j] + ss[k] == n) comb++;
                }
            }
        }
        if (comb != 0) {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, comb);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, perm);
        } else {
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
        }
        printf("**********************************************************************\n");
    }
    printf("END OF OUTPUT\n");


}

