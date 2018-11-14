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

int bill(int x) {
    int s;
    if(x<=100)
        s = 2*x;
    else if(x<=10000)
        s = 2*100 + 3*(x-100);
    else if(x<=1000000)
        s = 2*100 + 3*9900 + 5*(x-10000);
    else s = 2*100 + 3*9900 + 5*990000 + 7*(x-1000000);
    return s;
}

int consume(int x) {
    int c = 0;
    if(x<=200) {
        c = x/2;
        return c;
    }
    else { x -= 200; c = 100; }
    if(x<=29700) {
        c += x/3;
        return c;
    }
    else { x -= 29700; c += 9900; }
    if(x<=4950000) {
        c += x/5;
        return c;
    }
    else { x -= 4950000; c += 990000; }
    c += x/7;
    return c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int A, B, l ,r, total, mid, diff;
    
    cin >> A >> B;
    while(A) {
        l=0;
        total = consume(A);
        r=total/2;
        mid = (l+r)/2;
        diff=bill(total-mid)-bill(mid);
        while(diff!=B) {
            if(diff<B)
                r = mid-1;
            else l = mid+1;
            mid = (l+r)/2;
            diff = bill(total-mid)-bill(mid);
        }
        cout << bill(mid) << endl;
        cin >> A >> B;
    }
    
    return 0;
}

