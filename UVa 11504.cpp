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

int n, m, root[100001], low[100001], pre[100001], scc;
vector<int> adj[100001];
bool visited[100001];
stack<int> s;
unordered_map<int, int> component;
vector<vector<int>> reduced;

//Tarjan algorithm to find SCCs
void TarjanDFS(int u, int &clock){
	visited[u] = 1;
	low[u] = pre[u] = ++clock;
	s.push(u);
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(!visited[v]){
			TarjanDFS(v, clock);
			low[u] = min(low[u], low[v]);
		}
		else if(root[v]==-1)
			low[u] = min(low[u], pre[v]);
	}
	if(low[u]==pre[u]){
		int v = s.top();
		s.pop();
		root[v] = u;
		component[v] = scc;
		while(v!=u){
			v = s.top();
			s.pop();
			root[v] = u;
			component[v] = scc;
		}
		scc++;
	}
}

//find all strongly connected components
void FindSCC(){
	memset(visited, 0, sizeof(visited));
	for(int i=1; i<=n; i++){
		low[i] = pre[i] = 0;
		root[i] = -1;
	}
	int clock = 0;
	for(int i=1; i<=n; i++)
		if(!visited[i])
			TarjanDFS(i, clock);
}

int main(){
	int T, u, v;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i=0; i<m; i++){
			cin >> u >> v;
			adj[u].push_back(v);
		}
		scc = 0;
		FindSCC();
		
		//build the strong component graph
		reduced.resize(scc);
		vector<int> indegree_reduced(scc, 0);
		for(int u=1; u<=n; u++)
			for(int i=0; i<adj[u].size(); i++)
				if(component[u]!=component[adj[u][i]]) {
					reduced[component[u]].push_back(component[adj[u][i]]);
					//mark that indegree is greater than 0
					indegree_reduced[component[adj[u][i]]] = 1;
				}

		//count the number of source vertex in the strong component graph
		int count=0;
		for(int i=0; i<scc; i++)
			if(indegree_reduced[i]==0)
				count++;		
		cout << count << endl;

		for(int i=1; i<=n; i++)
			adj[i].clear();
		component.clear();
		reduced.clear();
		indegree_reduced.clear();
	}

	return 0;
}