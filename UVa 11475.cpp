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

vector<int> pi;

void prefix_function(string P){
	pi.clear();
	pi.resize(P.length());
	pi[0] = 0;
	int j = 0;
	for(int i=1; i<P.length(); i++){
		while(j>0 && P[j]!=P[i])
			j = pi[j-1];
		if(P[j]==P[i])
			j++;
		pi[i] = j;
	}
}

int main(){
	string s, rev;
	bool first=1;

	while(!cin.eof()){
		if(!first)
			cout << "\n";
		first = 0;
		getline(cin, s);
		rev = s;
		reverse(rev.begin(), rev.end());
        prefix_function(rev);
		int j=0;
		for(int i=0; i<s.length(); i++){
			while(j>0 && rev[j]!=s[i])
				j = pi[j-1];
			if(rev[j]==s[i])
				j++;
            
		}
		if(j==0)
			cout << s;
		else{
			for(int i=j; i<rev.length(); i++)
				s += rev[i];
			cout << s;
		}
	}

	return 0;
}