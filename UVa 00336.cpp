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

int NC, n, TTL;
unordered_map<int, int> vertex;
vector<int> adj[31];
vector<int> dist;

//BFS and mark the distance of every vertex from src
//Initialize dist to 1e8, nodes not connected from src have dist>TTL
void bfs(int src){
	dist.assign(n, 1e8);
	dist[src] = 0;
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i];
			if(dist[v]==1e8){
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
}

int main(){
	int u, v, cases=1;
	while(cin >> NC && NC){
		n = 0;
		for(int i=0; i<NC; i++){
			cin >> u >> v;
			auto f1 = vertex.find(u);
			if(f1!=vertex.end())
				u = f1->second;
			else { vertex.insert(make_pair(u, n)); u = n++; }
			auto f2 = vertex.find(v);
			if(f2!=vertex.end())
				v = f2->second;
			else { vertex.insert(make_pair(v, n)); v = n++; }
			if(u==v)
			    continue;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		while(cin >> u >> TTL && (u || TTL)){
		    int count = 0;
		    if(vertex.find(u)!=vertex.end()){
    			v = (vertex.find(u))->second;
			    bfs(v);
			    for(int i=0; i<n; i++)
				    if(dist[i]>TTL)
					    count++;
		    }
		    else count = n; 
			cout << "Case " << cases++ << ": " << count 
			<< " nodes not reachable from node " << u << " with TTL = " << TTL << ".\n";
		}
		for(int i=0; i<n; i++)
			adj[i].clear();
		vertex.clear();
	}

	return 0;
}