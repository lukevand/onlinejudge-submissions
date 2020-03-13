#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'

bitset<10000010> bs;
long sieve_size;

vector<long> primes;

void sieve(long upperbound) {
    bs.set();
    sieve_size = upperbound+1;

    bs[0] = bs[1] = 0;

    for (long i=2; i<= sieve_size; i++) {
        if (bs[i]) {
            for (long j=i*i; j<sieve_size; j+=i) {
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

int main() {
    sieve((long)1e7);
    cout << primes.size() << '\n';
    cout << primes[primes.size()-1] << '\n';
}

