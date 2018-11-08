#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;

bool SearchElement(long long s[], int left, int right, long long x) {
    if(right>=left) {
        int mid = (left+right)/2;
        if(s[mid]==x)
            return true;
        if(s[mid]<x)
            return SearchElement(s, mid+1, right, x);
        return SearchElement(s, left, mid-1, x);
    }
    return false;
}

int main() {
    int n;
    long long s[1010], M;
    bool found;
    cin >> n;
    while(n) {
        found = false;
        for(int i=0; i<n; i++)
            cin >> s[i];
        sort(s, s+n);
        for(int d=n-1; d>=3; d--){
            for(int c=d-1; c>=2; c--){
                for(int b=c-1; b>=1; b--) {
                    long long a=s[d]-s[c]-s[b];
                    if(SearchElement(s, 0, b-1, a)){
                        found = true;
                        M = s[d];
                        break;
                    }
                }
                if(found)
                    break;
            }
            if(found)
                break;
        }
        if(found)
            cout << M;
        else cout << "no solution";
        cin >> n;
        if(n)
            cout << endl;
    }
    
    return 0;
}
