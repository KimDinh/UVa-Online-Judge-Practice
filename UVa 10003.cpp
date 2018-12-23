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
#include <unordered_map>
#include <iomanip>
using namespace std;

const int M = 1e6;

int main() {
    int l, n, a[52], dp[52][52];
    
    cin >> l;
    while(l) {
        cin >> n;
        a[0] = 0; a[n+1] = l;
        for(int i=1; i<=n; i++)
            cin >> a[i];
        for(int i=0; i<=n; i++)
            dp[i][i+1] = 0;
        for(int r=2; r<=n+1; r++)
            for(int l=0; l<=n+1-r; l++) {
                dp[l][r+l] = a[r+l] - a[l];
                int m = M;
                for(int i=l+1; i<r+l; i++)
                    m = min(m, dp[l][i] + dp[i][r+l]);
                dp[l][r+l] += m;
            }
        cout << "The minimum cutting is " << dp[0][n+1] << ".\n";
        cin >> l;
    }
    
    return 0;
}
