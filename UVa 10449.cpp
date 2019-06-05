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

#define ii pair<int, long long>

int n;
long long business[201], dist[201];
vector<ii> adj[201];
bool reachable[201];

void bfs(){
    for(int i=1; i<=n; i++)
        reachable[i] = 0;
    reachable[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].first;
            if(!reachable[v]){
                reachable[v] = 1;
                q.push(v);
            }
        }
    }
}

void BellmanFord(){
	for(int i=1; i<=n; i++)
		dist[i] = 1e9;
	dist[1] = 0;
	for(int i=0; i<n-1; i++)
		for(int u=1; u<=n; u++)
			for(int j=0; j<adj[u].size(); j++){
				int v = adj[u][j].first;
                long long d = adj[u][j].second;
				dist[v] = min(dist[v], dist[u]+d);
			}
}

int main(){
	int r, q, u, v, cases=1;
    long long d;

	while(cin >> n){
		for(int i=1; i<=n; i++)
			adj[i].clear();
		for(int i=1; i<=n; i++)
			cin >> business[i];
		cin >> r;
		for(int i=0; i<r; i++){
			cin >> u >> v;
			d = business[v]-business[u];
			adj[u].push_back(ii(v, d*d*d));
		}
        bfs();
		BellmanFord();
        for(int i=0; i<2; i++)
		    for(u=1; u<=n; u++)
			    for(int j=0; j<adj[u].size(); j++){
				    v = adj[u][j].first; d = adj[u][j].second;
			  	    if(dist[v]>dist[u]+d)
					    dist[v]=-1e9;
			    }
		cout << "Set #" << cases++ << "\n";
		cin >> q;
		for(int i=0; i<q; i++){
			cin >> u;
			if(!reachable[u] || dist[u]<3 || dist[u]==1e9)
				cout << "?\n";
			else cout << dist[u] << "\n";
		}
	}

	return 0;
}