#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
#define EPS 1e-9
int p, q, r, s, t, u;

double f(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x, 2.0) + u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> p >> q >> r >> s >> t >> u) {
        double lo = 0.0, hi = 1.0, mid = 0.0, ans = 0.0;
        if (p + r + u == 0) {
            printf("0.0000\n");
            continue;
        }
        if (fabs(p*1.0/M_E + q*sin(1) + r*cos(1) + s*tan(1) + t + u) < EPS) {
            printf("1.0000\n");
            continue;
        }
        bool x0Pos = (p+r) > -u;
        while (fabs(hi - lo) > EPS) {
            mid = (lo + hi)/2.0;
            if (f(mid) > 0) {
                if (x0Pos) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            } else {
                if (x0Pos) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            ans = mid;
        }

        if ((lo-0.0)<EPS || (1.0-hi)<EPS) {
            printf("No solution\n");
        } else {
            printf("%.4lf\n", ans);
        }
    }
}

