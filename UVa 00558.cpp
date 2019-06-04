//Assume that any star system is reachable from
//our solar system, just like the problem statement says. 
//Some of the tests on uDebug don't follow this condition.
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

int n, m, dist[1000];
vector<ii> adj[1000];

void BellmanFord(){
	for(int i=0; i<n; i++)
		dist[i] = 1e9;
	dist[0] = 0;
	for(int i=0; i<n-1; i++)
		for(int u=0; u<n; u++)
			for(int j=0; j<adj[u].size(); j++){
				int v = adj[u][j].first, d = adj[u][j].second;
				if(dist[v]>dist[u]+d)
					dist[v] = dist[u]+d;
			}
}

int main(){
	int u, v, d, T;
	bool negative_cycle;

	cin >> T;
	for(int c=1; c<=T; c++){
		cin >> n >> m;
		for(int i=0; i<n; i++)
			adj[i].clear();
		for(int i=0; i<m; i++){
			cin >> u >> v >> d;
			adj[u].push_back(ii(v, d));
		}
		BellmanFord();
		negative_cycle = 0;
		for(int u=0; u<n; u++){
			for(int i=0; i<adj[u].size(); i++){
				v = adj[u][i].first; d = adj[u][i].second;
				if(dist[v]>dist[u]+d){
					negative_cycle = 1;
					break;
				}
			}
			if(negative_cycle)
				break;
		}
		if(negative_cycle)
			cout << "possible\n";
		else cout << "not possible\n";
	}

	return 0;
}