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

int R, C, m, n, dist[201][201];
int dx[]={-1, 0, 1,  0, -1, -1, 1,  1};
int dy[]={ 0, 1, 0, -1, -1,  1, 1, -1};

bool valid(int x, int y){
	return (x>0 && y>0 && x<=R && y<=C);
}

void dangerous(int x, int y, int L){
	dist[x][y] = -1;
	for(int a=x-L; a<=x+L; a++)
		for(int b=y-L; b<=y+L; b++)
			if(valid(a, b) && ((a-x)*(a-x)+(b-y)*(b-y)<=L*L))
				dist[a][b] = -1;
}

void bfs(){
	if(dist[1][1]==-1) 
		return;
	queue<pii> q;
	dist[1][1] = 0;
	q.push(pii(1, 1));
	while(!q.empty()){
		int x1 = q.front().first, y1 = q.front().second;
		q.pop();
		if(x1==R && y1==C) 
			return;
		for(int i=0; i<4; i++){
			int x2 = x1+dx[i], y2 = y1+dy[i];
			if(valid(x2, y2) && dist[x2][y2]==1e8){
				dist[x2][y2] = dist[x1][y1]+1;
				q.push(pii(x2, y2));
			}
		}
	}
}

int main(){
	int x, y, L;

	while(cin >> R >> C && R){
		for(int i=1; i<=R; i++)
			for(int j=1; j<=C; j++)
				dist[i][j] = 1e8;
		cin >> m;
		for(int i=0; i<m; i++){
			cin >> x >> y;
			dist[x][y] = -1;
		}
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> x >> y >> L;
			dangerous(x, y, L);
		}
		bfs();
		if(dist[R][C]==-1 || dist[R][C]==1e8)
			cout << "Impossible.\n";
		else cout << dist[R][C] << endl;
	}

	return 0;
}