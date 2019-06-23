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

int dp[1001][1001], transition[1001][1001];
string str;

int PalindromeEdit(){
	int n = str.length();
	for(int i=0; i<n; i++){
		dp[i][i] = 0;
		if(i>0)
			dp[i][i-1] = 0;
	}
	for(int len=2; len<=n; len++)
		for(int l=0; l<=n-len; l++){
			int r = l+len-1;
			if(str[l]==str[r]){
				dp[l][r] = dp[l+1][r-1];
				transition[l][r] = 1;
			}
			else if(dp[l][r-1]<=dp[l+1][r]){
				dp[l][r] = dp[l][r-1]+1;
				transition[l][r] = 2;
			}
			else{
				dp[l][r] = dp[l+1][r]+1;
				transition[l][r] = 3;
			}
		}
	return dp[0][n-1];
}

void MakePalindrome(int l, int r, string& start, string& end){
	if(l>r)
		return;
	if(l==r){
		start += str[l];
		return;
	}
	if(transition[l][r]==1){
		start += str[l];
		end = str[l]+end;
		MakePalindrome(l+1, r-1, start, end);
	}
	else if(transition[l][r]==2){
		start += str[r];
		end = str[r]+end;
		MakePalindrome(l, r-1, start, end);
	}
	else{
		start += str[l];
		end = str[l]+end;
		MakePalindrome(l+1, r, start, end);
	}
}

int main(){
	while(!cin.eof()){
		cin >> str;
		cout << PalindromeEdit() << " ";
		string start="", end="";
		MakePalindrome(0, str.length()-1, start, end);
		cout << start+end << "\n";
	}

	return 0;
}