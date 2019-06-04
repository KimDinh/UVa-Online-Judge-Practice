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

#define ii pair<int, int>

int M, dist[5002];
map<string, vector<string>> language;
map<string, int> word;
vector<ii> adj[5002];

void Dijkstra(){
	for(int i=0; i<=M+1; i++)
		dist[i] = 1e8;
	dist[0] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> q;
	q.push(ii(0, 0));
	while(!q.empty()){
		int u = q.top().second, d = q.top().first;
		q.pop();
		if(d>dist[u])
			continue;
		if(u==M+1)
			return;
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i].first; d = adj[u][i].second;
			if(dist[v]>dist[u]+d){
				dist[v] = dist[u]+d;
				q.push(ii(dist[v], v));
			}
		}
	}
}

int main(){
	string I1, I2, P, s, O, D;
	int u, v;

	while(cin >> M && M){
        cin.ignore();
		getline(cin, O, ' ');
        getline(cin, D);
		language.clear();
		word.clear();
		for(int i=0; i<=M+1; i++)
			adj[i].clear();
		for(int i=1; i<=M; i++){
			getline(cin, I1, ' ');
            getline(cin, I2, ' ');
            getline(cin, P);
			word[P] = i;
			if(language.count(I1)){
				for(int j=0; j<language[I1].size(); j++){
					s = language[I1][j];
					if(P[0]==s[0]) continue;
					adj[word[P]].push_back(ii(word[s], s.length()));
					adj[word[s]].push_back(ii(word[P], P.length()));
				}
				language[I1].push_back(P);
			}
			else language[I1] = vector<string>(1, P);
            if(language.count(I2)){
				for(int j=0; j<language[I2].size(); j++){
					s = language[I2][j];
					if(P[0]==s[0]) continue;
					adj[word[P]].push_back(ii(word[s], s.length()));
					adj[word[s]].push_back(ii(word[P], P.length()));
				}
				language[I2].push_back(P);
			}
			else language[I2] = vector<string>(1, P);
		}
		if(!language.count(O) || !language.count(D)){
			cout << "impossivel\n";
			continue;
		}
		for(int i=0; i<language[O].size(); i++){
			s = language[O][i];
			adj[0].push_back(ii(word[s], s.length()));
		}
		for(int i=0; i<language[D].size(); i++){
			s = language[D][i];
			adj[word[s]].push_back(ii(M+1, 0));
		}
		Dijkstra();
		if(dist[M+1]==1e8)
			cout << "impossivel\n";
		else cout << dist[M+1] << endl;
	}
	

	return 0;
}