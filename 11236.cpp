#include <bits/stdc++.h>
using namespace std;

long w;

int main() {
    for (long x=1; x<=125; x++) {
        for (long y=x; y<=600; y++) {
            if (x+y > 2000) break;
            for (long z=y; z<=900; z++) {
                if (x*y*z <= 1000000) continue;
                w = (1000000*(x+y+z))/(x*y*z - 1000000);
                if (x+y+z+w > 2000 || w<z) continue;
                    if ((x+y+z+w)*1000000 == x*y*z*w) {
                        printf("%ld.%.2ld %ld.%.2ld %ld.%.2ld %ld.%.2ld\n", x/100, x%100, y/100, y%100, z/100, z%100, w/100, w%100);
                    }
                }
            }
        }
    return 0;
}

