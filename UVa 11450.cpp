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
    int T, M, C, K, price[20][21];
    bool dp[20][201];
    
    cin >> T;
    while(T--) {
        cin >> M >> C;
        for(int i=0; i<C; i++) {
            cin >> K;
            price[i][0] = K;
            for(int j=1; j<=K; j++)
                cin >> price[i][j];
        }
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=price[0][0]; i++)
            if(price[0][i]<=M)
                dp[0][M-price[0][i]] = 1;
        for(int g=1; g<C; g++)
            for(int m=0; m<M; m++) {
                if(dp[g-1][m]){
                    for(int i=1; i<=price[g][0]; i++)
                        if(price[g][i]<=m)
                            dp[g][m-price[g][i]] = 1;
                }
            }
        int m=0;
        while(m<M && !dp[C-1][m])
            m++;
        if(m==M)
            cout << "no solution\n";
        else cout << M-m << endl;
    }
    
    return 0;
}

