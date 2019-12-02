#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> powers = {1, 2, 4, 8, 16, 32, 64, 128};
    int n;
    while (scanf("%d", &n), n) {
        printf("Printing order for %d pages:\n", n);
        if (n == 1) {
            printf("Sheet 1, front: Blank, 1\n");
            continue;
        }

        int sheet = (n+3)/4;
        int a=1, b=sheet*4;

        for (int i=1; i<= sheet; i++) {
            printf("Sheet %d, front: %s, %d\n", i, (b > n) ? "Blank" : to_string(b).c_str(), a);
            b--, a++;
            printf("Sheet %d, back : %d, %s\n", i, a, (b > n) ? "Blank" : to_string(b).c_str());
            b--, a++;
        }
    }

    return 0;
}

