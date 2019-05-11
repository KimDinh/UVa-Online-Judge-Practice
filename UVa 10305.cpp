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

int n, m, degree[101];
vector<int> adj[101];
queue<int> q;

void toposort(){
	for(int u=1; u<=n; u++)
		if(degree[u]==0)
			q.push(u);
	while(!q.empty()){
		int u=q.front();
		cout << u;
		q.pop();
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i];
			if(--degree[v]==0)
				q.push(v);
		}
		if(!q.empty())
			cout << " ";
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int u, v;

	cin >> n >> m;
	while(n){
		memset(degree, 0, sizeof(degree));
		for(int i=0; i<m; i++){
			cin >> u >> v;
			adj[u].push_back(v);
			degree[v]++;
		}
		toposort();
		for(int u=1; u<=n; u++)
			adj[u].clear();
		cin >> n >> m;
	}

	return 0;
}