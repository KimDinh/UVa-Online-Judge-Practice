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

#define pii pair<int, int>

int N, E, T, M, dist[101];
vector<pii> adj[101];

void Dijkstra(){
	dist[E] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push(pii(0, E));
	while(!q.empty()){
		int d = q.top().first, u = q.top().second;
		q.pop();
		if(d>dist[u])
			continue;
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i].first;
			if(dist[v]>dist[u]+adj[u][i].second){
				dist[v] = dist[u]+adj[u][i].second;
				q.push(pii(dist[v], v));
			}
		}
	}
}

int main(){
	int C, u, v, c, count;

	cin >> C;
	while(C--){
		cin >> N >> E >> T >> M;
		for(int i=0; i<101; i++){
			adj[i].clear();
			dist[i] = 1e8;
		}
		for(int i=0; i<M; i++){
			cin >> u >> v >> c;
			adj[v].push_back(pii(u, c));
		}
		Dijkstra();
		count = 0;
		for(int i=1; i<=N; i++)
			if(dist[i]<=T)
				count++;
		cout << count << endl;
		if(C) cout << endl;
	}


	return 0;
}