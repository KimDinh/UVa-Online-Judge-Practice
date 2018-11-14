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
    int T, n, x, max, index, cases=1, k;
    vector<int> r;
    
    cin >> T;
    while(T--) {
        cin >> n;
        max = 0;
        for(int i=0; i<n; i++) {
            cin >> x;
            r.push_back(x);
            if(i==0) {
                max = r[i];
                index = i;
            }
            else if(max<r[i]-r[i-1]) {
                max = r[i]-r[i-1];
                index = i;
            }
        }
        k = max-1;
        for(int i=index; i<n-1; i++) {
            if(r[i+1]-r[i]>k) {
                max++;
                break;
            }
            else if(r[i+1]-r[i]==k)
                k--;
        }
        cout << "Case " << cases << ": " << max << endl;
        cases++;
        r.clear();
    }
    
    return 0;
}
