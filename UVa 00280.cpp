#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <stack>
#include <iomanip>
using namespace std;

int n;
vector<int> adj[101];
bool visited[101];

void dfs(int u) {
	visited[u] = 1;
	for(int i=0; i<adj[u].size(); i++) {
		int v=adj[u][i];
		if(!visited[v])
			dfs(v);
	}
}

int main() {
	cin >> n;
	while(n!=0) {
		int u, v;
		cin >> u;
		while(u!=0) {
			cin >> v;
			while(v!=0) {
				adj[u].push_back(v);
				cin >> v;
			}
			cin >> u;
		}
		int k;
		cin >> k;
		for(int i=0; i<k; i++) {
			cin >> u;
			memset(visited, 0, sizeof(visited));
			for(int j=0; j<adj[u].size(); j++)
				dfs(adj[u][j]);
			int count = 0;
			for(int v=1; v<=n; v++)
				if(!visited[v])
					count++;
			cout << count;
			for(int v=1; v<=n; v++)
				if(!visited[v])
					cout << " " << v;
			cout << endl;
		}
		for(int i=1; i<=n; i++)
			adj[i].clear();
		cin >> n;
	}


	return 0;
}