#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    while (cin >> s, s != "DONE") {
        auto start = begin(s);
        auto last = begin(s);
        while (start != last) {
            if (isalpha(*start) && isalpha(*last) && tolower(*start) != tolower(*last)) {
                printf("Oh oh\n");
                return 0;
            }
            if (!isalpha(*start)) {
                start++;
            }
            if (!isalpha(*last)) {
                last--;
            }
        }
        printf("sae\n");
    }

    return 0;
}

