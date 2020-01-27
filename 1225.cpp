#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
int A[10];

void adddig(int n) {
    while (n > 0) {
        ++A[n%10];
        n /= 10;
    }
}

int main() {
    int TC;
    int n;
    scanf("%d", &TC);
    while (TC--) {
        memset(A, 0, sizeof A);
        scanf("%d", &n);
        while (n) adddig(n--);
        for (int i=0; i<10; i++) printf("%d%c", A[i], i==9 ? '\n' : ' ');
    }
}

