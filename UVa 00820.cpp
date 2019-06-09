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
#define INF 1e9

int n, s, t, c, dist[6000], cap[20000], flow[20000], maxflow;
vector<int> adj[6000];
vector<ii> edge;
map<ii, int> raw_edge;

void AddEdge(int u, int v, int c){
	edge.push_back(ii(u ,v));
	edge.push_back(ii(v, u));
	adj[u].push_back(edge.size()-2);
	adj[v].push_back(edge.size()-1);
	cap[edge.size()-2] = c;
	flow[edge.size()-2] = cap[edge.size()-1] = flow[edge.size()-1] = 0;
}

bool Dinic_BFS(){
	for(int i=0; i<6000; i++)
		dist[i] = INF;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0; i<adj[u].size(); i++){
			int e = adj[u][i], v = edge[e].second;
			if(dist[v]==INF && flow[e]<cap[e]){
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
	return (dist[t]!=INF);
}

int Dinic_DFS(int s, int t, int f){
	if(s==t) return f;
	int push = 0;
	for(int i=0; i<adj[s].size(); i++){
		int e = adj[s][i], v = edge[e].second;
		if(push>=f) break;
		if(flow[e]<cap[e] && dist[v]==dist[s]+1){
			int current_push = Dinic_DFS(v, t, min(cap[e]-flow[e], f-push));
			flow[e] += current_push;
			flow[e^1] -= current_push;
			push += current_push;
		}
	}
	return push;
}

int Dinic(){
	int f = 0;
	while(Dinic_BFS()){
		f += Dinic_DFS(s, t, INF);
	}
	return f;
}

int main(){
	int u, v, d, cases=1, newnode;

	while(cin >> n && n){
		cin >> s >> t >> c;
		for(int i=0; i<6000; i++)
			adj[i].clear();
		edge.clear();
		raw_edge.clear();
		for(int i=0; i<c; i++){
			cin >> u >> v >> d;
			ii p(min(u, v), max(u, v));
			if(raw_edge.count(p))
				raw_edge[p] += d;
			else raw_edge[p] = d;
		}
		newnode = n+1;
		for(auto& e : raw_edge){
			u = e.first.first; v = e.first.second; d = e.second;
			AddEdge(u, newnode, d);
			AddEdge(newnode, v, d);
			AddEdge(v, u, d);
			newnode++;
		}
		cout << "Network " << cases++ << "\n";
		cout << "The bandwidth is " << Dinic() << ".\n\n";
	}


	return 0;
}