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

long long adj_time[201][201], adj_dist[201][201];
int n, m;

int main(){
	long long t, d;
    int u, v, q, T;

	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++){
				if(i==j)
					adj_time[i][j] = adj_dist[i][j] = 0;
				else adj_time[i][j] = adj_dist[i][j] = 1e9;
			}
		for(int i=0; i<m; i++){
			cin >> u >> v >> t >> d;
			if(adj_time[u][v]<t)
                continue;
            if(adj_time[u][v]>t){
                adj_time[u][v] = adj_time[v][u] = t;
                adj_dist[u][v] = adj_dist[v][u] = d;
                continue;
            }
            if(adj_dist[u][v]>d)
                adj_dist[u][v] = adj_dist[v][u] = d;
		}
		//FloydWarshall's algorithm
		for(int k=1; k<=n; k++)
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++){
                    if(adj_time[i][j]<adj_time[i][k]+adj_time[k][j])
                        continue;
					if(adj_time[i][j]>adj_time[i][k]+adj_time[k][j]){
						adj_time[i][j] = adj_time[i][k]+adj_time[k][j];
						adj_dist[i][j] = adj_dist[i][k]+adj_dist[k][j];
                        continue;
					}
                    adj_dist[i][j] = min(adj_dist[i][j], adj_dist[i][k]+adj_dist[k][j]);
                }
		cin >> q;
		for(int i=0; i<q; i++){
			cin >> u >> v;
			if(u<1 || u>n || v<1 || v>n || adj_time[u][v]==1e9)
				cout << "No Path.\n";
			else cout << "Distance and time to reach destination is "
					<< adj_dist[u][v] << " & " << adj_time[u][v] << ".\n";
		}
		if(T) cout << endl;
	}

	return 0;
}