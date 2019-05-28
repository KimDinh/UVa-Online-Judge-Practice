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

int R, C, dr[]={-1, 0, 1, 0}, dc[]={0, 1, 0, -1};
vector<int> dist[1000];


//BFS and mark the distance of grid cells from the start cell
void bfs(pair<int, int> start, pair<int, int> end){
	dist[start.first][start.second] = 0;
	queue<pair<int, int>> q;
	q.push(start);
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int r = p.first+dr[i], c = p.second+dc[i];
			if(r>=0 && r<R && c>=0 && c<C && dist[r][c]==1e9){
				dist[r][c] = dist[p.first][p.second]+1;
				q.push(make_pair(r, c));
				if(r==end.first && c==end.second)
					return;
			}
		}
	}
}

int main(){
	int r, c, bombrow, b;

	while(cin >> R >> C && R){
		for(int i=0; i<R; i++)
			dist[i].assign(C, 1e9);
		cin >> bombrow;
		for(int i=0; i<bombrow; i++){
			cin >> r >> b;
			for(int j=0; j<b; j++){
				cin >> c;
				dist[r][c] = -1;
			}
		}
		int r1, c1;
		cin >> r >> c >> r1 >> c1;
		bfs(pair<int, int>(r, c), pair<int, int>(r1, c1));
		cout << dist[r1][c1] << endl;
	}

	return 0;
}