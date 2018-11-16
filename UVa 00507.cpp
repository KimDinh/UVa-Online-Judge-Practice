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

int main() {
    int a[20000], T, c=1, s, m, le, ri, l, r;
    vector<int> b;
    
    cin >> T;
    while(T--) {
        m = le = ri = l = r = 0;
        cin >> s;
        for(int i=0; i<s-1; i++)
            cin >> a[i];
        for(int i=0; i<s-1; i++) {
            if(i==0)
                b.push_back(a[i]);
            else {
                b.push_back(max(b[i-1]+a[i], a[i]));
                ri = i;
                if(b[i-1]<0)
                    le = i;
            }
            if(m<b[i]) {
                m = b[i];
                l = le; r = ri;
            }
            else if(m==b[i] && r-l<ri-le) {
                l = le; r = ri;
            }
        }
        if(m==0)
            cout << "Route " << c << " has no nice parts\n";
        else cout << "The nicest part of route " << c << " is between stops " << l+1 << " and " << r+2 << endl;
        c++;
        b.clear();
    }
    
    return 0;
}

