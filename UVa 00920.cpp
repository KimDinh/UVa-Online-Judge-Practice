#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <stack>
#include <iomanip>
using namespace std;

#define EPS 1e-9

struct point{
    double x, y;
    point(){}
    point(double _x, double _y){
        x = _x; y = _y;
    }
    bool operator < (point other) {
        if(fabs(x-other.x)>EPS)
            return x < other.x;
        return y < other.y;
    }
};

struct line{
    double a, b, c;
    line(){}
    line(double _a, double _b, double _c){
        a = _a; b = _b; c = _c;
    }
};

double dist(point p1, point p2){
    return hypot(p1.x-p2.x, p1.y-p2.y);
}

void pointsToLine(point p1, point p2, line& l){
    if(fabs(p1.x-p2.x)<EPS)
        l = {1.0, 0.0, -p1.x};
    else{
        double a = -(p1.y-p2.y)/(p1.x-p2.x);
        l = {a, 1.0, -a*p1.x-p1.y};
    }
}

bool areParallel(line l1, line l2){
    return (fabs(l1.a-l2.a)<EPS) && (fabs(l1.b-l2.b)<EPS);
}

bool areIntersect(line l1, line l2, point& p){
    if(areParallel(l1, l2)) return false;
    p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
    if(fabs(l1.b)>EPS)
        p.y = -(l1.a*p.x + l1.c);
    else p.y = -(l2.a*p.x + l2.c);
    return true;
}

int main(){
    int T, n;
    double x, y, len;
    vector<point> p;

    cin >> T;
    while(T--){
        cin >> n;
        p.clear();
        for(int i=0; i<n; i++){
            cin >> x >> y;
            p.emplace_back(x, y);
        }
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());
        len = 0;
        point prev_peak = p[0];
        for(int i=0; i<n-1; i+=2){
            if(p[i+1].y<=prev_peak.y)
                continue;
            line l1(0.0, 1.0, -prev_peak.y), l2;
            pointsToLine(p[i], p[i+1], l2);
            point p1;
            areIntersect(l1, l2, p1);
            len += dist(p[i+1], p1);
            prev_peak = p[i+1];
        }
        cout << fixed << setprecision(2) << len << "\n";
    }

    return 0;
}