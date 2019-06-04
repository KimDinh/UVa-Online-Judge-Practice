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

#define ii pair<int, int>

int n, dist[501][2];
vector<ii> adj[501];

struct Comp{
	bool operator()(pair<ii, int> p1, pair<ii, int> p2){
		return p1.first.first>p2.first.first;
	}
};

//Dijkstra to find shortest path, dist[i][0] and dist[i][1]
//are the length of the path using an even and odd number of edges
void Dijkstra(){
	for(int i=0; i<n; i++){
		dist[i][0] = dist[i][1] = 1e8;
	}
	dist[0][0] = 0;
	priority_queue<pair<ii, int>, vector<pair<ii, int>>, Comp> q;
	q.push(make_pair(ii(0, 0), 0));
	while(!q.empty()){
		int u = q.top().second, d = q.top().first.first, edge_num = q.top().first.second;
		q.pop();
		if(d>dist[u][edge_num])
			continue;
    if(u==n-1 && !edge_num)
      return;
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i].first; d = adj[u][i].second;
			if(dist[v][1-edge_num]>dist[u][edge_num]+d){
				dist[v][1-edge_num] = dist[u][edge_num]+d;
				q.push(make_pair(ii(dist[v][1-edge_num], 1-edge_num), v));
			}
		}
	}
}

int main(){
	int r, u, v, c, cases=1;

	while(cin >> n >> r){
		for(int i=0; i<n; i++)
			adj[i].clear();
		for(int i=0; i<r; i++){
			cin >> u >> v >> c;
			adj[u].push_back(ii(v, c));
			adj[v].push_back(ii(u, c));
		}
		Dijkstra();
		cout << "Set #" << cases++ << endl;
		if(dist[n-1][0]==1e8)
			cout << "?\n";
		else cout << dist[n-1][0] << endl;
	}

	return 0;
}