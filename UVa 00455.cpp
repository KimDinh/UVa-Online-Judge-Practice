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
#include <unordered_set>
#include <stack>
#include <iomanip>
using namespace std;

int pi[100];

int period(string P){
	pi[0] = 0;
	int j=0, n = P.length();
	for(int i=1; i<n; i++){
		while(j>0 && P[i]!=P[j])
			j = pi[j-1];
		if(P[j]==P[i])
			j++;
		pi[i] = j;
	}
	if(n%(n-j))
		return n;
	return n-j;
}

int main(){
	int T;
	string s;

	cin >> T;
	while(T--){
		cin >> s;
		cout << period(s) << "\n";
		if(T)
			cout << "\n";
	}

	return 0;
}