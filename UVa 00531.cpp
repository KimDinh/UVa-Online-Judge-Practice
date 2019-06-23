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

vector<string> v1, v2;
int n, m, dp[101][101], step[101][101];
bool firstword;

void LCS(){
	n = v1.size();
	m = v2.size();
	dp[0][0] = 0;
	for(int i=1; i<=n; i++)
		dp[i][0] = 0;
	for(int j=1; j<=m; j++)
		dp[0][j] = 0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++){
			if(v1[i-1]==v2[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
				step[i][j] = 1;
			}
			else if(dp[i][j-1]>=dp[i-1][j]){
				dp[i][j] = dp[i][j-1];
				step[i][j] = 2;
			}
			else{
				dp[i][j] = dp[i-1][j];
				step[i][j] = 3;
			}
		}
}

void printLCS(int x, int y){
	if(x==0 || y==0)
		return;
	if(step[x][y]==1){
		printLCS(x-1, y-1);
		if(!firstword)
			cout << " ";
		cout << v1[x-1];
		firstword = 0;
	}
	else if(step[x][y]==2)
		printLCS(x, y-1);
	else printLCS(x-1, y);
}

int main(){
	string s;
	bool firstline=1;

	while(!cin.eof()){
		if(!firstline)
			cout << "\n";
		firstline = 0;
		v1.clear();
		v2.clear();
		while(cin >> s && s[0]!='#')
			v1.push_back(s);
		while(cin >> s && s[0]!='#')
			v2.push_back(s);
		LCS();
		firstword = 1;
		printLCS(n, m);
	}

	return 0;
}