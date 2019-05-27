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

int n;
vector<int> adj[2500], dist, boomsize;

//BFS, mark the distance from src, count # of vertices of the same dist
void bfs(int src){
	dist.assign(n, 1e5);
	boomsize.assign(n, 0);
	dist[src] = 0;
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i];
			if(dist[v]==1e5){
				dist[v] = dist[u]+1;
				boomsize[dist[v]]++;
				q.push(v);
			}
		}
	}
}

int main(){
	int m, u, v, T;

	cin >> n;
	for(u=0; u<n; u++){
		cin >> m;
		for(int i=0; i<m; i++){
			cin >> v;
			adj[u].push_back(v);
		}
	}
	cin >> T;
	while(T--){
		cin >> u;
		bfs(u);
		int maxboom=0, day;
		for(int i=1; i<n; i++)
			if(boomsize[i]>maxboom){
				maxboom = boomsize[i];
				day = i;
			}
		if(maxboom==0)
			cout << "0\n";
		else cout << maxboom << " " << day << endl;
	}

	return 0;
}