#include <bits/stdc++.h>

using namespace std;

#define debug(XXX) cerr << #XXX << ": " << XXX << '\n'
#define debugv(X) cerr << #X << ": "; for(auto const& CCC:X) std::cerr<<CCC<<' '; cerr<<'\n'
#define debuga(X, _a, _b) cerr << #X << ": "; for (int _i=_a; _i<_b; _i++) cout << X[_i] << " "; cout << '\n';
#define debugapair(X, _a, _b) cerr << #X << ": "; for (int _i=_a; _i<_b; _i++) cout << '(' << X[_i].first << ',' << X[_i].second << ')' << " "; cout << '\n';

#define EPS e-9

struct point_i {
    int x, y;
    point_i() { x=y=0;}
    point_i(int _x, int _y) : x(_x), y(_y) {};
    bool operator < (point_i other) const {
        if (x-other.x > 0)
            return x < other.x;
        return y < other.y;
    }
};
struct line { double a, b, c; };

double dist_i(point_i p, point_i q) {
    return hypot(p.x - q.x, p.y - q.y);
}




int main()
{
    int C, N, x, y;
    scanf("%d", &C);
    while (C--) {
        scanf("%d", &N);
        vector<point_i> A(N, point_i());
        for (int i=0; i<N; i++) {
            scanf("%d %d", &x, &y);
            A[i] = point_i(x, y);
        }
        sort(A.begin(), A.end());


    return 0;
}

