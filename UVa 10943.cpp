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
    int n, k, dp[101][101];
    
    cin >> n >> k;
    while(n) {
        for(int i=0; i<=n; i++)
            dp[i][1] = 1;
        for(int i=2; i<=k; i++)
            dp[0][i] = 1;
        for(int i=1; i<=n; i++)
            for(int j=2; j<=k; j++)
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%M;
        cout << dp[n][k] << endl;
        cin >> n >> k;
    }
    
    return 0;
}

