#include <iostream>
#include <fstream>
#include <sstream>
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

int F, I, dist[501];
unordered_set<int> station;
vector<ii> adj[501];

void Dijkstra(int u){
	for(int i=1; i<=I; i++)
		dist[i] = 1e8;
	priority_queue<ii, vector<ii>, greater<ii>> q;
	if(u){
		dist[u] = 0;
		q.push(ii(0, u));
	}
	for(auto i=station.begin(); i!=station.end(); i++){
		dist[*i] = 0;
		q.push(ii(0, *i));
	}
	while(!q.empty()){
		int d = q.top().first; u = q.top().second;
		q.pop();
		if(d>dist[u]) continue;
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i].first; d = adj[u][i].second;
			if(dist[v]>dist[u]+d){
				dist[v] = dist[u]+d;
				q.push(ii(dist[v], v));
			}
		}
	}
}

int main(){
	int T, u, v, d, minstation, minimax;
	string s;

	cin >> T;
	for(int c=1; c<=T; c++){
		cin >> F >> I;
		minstation = 1e8;
    	station.clear();
    	for(int i=1; i<=I; i++)
      		adj[i].clear();
		for(int i=0; i<F; i++){
			cin >> u;
			station.insert(u);
			minstation = min(minstation, u);
		}
		getline(cin, s);
		while(true){
			if(!getline(cin, s) || s.empty()) break;
			stringstream ss(s);
			ss >> u >> v >> d;
			adj[u].push_back(ii(v, d));
			adj[v].push_back(ii(u, d));
		}

		Dijkstra(0);
    	minimax = 0;
    	for(int i=1; i<=I; i++)
      		minimax = max(minimax, dist[i]);
		for(int i=1; i<=I; i++)
			if(!station.count(i)){
				Dijkstra(i);
        		int m = 0;
        		for(int j=1; j<=I; j++)
          			m = max(m, dist[j]);
				if(minimax>m || (minimax==m && minstation>i)){
					minimax = m;
					minstation = i;
				}
			}
		cout << minstation << "\n";
		if(c<T) cout << "\n";
	}

	return 0;
}