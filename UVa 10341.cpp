#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <iomanip>
using namespace std;

int p, q, r, s, t, u;

double F(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}


int main() {
    double le, ri, mid, f;
    
    cin >> p;

    while(!cin.eof()) {
        le = 0; ri = 1;
        cin >> q >> r >> s >> t >> u;
        if(!p && !q && !r && !s && !t && !u) {
            cout << "0.0000\n";
            cin >> p;
            continue;
        }
        if(F(0)<-1e-7 || F(1)>1e-7) {
            cout << "No solution\n";
            cin >> p;
            continue;
        }
        mid = (le+ri)/2;
        f = F(mid);
        while(fabs(f)>1e-7) {
            if(f>1e-7)
                le = mid;
            else ri = mid;
            mid = (le+ri)/2;
            f = F(mid);
        }
        cout << fixed << setprecision(4) << mid << endl;
        cin >> p;
    }
    
    return 0;
}
