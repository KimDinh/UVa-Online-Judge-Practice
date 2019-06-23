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

string A, B;
int n, m, dp[101][101];

int LCS(){
	n = A.length();
	m = B.length();
	dp[0][0] = 0;
	for(int i=1; i<=n; i++)
		dp[i][0] = 0;
	for(int j=1; j<=m; j++)
		dp[0][j] = 0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++){
			if(A[i-1]==B[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else if(dp[i][j-1]>=dp[i-1][j])
				dp[i][j] = dp[i][j-1];
			else
				dp[i][j] = dp[i-1][j];
		}
	return dp[n][m];
}

int main(){
	string s;
	int cases=1;

	while(getline(cin, A) && A[0]!='#'){
		getline(cin, B);
		printf("Case #%d: you can visit at most %d cities.\n", cases++, LCS());
	}

	return 0;
}