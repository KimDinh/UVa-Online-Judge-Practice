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

int n, m, adj[26][26], inter[26][26], p[26][26];
unordered_map<char, int> chartoint;
unordered_map<int, char> inttochar;

void FloydWarshall(){
	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				int d = adj[i][k]+adj[k][j];
				if(adj[i][j]<d) continue;
				if(adj[i][j]>d || inter[i][j]>inter[i][k]+inter[k][j]+1){
					adj[i][j] = d;
					p[i][j] = p[k][j];
					inter[i][j] = inter[i][k]+inter[k][j]+1;
				}
			}
}

void Path(int s, int t){
	if(s==t){
		cout << inttochar[s];
		return;
	}
	Path(s, p[s][t]);
	cout << " " << inttochar[t];
}

int main(){
	int count, u, v, d, q;
	char c1, c2;

	cin >> n >> m;
	cin.ignore();
	count = 0;
	for(int i=0; i<26; i++)
		for(int j=0; j<26; j++){
			adj[i][j] = 1e9;
			inter[i][j] = 0;
			p[i][j] = i;
		}
	for(int i=0; i<m; i++){
		cin.get(c1); cin.ignore(); cin.get(c2); cin >> d; cin.ignore();
		if(!chartoint.count(c1)){
			chartoint[c1] = count++;
			inttochar[chartoint[c1]] = c1;
		}
		u = chartoint[c1];
		if(!chartoint.count(c2)){
			chartoint[c2] = count++;
			inttochar[chartoint[c2]] = c2;
		}
		v = chartoint[c2];
		adj[u][v] = d;
		adj[v][u] = d;
	}
	FloydWarshall();
	cin >> q;
	cin.ignore();
	for(int i=0; i<q; i++){
		cin.get(c1); cin.ignore(); cin.get(c2); cin.ignore();
		u = chartoint[c1]; v = chartoint[c2];
		Path(u ,v);
		cout << "\n";
	}

	return 0;
}