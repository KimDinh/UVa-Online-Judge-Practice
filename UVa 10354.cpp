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

int P, R, bh, of, yh, m, dist[101][101], adj[101][101], p[101][101];
unordered_set<int> avoid;

void FloydWarshall(){
    for(int i=1; i<=P; i++)
			for(int j=1; j<=P; j++){
			    dist[i][j] = adj[i][j];
				p[i][j] = i;
			}
	for(int k=1; k<=P; k++)
		for(int i=1; i<=P; i++)
			for(int j=1; j<=P; j++){
				if(avoid.count(k) || avoid.count(i) || avoid.count(j))
					continue;
				if(dist[i][j]>dist[i][k]+dist[j][k]){
					dist[i][j] = dist[i][k]+dist[k][j];
					p[i][j] = p[k][j];
				}
			}
}

int main(){
	int u, v, d;

	while(cin >> P >> R >> bh >> of >> yh >> m){
		avoid.clear();
        for(int i=1; i<=P; i++)
            for(int j=1; j<=P; j++){
                if(i==j)
                    adj[i][j] = 0;
                else adj[i][j] = 1e9;
            }
		for(int i=0; i<R; i++){
			cin >> u >> v >> d;
			adj[u][v] = adj[v][u] = d;
		}
		FloydWarshall();
        for(int i=1; i<=P; i++)
            if(dist[bh][of]==dist[bh][i]+dist[i][of])
                avoid.insert(i);
		FloydWarshall();
		if(avoid.count(yh) || avoid.count(m) || dist[yh][m]==1e9)
			cout << "MISSION IMPOSSIBLE.\n";
		else cout << dist[yh][m] << "\n";
	}

	return 0;
}