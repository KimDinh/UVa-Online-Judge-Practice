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

int n, m, degree[1000001];
vector<int> adj[1000001];
queue<int> q, order;

bool toposort(){
	for(int u=1; u<=n; u++)
		if(degree[u]==0)
			q.push(u);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		order.push(u);
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i];
			if(--degree[v]==0)
				q.push(v);
		}
	}
	for(int u=1; u<=n; u++)
		if(degree[u]>0)
			return false;
	return true;
}

int main(){
	int u, v;

	cin >> n >> m;
	while(n){
		memset(degree, 0, sizeof(degree));
		for(int i=0; i<m; i++){
			cin >> u >> v;
			adj[u].push_back(v);
			degree[v]++;
		}
		if(toposort()){
			while(!order.empty()){
				cout << order.front() << "\n";
				order.pop();
			}
		}
		else cout << "IMPOSSIBLE\n";
		while(!order.empty())
			order.pop();
		for(int u=1; u<=n; u++)
			adj[u].clear();
		cin >> n >> m;
	}


	return 0;
}