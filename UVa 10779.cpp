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

int n, m, nodes, source, sink; 
int dist[100], flow[2000], cap[2000], count_type[26];
vector<ii> edge;
vector<int> adj[100], input[11];

void AddEdge(int u, int v, int c){
	edge.push_back(ii(u, v));
	edge.push_back(ii(v, u));
	adj[u].push_back(edge.size()-2);
	adj[v].push_back(edge.size()-1);
	cap[edge.size()-2] = c;
	flow[edge.size()-2] = cap[edge.size()-1] = flow[edge.size()-1] = 0;
}

void Make_Graph(){
	edge.clear();
	for(int i=0; i<100; i++)
		adj[i].clear();
	for(int i=1; i<=m; i++)
		count_type[i] = 0;
	//count the number of stickers of each type Bob has
	for(int i=0; i<input[0].size(); i++)
		count_type[input[0][i]]++;
	//number of nodes of graph
	nodes = 1+  //source
			1+  //sink
			m+  //1 source node for Bob for each sticker type
			m+  //1 trade node for Bob for each sticker type
			m+  //1 sink node for Bob for each sticker type 
			n-1;//1 node for each of other people
	source = 0; sink = 3*m+1;
	for(int i=1; i<=m; i++){
		//edge from source to the sticker type for Bob 
		AddEdge(source, i, count_type[i]);
		//edge from source to trade node of the sticker type for Bob
		AddEdge(i, i+m, count_type[i]);
		//edge from trade node to sink node of the sticker type for Bob
		AddEdge(i+m, i+2*m, 1);
		//edge from sink node of the sticker type to sink node
		AddEdge(i+2*m, sink, 1);
	}
	//for each of the other people
	for(int i=1; i<n; i++){
		int p = sink+i;
		for(int j=1; j<=m; j++)
			count_type[j] = 0;
		//count the number of stickers of each type
		for(int j=0; j<input[i].size(); j++)
			count_type[input[i][j]]++;
		vector<int> give, take;
		//give stickers of the type that person has > 1, take a sticker
		//the type that person does not have
		for(int j=1; j<=m; j++){
			if(count_type[j]>1)
				give.push_back(j);
			else if(count_type[j]==0)
                take.push_back(j);
		}
		//edge to a trade node of the type that person wants to take
		for(int j=0; j<take.size(); j++)
			AddEdge(take[j]+m, p, 1);
		//edge to a trade node of the type that person can give away
		for(int j=0; j<give.size(); j++)
			AddEdge(p, give[j]+m, count_type[give[j]]-1);
	}
}

bool Dinic_BFS(){
	for(int i=0; i<nodes; i++)
		dist[i] = INF;
	dist[source] = 0;
	queue<int> q;
	q.push(source);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0; i<adj[u].size(); i++){
			int e = adj[u][i], v = edge[e].second;
			if(dist[v]==INF && flow[e]<cap[e]){
				q.push(v);
				dist[v] = dist[u]+1;
			}
		}
	}
	return (dist[sink]!=INF);
}

int Dinic_DFS(int s, int t, int f){
	if(s==t) return f;
	int push = 0;
	for(int i=0; i<adj[s].size(); i++){
		if(push>=f) break;
		int e = adj[s][i], v = edge[e].second;
		if(flow[e]<cap[e] && dist[v]==dist[s]+1){
			int current_push = Dinic_DFS(v, t, min(f-push, cap[e]-flow[e]));
			push += current_push;
			flow[e] += current_push;
			flow[e^1] -= current_push;
		}
	}
	return push;
}

int Dinic(){
	int f=0;
	while(Dinic_BFS()){
		f += Dinic_DFS(source, sink, INF);
	}
	return f;
}

int main(){
	int T, k, x;

	cin >> T;
	for(int c=1; c<=T; c++){
		cin >> n >> m;
		for(int i=0; i<n; i++){
			cin >> k;
			input[i].resize(k);
			for(int j=0; j<k; j++)
				cin >> input[i][j];
		}
		Make_Graph();
		cout << "Case #" << c << ": " << Dinic() << "\n";
 	}

	return 0;
}