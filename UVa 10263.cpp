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
};

struct vec{
    double x, y;
    vec(){}
    vec(double _x, double _y){
        x = _x; y = _y;
    }
};

double dist(point p1, point p2){ return hypot(p1.x-p2.x, p1.y-p2.y); }

vec toVec(point a, point b){ return vec(b.x-a.x, b.y-a.y); }

vec scale(vec v, double s){ return vec(v.x*s, v.y*s); }

point translate(point p, vec v){ return point(p.x+v.x, p.y+v.y); }

double dot(vec a, vec b){ return (a.x*b.x + a.y*b.y); }

double norm_sq(vec v){ return (v.x*v.x + v.y*v.y); }

double distToLine(point p, point a, point b, point& c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab)/norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point& c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab)/norm_sq(ab);
    if(u<0.0){ c = point(a.x, a.y); return dist(p, a); }
    if(u>1.0){ c = point(b.x, b.y); return dist(p, b); }
    return distToLine(p, a, b, c);
}

int main(){
    point M, station, stn;
    vector<point> p;
    int N;
    double x, y, min_dist;

    while(cin >> M.x >> M.y >> N){
        p.clear();
        for(int i=0; i<N+1; i++){
            cin >> x >> y;
            p.emplace_back(x, y);
        }
        min_dist = dist(M, p[0]);
        station = p[0];
        for(int i=0; i<N; i++){
            double d = distToLineSegment(M, p[i], p[i+1], stn);
            if(min_dist>d){
                min_dist = d;
                station = stn;
            }
        }
        cout.precision(4);
        cout << fixed << station.x << "\n" << station.y << "\n";
    }

    return 0;
}