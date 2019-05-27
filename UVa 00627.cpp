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

int n, parent[301];
vector<int> adj[301], dist;

//BFS and mark the distance from start to end
void bfs(int start, int end){
	dist.assign(n+1, 1000);
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i];
			if(dist[v]==1000){
				dist[v] = dist[u]+1;
				q.push(v);
				parent[v] = u;
				if(v==end)
					return;
			}
		}
	}
}

//print the path from start to end
void path(int start, int end){
	if(start==end){
		cout << start;
		return;
	}
	path(start, parent[end]);
	cout << " " << end;
}

int main(){
	int u, v, Q;
	string s, num;

	while(cin >> n){
		for(int i=0; i<n; i++){
			cin >> u;
			cin.ignore();
			getline(cin, s);
			int j=0;
			num="";
			while(j<s.length()){
				if(s[j]!=',')
					num += s[j];
				else { 
					adj[u].push_back(stoi(num));
					num = ""; 
				}
				j++;
			}
			if(num!="")
			    adj[u].push_back(stoi(num));
		}
		cout << "-----\n";
		cin >> Q;
		for(int i=0; i<Q; i++){
			cin >> u >> v;
			bfs(u, v);
			if(dist[v]==1000)
				cout << "connection impossible";
			else path(u, v);
			cout << endl;
		}
		for(int i=0; i<301; i++)
			adj[i].clear();
	}

	return 0;
}