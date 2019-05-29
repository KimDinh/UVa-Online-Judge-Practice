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

int n, m, dist[105][105];
set<int> monitored[105][105];
set<pair<pii, pii>> blocked;
int dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};

bool valid(int x, int y){
	return (x>=0 && x<n && y>=0 && y<m);
}

int bfs(){
	dist[0][0] = 0;
	queue<pii> q;
	q.push(pii(0, 0));
	while(!q.empty()){
		int x1 = q.front().first, y1 = q.front().second;
		int d = dist[x1][y1];
		q.pop();
		if(x1==n-1 && y1==m-1) return d;
		bool wait=0;
		for(int i=0; i<4; i++){
			int x2 = x1+dx[i], y2 = y1+dy[i];
			if(!valid(x2, y2) || dist[x2][y2]<1e8) continue;
			if(blocked.find(make_pair(pii(x1, y1), pii(x2, y2)))!=blocked.end()) continue;
			set<int> s1=monitored[x1][y1], s2=monitored[x2][y2];
			if(s1.find(d+1)!=s1.end() && s2.find(d+1)!=s2.end()) continue;
			if(s2.find(d+1)!=s2.end()) wait = 1;
			else {
				dist[x2][y2] = d+1;
				q.push(pii(x2, y2));
			}
		}
		if(wait) {
		    q.push(pii(x1, y1));
		    dist[x1][y1] = d+1;
		}
	}
}

int main(){
	int x1, y1, x2, y2, t, r, s;

	while(cin >> n >> m){
		cin >> r;
		blocked.clear();
		for(int i=0; i<r; i++){
			cin >> x1 >> y1 >> x2 >> y2;
			blocked.insert(make_pair(pii(x1, y1), pii(x2, y2)));
		}
		for(int i=0; i<105; i++)
			for(int j=0; j<105; j++){
				monitored[i][j].clear();
				dist[i][j] = 1e8;
			}
		cin >> s;
		for(int i=0; i<s; i++){
			cin >> t >> x1 >> y1;
			monitored[x1][y1].insert(t);
		}
		cout << bfs() << endl;
	}

	return 0;
}