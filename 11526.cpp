#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

long long H(int n) {
    long long res = 0;
    /* print("int " << n); */
    for( int i = 1; i <= n; i=i+1 ){
        res = (res + n/i);
        /* print(n/i << ' ' << res << ' ' << i); */
    }
    /* cout << '\n'; */
    return res;
}

long long F(int n) {
    if (n <= 0) return 0;
    int sq = (int)(sqrt(n));
    long long res = 0;
    for (int i=1; i<=sq; i++) {
        res += n / i;
        /* print(res); */
        res += i * (n/i - n/(i+1));
        /* print(res); */
    }
    if (sq*sq == n) {
        res -= sq;
    }
    /* if (n%2 == 1) { */
    /*     res -= sq; */
    /* } */
    return res;
}

int main()
{
    for (int i=1; i<21; i++) {
        cout << i << ' ' << H(i) << ' ' << F(i) <<  '\n';
    }

    return 0;
}

