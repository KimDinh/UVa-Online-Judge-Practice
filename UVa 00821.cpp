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
	int n, u, v, adj[101][101], count, sum, cases=1;
	unordered_map<int, int> vertex;

	while(cin >> u >> v && u && v){
		int n = 0;
		vertex.clear();
		for(int i=0; i<101; i++)
			for(int j=0; j<101; j++)
				adj[i][j] = 1e9;
		vertex[u] = n++;
		vertex[v] = n++;
		adj[0][1] = 1;
		while(cin >> u >> v && u && v){
			if(!vertex.count(u))
				vertex[u] = n++;
			u = vertex[u];
			if(!vertex.count(v))
				vertex[v] = n++;
			v = vertex[v];
			adj[u][v] = 1;
		}
		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
		count = 0; sum = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(j!=i){
					count++;
					sum += adj[i][j];
				}
		cout << "Case " << cases++ << ": average length between pages = ";
		cout << fixed << setprecision(3) << sum*1.0/count << " clicks\n";
	}

	return 0;
}