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

int n, m, cost[1000][1000], dist[1000][1000];
int dx[]={-1, 0, 1,  0};
int dy[]={ 0, 1, 0, -1};

bool valid(int x, int y){
	return (x>=0 && y>=0 && x<n && y<m);
}

void Dijkstra(){
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;
	dist[0][0] = cost[0][0];
	q.push(make_pair(dist[0][0], pii(0, 0)));
	while(!q.empty()){
		int x1 = q.top().second.first, y1 = q.top().second.second;
		int d = q.top().first;
		q.pop();
		if(d>dist[x1][y1])
			continue;
		for(int i=0; i<4; i++){
			int x2 = x1+dx[i], y2 = y1+dy[i];
			if(valid(x2, y2) && dist[x1][y1]+cost[x2][y2]<dist[x2][y2]){
				dist[x2][y2] = dist[x1][y1]+cost[x2][y2];
				q.push(make_pair(dist[x2][y2], pii(x2, y2)));
			}
		}
	}
}

int main(){
	int T;

	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){
				cin >> cost[i][j];
				dist[i][j] = 1e8;
			}
		Dijkstra();
		cout << dist[n-1][m-1] << endl;
	}

	return 0;
}