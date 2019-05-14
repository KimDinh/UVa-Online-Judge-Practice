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

int main(){
	int T, V, E, u, v, color[201], count[2], result;
	vector<int> adj[201];
	bool isbipartite;

	cin >> T;
	while(T--){
		cin >> V >> E;
		for(int i=0; i<E; i++){
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i=0; i<V; i++)
			color[i] = -1;

		result = 0;
		for(int i=0; i<V; i++){
			if(color[i]!=-1)
				continue;
				
			isbipartite = 1;
			queue<int> q;
			color[i] = 0;
			count[0] = 1; count[1] = 0;
			q.push(i);

			//BFS to check if bipartite and color the junctions
			while(!q.empty()){
				u = q.front();
				q.pop();
				for(int j=0; j<adj[u].size(); j++){
					v = adj[u][j];
					if(color[v]==-1){
						color[v] = 1-color[u];
						count[color[v]]++;
						q.push(v);
					}
					else if(color[v]==color[u])
						isbipartite = 0;
				}
			}

			if(isbipartite){
				if(count[0]>0 && count[1]>0)
					result += min(count[0], count[1]);
				else result += max(count[0], count[1]);
			}
			else {
				result = -1;
				break;
			}
		}
		cout << result << endl;
		for(int i=0; i<V; i++)
			adj[i].clear();
	}

	return 0;
}