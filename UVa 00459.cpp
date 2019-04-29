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

vector<int> adj[26];
bool visited[26];
int T, n;

void dfs(int u) {
	visited[u] = 1;
	for(int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if(!visited[v])
			dfs(v);
	}
}

int main() {
	string s;
	cin >> T;
	getline(cin, s);
	getline(cin, s);
	for(int i=0; i<T; i++) {
		getline(cin, s);
		n = s[0]-'A'+1;
		while(true) {
		    if(!getline(cin, s) || s.empty())
		        break;
			int u = s[0]-'A', v = s[1]-'A';
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(visited, 0, sizeof(visited));
		int count = 0;
		for(int u=0; u<n; u++)
			if(!visited[u]) {
				count++;
				dfs(u);
			}
		cout << count << endl;
		if(i<T-1)
			cout << endl;
		for(int u=0; u<n; u++)
			adj[u].clear();
	}

	return 0;
}