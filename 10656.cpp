#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
typedef vector<int> VI;

int main() {
    int n, x;
    while (scanf("%d", &n), n) {
        bool seen0 = false;
        VI re;
        for (int i=0; i<n; i++) {
            scanf("%d", &x);
            if (x > 0) re.push_back(x);
            else if (x == 0) seen0 = true;
        }
        if (re.empty() && seen0) {
            printf("0\n");
        } else {
            for (int i=0; i<(int)re.size(); i++) {
                printf("%d%c", re[i], (i==(int)re.size()-1 ? '\n' : ' '));
            }
        }
    }

}

