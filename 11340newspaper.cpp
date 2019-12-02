#include <bits/stdc++.h>
using namespace std;

using L = long long;


L d[200];

int main()
{
    int N, K, M;
    int a;
    char ch;
    int c;
    map<char,int> value;
    scanf("%d", &N);
    while (N--) {
        memset(d, 0, sizeof d);
        value.clear();
        scanf("%d", &K);
        while (K--) {
            scanf(" %c %d", &ch, &a);
            value.emplace(ch, a);
        }
        scanf("%d", &M);
        M++;
        while (M--) {
            while ((c = getc(stdin)) != '\n') {
                d[c] += 1;
            }
        }
        L total=0;
        for (auto it=value.begin(); it!=value.end(); ++it) {
            total += d[(int)it->first]*it->second;
        }
        printf("%lld.%02lld$\n", total/100, total%100);

    }

    return 0;
}

