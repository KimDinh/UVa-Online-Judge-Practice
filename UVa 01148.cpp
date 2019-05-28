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

int n;
vector<int> adj[100001], dist;

//BFS and mark the distance of vertices from start
void bfs(int start, int end){
	dist.assign(n, 1e8);
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i];
			if(dist[v]>dist[u]+1){
				dist[v] = dist[u]+1;
				q.push(v);
				if(v==end)
					return;
			}
		}
	}
}

int main(){
	int T, u, v, m;

	cin >> T;
	while(T--){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> u >> m;
			for(int j=0; j<m; j++){
				cin >> v;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
		cin >> u >> v;
		bfs(u, v);
		cout << u << " " << v << " " << dist[v]-1 << "\n";
		if(T)
			cout << "\n";
		for(int i=0; i<n; i++)
			adj[i].clear();
	}

	return 0;
}