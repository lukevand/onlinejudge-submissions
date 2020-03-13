#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
#define EPS 1e-9

struct point_i {
    int x, y;
    point_i() { x=y=0;}
    point_i(int _x, int _y) : x(_x), y(_y) {};
    bool operator < (point_i other) const {
        /* if (x-other.x > 0) */
        if (x < other.x) {
            return true;
        } else if (x == other.x) {
            return y < other.y;
        }
        return false;
        /* return y < other.y; */
    }
};

struct point {
    double x, y;
    point() { x=y=0; };
    point(double _x, double _y) : x(_x), y(_y) {}
};

struct line { double a, b, c; };

double dist(point p, point q) {
    return hypot(p.x - q.x, p.y - q.y);
}

void point2Line(point_i p1, point_i p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    } else {
        l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double) (l.a * p1.x) - p1.y;
    }
}

void intersect(line l1, line l2, point &p) {
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    p.y = -(l2.a * p.x + l2.c);
}


int main()
{
    int C, N, x, y;
    scanf("%d", &C);
    while (C--) {
        scanf("%d", &N);
        vector<point_i> peeks;
        for (int i=0; i<N; i++) {
            scanf("%d %d", &x, &y);
            peeks.emplace_back(x, y);
        }
        sort(peeks.begin(), peeks.end());
        reverse(peeks.begin(), peeks.end());

        int highest = 0;
        double total = 0;
        for (int i=1; i<N; i++) {
            if (peeks[i].y > highest) {
                line diagonalLine;
                point2Line(peeks[i], peeks[i-1], diagonalLine);

                line horizontalLine = {0.0, 1.0, -(double)highest};

                point intersectionPoint;
                intersect(diagonalLine, horizontalLine, intersectionPoint);

                point doublePoint(peeks[i].x, peeks[i].y);
                double len = dist(intersectionPoint, doublePoint);
                total += len;

                highest = peeks[i].y;
            }
        }
        printf("%.2f\n", total);
    }
    return 0;
}

