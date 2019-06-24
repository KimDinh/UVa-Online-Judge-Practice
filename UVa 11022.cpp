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

string s;
int same_len[80][80], dp[80][80], n;

int min_weight(){
    for(int i=0; i<n; i++)
        dp[i][i] = 1;
    for(int len=2; len<=n; len++)
        for(int i=0, j=len-1; j<n; i++, j++){
            dp[i][j] = j-i+1;
            for(int k=i; k<j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
            for(int k=1; k<len; k++)
                if(len%k==0){
                    bool intogroup = 1;
                    for(int ii=i; ii<=j; ii+=k)
                        if(same_len[i][ii]<k){
                            intogroup = 0;
                            break;
                        }
                    if(intogroup)
                        dp[i][j] = min(dp[i][j], dp[i][i+k-1]);
                }
        }
    return dp[0][n-1];
}

int main(){
    while(cin >> s && s[0]!='*'){
        n = s.length();
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++){
                same_len[i][j] = 0;
                for(int len=1; j<=n-len; len++){
                    if(s[i+len-1]==s[j+len-1])
                        same_len[i][j] = len;
                    else break;
                }
            }
        cout << min_weight() << "\n";
    }

    return 0;
}