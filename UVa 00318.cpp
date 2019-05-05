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

const int M = 1e8;
//const double e = 1e-9;
#define pii pair<int, int>

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, dist[501], vertex1, vertex2, cases;
	double maxd;
	vector<pii> adj[501];
	priority_queue<pii, vector<pii>, greater<pii>> q;

	cin >> n >> m;
	cases = 1;
	while(n!=0) {
		int u, v, l;
		for(int i=0; i<m; i++) {
			cin >> u >> v >> l;
			adj[u].push_back(make_pair(v, l));
			adj[v].push_back(make_pair(u, l)); 
		}

		for(int i=1; i<=n; i++)
			dist[i] = M;
		dist[1] = 0;
		q.push(make_pair(0, 1));
		
		//Dijkstra to find fall time of key dominoes
		while(!q.empty()) {
			int u = q.top().second, d = q.top().first;
			q.pop();
			if(d>dist[u]) continue;

			for(int i=0; i<adj[u].size(); i++) {
				int v = adj[u][i].first;
				d = adj[u][i].second;
				if(dist[u]+d<dist[v]) {
					dist[v] = dist[u]+d;
					q.push(make_pair(dist[v], v));
				}
			}
		}
		//Find the largest fall time
		maxd = 0; vertex1 = 1; vertex2 = -1;
		for(int u=1; u<=n; u++)
			//Last domino falling is a key domino
			if(dist[u]>maxd && dist[u]<M) {
				maxd = dist[u];
				vertex1 = u;
			}
		for(int u=1; u<=n; u++)
			for(int j=0; j<adj[u].size(); j++) {
				int v = adj[u][j].first, d = adj[u][j].second;
				double t = (dist[u]+dist[v]+d)/2.0;
				if(dist[u]<M && dist[v]<M && t>maxd) {
					maxd = t; vertex1 = min(u, v); vertex2 = max(u, v);
				}
			}
		
		cout << "System #" << cases << endl;
		if(vertex2==-1)
			cout << "The last domino falls after " << fixed << setprecision(1) 
			<< maxd << " seconds, at key domino " << vertex1 << ".\n\n";
		else cout << "The last domino falls after " << fixed << setprecision(1)
			<< maxd << " seconds, between key dominoes " 
			<< min(vertex1, vertex2) << " and " << max(vertex1, vertex2) << ".\n\n";
		cases++;
		for(int i=1; i<=n; i++)
			adj[i].clear();
		cin >> n >> m;
	}

	return 0;
}