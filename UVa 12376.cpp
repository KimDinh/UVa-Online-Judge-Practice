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


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, T, value[101], u, v, unit;
	vector<int> adj[101];

	cin >> T;
	for(int c=1; c<=T; c++) {
		cin >> n >> m;
		for(int i=0; i<n; i++)
			cin >> value[i];
		for(int i=0; i<m; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
		}
		u = 0; unit = 0;
		while(true) {
			if(adj[u].size()==0)
				break;
			int maxunit = 0;
			for(int i=0; i<adj[u].size(); i++)
				if(value[adj[u][i]]>maxunit) {
					maxunit = value[adj[u][i]];
					v = adj[u][i];
				}
			u = v; unit += maxunit;
		}
		cout << "Case " << c << ": " << unit << " " << u << endl;
		for(int i=0; i<n; i++)
			adj[i].clear();
	}

	return 0;
}