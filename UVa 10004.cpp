#include <iostream>
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
#include <stack>
#include <iomanip>
using namespace std;

int n, l, color[200];
vector<int> adj[200];

bool bicolor_dfs(int i) {
	stack<int> s; 
	bool check = true;
	color[i] = 0;
	s.push(i);
	while(!s.empty() && check) {
		int u=s.top();
		s.pop();
		for(int j=0; j<adj[u].size(); j++) {
			int v = adj[u][j];
			if(color[v]==-1) {
				color[v] = 1 - color[u];
				s.push(v);
			}
			else if(color[v]==color[u]) {
				check = false;
				break;
			}
		}
	}
	return check;
}

bool bicolor() {
	bool check=true;
	for(int i=0; i<n; i++)
		if(color[i]==-1 && !bicolor_dfs(i))
			return false;
	return true;
}

int main() {
	cin >> n;
	int u, v;
	while(n!=0) {
		cin >> l;
		for(int i=0; i<l; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(color, -1, sizeof(color));
		if(bicolor())
			cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";
		for(int i=0; i<n; i++)
			adj[i].clear();
		cin >> n;
	} 

	return 0;
}