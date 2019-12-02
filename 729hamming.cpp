#include <bits/stdc++.h>
using namespace std;

#define debugp(X) for(auto const& CCC:X) std::cerr<<CCC<<' '; cerr<<'\n'
#define debug(XXX) cerr << #XXX << ": " << XXX << '\n'

void print_bits(unsigned int value, unsigned int bits)
{
    unsigned mask = 1 << (bits-1);

    while (mask) {
        printf("%d", (mask & value) != 0);
        mask >>= 1;
    }
    printf("\n");
}

int main()
{
    int n;
    int N, H;
    int c;
    int j;
    scanf("%d", &n);
    while (n--) {
        scanf(" %d %d", &N, &H);
        for (int i=1; i<(1<<N); i++) {
            c = 0;
            j = i;
            for (; j && c<=H; c++) {
                j &= (j-1);
            }
            if (c==H) {
                print_bits(i, N);
            }
        }
        if (n > 0) printf("\n");
    }

    return 0;
}

