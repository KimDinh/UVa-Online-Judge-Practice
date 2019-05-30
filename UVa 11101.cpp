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

#define pii pair<int, int>

set<pii> s, t;
int dist[2001][2001];
int dx[]={-1, 0, 1,  0};
int dy[]={ 0, 1, 0, -1};

bool valid(int x, int y){
	return (x>=0 && y>=0 && x<=2000 && y<=2000);
}

int bfs(){
	for(int i=0; i<2001; i++)
		for(int j=0; j<2001; j++)
			dist[i][j] = 1e8;
	queue<pii> q;
	for(auto i=s.begin(); i!=s.end(); i++){
		q.push(*i);
		dist[i->first][i->second] = 0;
	}
	while(!q.empty()){
		pii p = q.front();
		q.pop();
		if(t.find(p)!=t.end())
			return dist[p.first][p.second];
		for(int i=0; i<4; i++)
			if(valid(p.first+dx[i], p.second+dy[i]) 
				&& dist[p.first+dx[i]][p.second+dy[i]]==1e8){
				dist[p.first+dx[i]][p.second+dy[i]] = dist[p.first][p.second]+1;
				q.push(pii(p.first+dx[i], p.second+dy[i]));
			}
	}
}

int main(){
	int p, x, y;

	while(cin >> p && p){
		s.clear();
		t.clear();
		for(int i=0; i<p; i++){
			cin >> x >> y;
			s.insert(pii(x, y));
		}
		cin >> p;
		for(int i=0; i<p; i++){
			cin >> x >> y;
			t.insert(pii(x, y));
		}
		cout << bfs() << endl;
	}

	return 0;
}