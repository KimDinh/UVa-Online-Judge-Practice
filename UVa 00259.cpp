#include <iostream>
#include <sstream>
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

vector<ii> edge;
vector<int> adj[38];
int cap[1500], flow[1500], maxflow, dist[38], total;

void AddEdge(int u, int v, int e, int c){
	edge.push_back(ii(u, v));
	edge.push_back(ii(v, u));
	adj[u].push_back(e);
	adj[v].push_back(e+1);
	cap[e] = c;
	cap[e+1] = flow[e] = flow[e+1] = 0;
}

bool Dinic_BFS(){
	for(int i=0; i<38; i++)
		dist[i] = INF;
	queue<int> q;
	q.push(0);
	dist[0] = 0;
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
	return (dist[37]!=INF);
}

int Dinic_DFS(int s, int t, int f){
	if(s==t) return f;
	int push = 0;
	for(int i=0; i<adj[s].size(); i++){
		if(push>=f) break;
		int e = adj[s][i], v = edge[e].second;
		if(flow[e]<cap[e] && dist[v]==dist[s]+1){
			int current_push = Dinic_DFS(v, t, min(f-push, cap[e]-flow[e]));
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
		f += Dinic_DFS(0, 37, INF);
	}
	return f;
}

int main(){
	char app;
	int users, u, v, e;
	string s1, s2;

	while(cin.peek()!=EOF){
		total = 0;
		edge.clear();
		for(int i=0; i<38; i++)
			adj[i].clear();
		while(cin.peek()!='\n' && cin.peek()!=EOF){
            cin >> s1 >> s2;
            cin.get();
            app = s1[0]; users = s1[1]-'0';
			total += users;
			u = 0; v = app-'A'+1; e = edge.size();
			AddEdge(u, v, e, users);
			for(int i=0; i<s2.length()-1; i++){
				u = app-'A'+1; v = s2[i]-'0'+27; e = edge.size();
				AddEdge(u, v, e, 1);
			}
		}
        if(cin.peek()!=EOF)
            cin.get();
		for(int i=27; i<=36; i++)
			AddEdge(i, 37, edge.size(), 1);
		maxflow = Dinic();
		if(maxflow!=total){
			cout << "!\n";
			continue;
		}
		for(int u=27; u<=36; u++){
			bool match = 0;
			for(int i=0; i<adj[u].size(); i++){
				e = adj[u][i]; v = edge[e].second;
				if(flow[(e^1)]){
					cout << char(v+'A'-1);
					match = 1;
					break;
				}
			}
			if(!match) cout << "_";
		}
		cout << "\n";
	}

	return 0;
}