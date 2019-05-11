#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <unordered_set>
#include <stack>
#include <iomanip>
using namespace std;

vector<int> adj[21];
bool visited[21], NO;
unordered_map<char, int> chartoint;
vector<char> inttochar;
int n;

void backtrack(string result){
	bool full=1;
	for(int u=0; u<n; u++)
		if(!visited[u]){
			bool choose=1;
			for(int i=0; i<adj[u].size(); i++){
				int v=adj[u][i];
				if(!visited[v])
					choose = 0;
			}
			if(choose){
				visited[u] = 1;
				backtrack(result + inttochar[u]);
				visited[u] = 0;
			}
			full = 0;
		}
	if(full){
		NO = 0;
		cout << result[0];
		for(int i=1; i<result.length(); i++)
			cout << " " << result[i];
		cout << endl;
	}
}

int main(){
	int Case;
	string s;

	cin >> Case;
	getline(cin, s);
	while(Case--){
		getline(cin, s);
		getline(cin, s);
		n = 0;
		for(int i=0; i<s.length(); i++)
			if(s[i]!=' '){
				inttochar.push_back(s[i]);
				n++;
			}
		sort(inttochar.begin(), inttochar.end());
		for(int i=0; i<inttochar.size(); i++)
			chartoint.insert(make_pair(inttochar[i], i));
		getline(cin, s);
		for(int i=0; i<s.length(); i++)
			if(s[i]=='<'){
				auto f1=chartoint.find(s[i-1]), f2=chartoint.find(s[i+1]);
				int u=f1->second, v=f2->second;
				adj[v].push_back(u);
			}
		memset(visited, 0, sizeof(visited));
		NO = 1;
		backtrack("");
		if(NO)
			cout << "NO\n";
		if(Case)
			cout << endl;
		for(int i=0; i<n; i++)
			adj[i].clear();
		chartoint.clear();
		inttochar.clear();
	}


	return 0;
}