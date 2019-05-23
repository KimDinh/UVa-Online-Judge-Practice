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

int n, e, q, cost[101][101], path[101];
vector<pair<int, pii>> edge;
vector<int> mst[101], parent, size, rankset;

bool cmp(pair<int, pii> e1, pair<int, pii> e2){
	return (e1.first<e2.first);
}

int FindSet(int i){
	if(parent[i]==i) return i;
	return (parent[i] = FindSet(parent[i]));
}

void UnionSet(int i, int j){
	int u = FindSet(i), v = FindSet(j);
	if(u==v) return;
	if(rankset[u]>rankset[v]){
		parent[v] = u; size[u] += size[v];
	}
	else {
		parent[u] = v; size[v] += size[u];
		if(rankset[u]==rankset[v]) rankset[v]++;
	}
}

void KruskalMST(){
	parent.assign(n+1, 0); size.assign(n+1, 1); rankset.assign(n+1, 0);
	for(int i=1; i<=n; i++){
		parent[i] = i;
		mst[i].clear();
	}
	sort(edge.begin(), edge.end(), cmp);
	for(int i=0; i<e; i++){
		int u = edge[i].second.first, v = edge[i].second.second;
		if(FindSet(u)!=FindSet(v)){
			UnionSet(u, v);
			mst[u].push_back(v);
			mst[v].push_back(u);
		}
	}
}

void path_bfs(int start, int end){
	bool visited[101];
	queue<int> Q;
	memset(visited, 0, sizeof(visited));
	Q.push(start);
	visited[start] = 1;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		for(int i=0; i<mst[u].size(); i++){
			int v = mst[u][i];
			if(!visited[v]){
				visited[v] = 1;
				Q.push(v);
				path[v] = u;
				if(v==end)
					return;
			}
		}
	}
}

int main(){
	int u, v, c, cases=1;
	cin >> n >> e >> q;
	while(n){
		cout << "Case #" << cases++ << endl;
		for(int i=0; i<e; i++){
			cin >> u >> v >> c;
			edge.push_back(make_pair(c, make_pair(u, v)));
			cost[u][v] = c;
			cost[v][u] = c;
		}
		KruskalMST();
		while(q--){
			cin >> u >> v;
			if(FindSet(u)!=FindSet(v)){
				cout << "no path\n";
				continue;
			}
			path_bfs(u, v);
			int ans=-1;
			while(v!=u){
				ans = max(ans, cost[v][path[v]]);
				v = path[v];
			}
			cout << ans << endl;
		}
		edge.clear();
		cin >> n >> e >> q;
		if(n)
			cout << endl;
	}

	return 0;
}