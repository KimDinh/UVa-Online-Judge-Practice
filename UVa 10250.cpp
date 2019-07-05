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

#define PI acos(-1.0)
#define EPS 1e-9

double DEG_to_RAD(double d){
    return d*PI/180.0;
}

struct point{
    double x, y;
    point(){}
    point(double _x, double _y){
        x = _x; y = _y;
    }
};

point rotate(point p, double theta){
    double rad = DEG_to_RAD(theta);
    return point(p.x*cos(rad) - p.y*sin(rad), 
                p.x*sin(rad) + p.y*cos(rad));
}

int main(){
    point p1, p2, p3, p4;

    while(!cin.eof()){
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        if(fabs(p1.x-p2.x)<EPS && fabs(p1.y-p2.y)<EPS){
            cout << "Impossible.\n";
            continue;
        }
        point mid((p1.x+p2.x)/2, (p1.y+p2.y)/2);
        p3 = rotate(point(p1.x-mid.x, p1.y-mid.y), 90.0);
        p4 = rotate(point(p2.x-mid.x, p2.y-mid.y), 90.0);
        cout.precision(10);
        cout << fixed;
        cout << p3.x+mid.x << " " << p3.y+mid.y << " ";
        cout << p4.x+mid.x << " " << p4.y+mid.y << "\n";
    }

    return 0;
}