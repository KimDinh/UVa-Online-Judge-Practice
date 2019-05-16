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

int n, m, root[2001], low[2001], pre[2001], scc;
vector<int> adj[2001];
bool visited[2001];
stack<int> s;

//Tarjan's algorithm to find strongly connected components
void TarjanDFS(int u, int &clock){
	visited[u] = 1;
	pre[u] = low[u] = ++clock;
	s.push(u);
	for(int i=0; i<adj[u].size(); i++){
		int v=adj[u][i];
		if(!visited[v]){
			TarjanDFS(v, clock);
			low[u] = min(low[u], low[v]);
		}
		else if(root[v]==-1)
			low[u] = min(low[u], pre[v]);
	}

	if(low[u]==pre[u]){
		scc++;
		int v = s.top();
		s.pop();
		root[v] = u;
		while(v!=u){
			v = s.top();
			s.pop();
			root[v] = u;
		}
	}
}

void FindSCC(){
	for(int i=1; i<=n; i++){
		root[i] = -1;
		visited[i] = 0;
	}
	int clock = 0;

	for(int i=1; i<=n; i++)
		if(!visited[i])
			TarjanDFS(i, clock);
}

int main(){
	int u, v, p;
	while(cin >> n >> m && n && m){
		for(int i=0; i<m; i++){
			cin >> u >> v >> p;
			adj[u].push_back(v);
			if(p==2)
				adj[v].push_back(u);
		}
		scc = 0;
		FindSCC();
		if(scc==1)
			cout << "1\n";
		else cout << "0\n";

		for(int i=1; i<=n; i++)
			adj[i].clear();
	}

	return 0;
}