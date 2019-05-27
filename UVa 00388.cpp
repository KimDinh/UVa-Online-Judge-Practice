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
vector<int> adj[27], dist;
double value[27];

//BFS and mark the distance from Earth to other planets
void bfs(){
	dist.assign(27, 100);
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i];
			if(dist[v]==100){
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
}

//calculate the final value of product shipped to Earth
double get_value(double x, int d){
	for(int i=0; i<d-1; i++)
		x *= 0.95;
	return x;
}

int main(){
	string s;
	int u, v, ind;
	double import;

	while(cin >> n){
		cin.ignore();
		for(int i=0; i<n; i++){
			getline(cin, s, ' ');
			u = s[0]-'A'+1;
			cin >> value[u];
			cin.ignore();
			getline(cin, s);
			for(int j=0; j<s.length(); j++){
				if(s[j]=='*')
					adj[0].push_back(u);
				else {
					v = s[j]-'A'+1;
					adj[v].push_back(u);
					adj[u].push_back(v);
				}
			}
		}
		bfs();
		import = 0;
		for(int i=1; i<27; i++){
			double x = get_value(value[i], dist[i]);
			if(dist[i]<100 && import<x){
				import = x;
				ind = i;
			}
		}
		cout << "Import from " << char('A'+ind-1) << endl;
		for(int i=0; i<27; i++)
			adj[i].clear();
	}

	return 0;
}