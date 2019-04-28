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
#include <unordered_map>
#include <stack>
#include <iomanip>
using namespace std;

vector<int> adj[101];
bool visited[101], dominate[101][101];
int n, T;

void dfs(int u) {
	visited[u] = 1;
	for(int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if(!visited[v])
			dfs(v);
	}
}

//dfs with the node x omitted
void dfs_node_off(int u, int x) {
	if(u==x)
		return;
	visited[u] = 1;
	for(int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if(!visited[v])
			dfs_node_off(v, x);
	}
}

void seperateline() {
	cout << "+";
	for(int i=1; i<=2*n-1; i++)
		cout << "-";
	cout << "+\n";
}

int main() {
	cin >> T;
	for(int i=1; i<=T; i++) {
		cout << "Case " << i << ":\n";
		cin >> n;
		int d;
		for(int u=0; u<n; u++)
			for(int v=0; v<n; v++) {
				cin >> d;
				if(d==1)
					adj[u].push_back(v);
			}
		memset(visited, 0, sizeof(visited));
		memset(dominate, 0, sizeof(dominate));
		dfs(0);
		//reachable nodes from start node dominate itself
		for(int j=0; j<n; j++)
			if(visited[j])
				dominate[j][j] = 1;

		//run dfs with a node omitted each time
		for(int j=0; j<n; j++) {
			memset(visited, 0, sizeof(visited));
			dfs_node_off(0, j);
			//initially reachable but unreachable after omitting node j
			for(int u=0; u<n; u++)
				if(dominate[u][u] && !visited[u])
					dominate[j][u] = 1;
		}

		for(int u=0; u<n; u++) {
			seperateline();
			for(int v=0; v<n; v++) {
				if(dominate[u][v])
					cout << "|Y";
				else cout << "|N";
			}
			cout << "|\n";
		}
		seperateline();
		for(int j=0; j<n; j++)
			adj[j].clear();
	}
	return 0;
}
