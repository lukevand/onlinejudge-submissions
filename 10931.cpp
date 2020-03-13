#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

int main() {
    uint32_t n;
    while (scanf("%u", &n), n != 0) {
        uint32_t x = n;
        int count = 0;
        while (x) {
            if (x & 1) count++;
            x>>=1;
        }
        printf("The parity of %d is %d (mod 2).\n", n, count);
    }


}

