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


int main(){
	string s;
	char l3prev[3], l4prev[4];
	int l3count, l4count;

	while(cin >> s){
		l3count = l4count = 0;
		for(int i=0; i<s.length(); i++){
			if(i+2<s.length() && s[i]==s[i+2]){
				if(l3count==0){
					l3count++;
					s.copy(l3prev, 3, i);
				}
				else if(s[i]!=l3prev[0] || s[i+1]!=l3prev[1]){
					l3count++;
					break;
				}
			}
			else if(i+3<s.length() && s[i]==s[i+3] && s[i+1]==s[i+2]){
				if(l4count==0){
					l4count++;
					s.copy(l4prev, 4, i);
				}
				else if(s[i]!=l4prev[0] || s[i+1]!=l4prev[1]){
					l4count++;
					break;
				}
			}
		}
		if(l3count+l4count>=2)
			cout << s << "\n";
	}

	return 0;
}